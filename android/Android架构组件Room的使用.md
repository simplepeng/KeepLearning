# Android架构组件Room的使用

Room其实就是一个orm，抽象了SQLite的使用，但是它作为Android的亲儿子orm，并且原生支持LiveData和Rxjava嵌套使用，学习一下还是不错的。



Room有3个主要组件

* Database ：数据库
* Entity : 代表数据库一个表结构
* Dao : 包含访问数据库的方法




## 简单使用

### 添加Google Maven仓库

```groovy
allprojects {
    repositories {
        jcenter()
        google()
    }
}
```

### 添加依赖

```groovy
dependencies {
    // Room
   implementation "android.arch.persistence.room:runtime:1.0.0"
   annotationProcessor "android.arch.persistence.room:compiler:1.0.0"
}
```

### 定义数据表实体类

班级表

```java
@Entity(tableName = "tb_class")
public class ClassEntity {

    @PrimaryKey
    private long id;
}
```

学生表

```Java
//指示数据表实体类
@Entity(tableName = "tb_student",//定义表名
        indices = @Index(value = {"name", "sex"}, unique = true),//定义索引
        foreignKeys = {@ForeignKey(entity = ClassEntity.class,
                parentColumns = "id",
                childColumns = "class_id")})//定义外键
public class StudentEntity {
    @PrimaryKey //定义主键
    private long id;
    @ColumnInfo(name = "name")//定义数据表中的字段名
    private String name;
    @ColumnInfo(name = "sex")
    private int sex;
    @Ignore//指示Room需要忽略的字段或方法
    private String ignoreText;
    @ColumnInfo(name = "class_id")
    private String class_id;

    //setter and getter
}
```

#### Entity注解可选参数

```java
public @interface Entity {
	//定义表名
    String tableName() default "";
	//定义索引
    Index[] indices() default {};
	//设为true则父类的索引会自动被当前类继承
    boolean inheritSuperIndices() default false;
	//定义主键
    String[] primaryKeys() default {};
	//定义外键
    ForeignKey[] foreignKeys() default {};
}
```

#### Index索引注解可选参数

```java
public @interface Index {
  //定义需要添加索引的字段
  String[] value();
  //定义索引的名称
  String name() default "";
  //true-设置唯一键，标识value数组中的索引字段必须是唯一的，不可重复
  boolean unique() default false;
}
```

#### ForeignKey外键注解可选参数

```java
public @interface ForeignKey {
  //引用外键的表的实体
  Class entity();
  //要引用的外键列
  String[] parentColumns();
  //要关联的列
  String[] childColumns();
  //当父类实体(关联的外键表)从数据库中删除时执行的操作
  @Action int onDelete() default NO_ACTION;
  //当父类实体(关联的外键表)更新时执行的操作
  @Action int onUpdate() default NO_ACTION;
  //在事务完成之前，是否应该推迟外键约束
  boolean deferred() default false;
  //给onDelete，onUpdate定义的操作
  int NO_ACTION = 1;
  int RESTRICT = 2;
  int SET_NULL = 3;
  int SET_DEFAULT = 4;
  int CASCADE = 5;
  @IntDef({NO_ACTION, RESTRICT, SET_NULL, SET_DEFAULT, CASCADE})
  @interface Action {
    }
}
```
### 定义Dao类

```java
@Dao
public interface StudentDao {

    @Query("SELECT * FROM StudentEntity")
    List<StudentEntity> getAll();

    @Query("SELECT * FROM StudentEntity WHERE id IN (:ids)")
    List<StudentEntity> getAllByIds(long[] ids);

    @Insert
    void insert(StudentEntity... entities);

    @Delete
    void delete(StudentEntity entity);

    @Update
    void update(StudentEntity entity);
}
```

@insert， @Update都可以执行事务操作，定义在OnConflictStrategy注解类中

```java

public @interface Insert {
   //定义处理冲突的操作
    @OnConflictStrategy
    int onConflict() default OnConflictStrategy.ABORT;
}
```



```Java
public @interface OnConflictStrategy {
    //策略冲突就替换旧数据
    int REPLACE = 1;
    //策略冲突就回滚事务
    int ROLLBACK = 2;
  	//策略冲突就退出事务
    int ABORT = 3;
   	//策略冲突就使事务失败 
    int FAIL = 4;
    //忽略冲突
    int IGNORE = 5;
}
```

### 定义数据库

```java
@Database(entities = {StudentEntity.class}, version = 1)
public abstract class RoomDemoDatabase extends RoomDatabase {

    public abstract StudentDao studentDao();
}
```

### 生成数据库实例

```java
RoomDemoDatabase database = Room.databaseBuilder(getApplicationContext(),
                RoomDemoDatabase.class, "database_name")
                .build();
```

生成数据库实例的其他操作

```java
Room.databaseBuilder(getApplicationContext(),
                        RoomDemoDatabase.class, "database_name")
                        .addCallback(new RoomDatabase.Callback() {
                            //第一次创建数据库时调用，但是在创建所有表之后调用的
                            @Override
                            public void onCreate(@NonNull SupportSQLiteDatabase db) {
                                super.onCreate(db);
                            }

                            //当数据库被打开时调用
                            @Override
                            public void onOpen(@NonNull SupportSQLiteDatabase db) {
                                super.onOpen(db);
                            }
                        })
                        .allowMainThreadQueries()//允许在主线程查询数据
                        .addMigrations()//迁移数据库使用，下面会单独拿出来讲
                        .fallbackToDestructiveMigration()//迁移数据库如果发生错误，将会重新创建数据库，而不是发生崩溃
                        .build();
```

## 数据库迁移(升级)

```java
Room.databaseBuilder(getApplicationContext(), MyDb.class, "database-name")
        .addMigrations(MIGRATION_1_2, MIGRATION_2_3).build();

static final Migration MIGRATION_1_2 = new Migration(1, 2) {
    @Override
    public void migrate(SupportSQLiteDatabase database) {
        database.execSQL("CREATE TABLE `Fruit` (`id` INTEGER, "
                + "`name` TEXT, PRIMARY KEY(`id`))");
    }
};

static final Migration MIGRATION_2_3 = new Migration(2, 3) {
    @Override
    public void migrate(SupportSQLiteDatabase database) {
        database.execSQL("ALTER TABLE Book "
                + " ADD COLUMN pub_year INTEGER");
    }
};
```

## 创建嵌套对象

有时，您希望将一个实体或普通的以前的Java对象(POJO)作为数据库逻辑中的一个完整的整体来表示，即使该对象包含几个字段。在这些情况下，您可以使用@Embedded来表示一个对象，您希望将其分解为表中的子字段。然后可以像对其他单个列一样查询嵌入式字段

```java
class Address {
    public String street;
    public String state;
    public String city;

    @ColumnInfo(name = "post_code")
    public int postCode;
}

@Entity
class User {
    @PrimaryKey
    public int id;

    public String firstName;

    @Embedded
    public Address address;
}
```

这样user表中的字段就包含了` id`, `firstName`, `street`, `state`, `city`, 和 `post_code`

> `注意`：嵌入式字段还可以包含其他嵌入式字段

如果一个实体具有相同类型的多个内嵌字段，则可以通过设置前缀属性(prefix)使每个列保持惟一。然后将所提供的值添加到嵌入对象中每个列名的开头

```ja
 @Embedded(prefix = "foo_")
 Coordinates coordinates;
```

## 和[`LiveData`](https://developer.android.google.cn/reference/android/arch/lifecycle/LiveData.html)一起使用

添加依赖

```java
 // ReactiveStreams support for LiveData
 implementation "android.arch.lifecycle:reactivestreams:1.0.0"
```

修改返回类型

```Java
@Dao
public interface MyDao {
    @Query("SELECT first_name, last_name FROM user WHERE region IN (:regions)")
    public LiveData<List<User>> loadUsersFromRegionsSync(List<String> regions);
}
```

## 和RxJava一起使用

添加依赖

```java
// RxJava support for Room
  implementation "android.arch.persistence.room:rxjava2:1.0.0"
```

修改返回类型

```Java
@Dao
public interface MyDao {
    @Query("SELECT * from user where id = :id LIMIT 1")
    public Flowable<User> loadUserById(int id);
}
```

## 直接游标访问

```java
@Dao
public interface MyDao {
    @Query("SELECT * FROM user WHERE age > :minAge LIMIT 5")
    public Cursor loadRawUsersOlderThan(int minAge);
}
```

## 类型转换

定义转换类，@TypeConverter注解定义转换的方法

```java
public class Converters {
    @TypeConverter
    public static Date fromTimestamp(Long value) {
        return value == null ? null : new Date(value);
    }

    @TypeConverter
    public static Long dateToTimestamp(Date date) {
        return date == null ? null : date.getTime();
    }
}
```

@TypeConverters注解，告知数据库要依赖哪些转换类

```java
@Database(entities = {User.class}, version = 1)
@TypeConverters({Converters.class})
public abstract class AppDatabase extends RoomDatabase {
    public abstract UserDao userDao();
}
```

使用这些转换器，您可以在其他查询中使用您的自定义类型，正如您将使用基本类型一样，如下代码所示

```java
@Entity
public class User {
    ...
    private Date birthday;
}
```

```java
@Dao
public interface UserDao {
    ...
    @Query("SELECT * FROM user WHERE birthday BETWEEN :from AND :to")
    List<User> findUsersBornBetweenDates(Date from, Date to);
}
```

## 输出模式

在编译时，将数据库的模式信息导出到JSON文件中，这样可有利于我们更好的调试和排错

build.gradle

```groovy
android {
    ...
    defaultConfig {
        ...
        javaCompileOptions {
            annotationProcessorOptions {
                arguments = ["room.schemaLocation":
                             "$projectDir/schemas".toString()]
            }
        }
    }
}
```

您应该将导出的JSON文件(表示数据库的模式历史记录)存储在您的版本控制系统中，因为它允许为测试目的创建您的数据库的旧版本