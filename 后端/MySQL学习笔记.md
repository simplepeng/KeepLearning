## 常用操作

### 连接mysql
```mysql
mysql -h host -P port -u username -p
```
### 查看端口
```mysql
SHOW VARIABLES LIKE 'port';
```

### 清屏

```mysql
SYSTEM CLEAR;
```

### 执行sql脚本

sql脚本为.sql结尾

```mysql
source 脚本文件路径;
```



## 数据库操作

### 创建数据库



### 选择数据库



### 删除数据库

### 显示所有数据库

```mysql
SHOW DATABASES;
```


## 表操作

### 显示表结构

```mysql
DESC 表名;
```

### 创建数据表

```mysql
CREATE TABLE 表名 (字段名 字段类型,...);
```

### 显示建表语句

```mysql
SHOW CREATE TABLE 表名;
```

### 删除数据表

```mysql
DROP TABLE 表名;
```

### 查询数据

#### 基本查询

```mysql
SELECT 条件 FROM 数据源;
```

#### 排序(ORDER BY)

```mysql
SELECT 条件 FROM 数据源 ORDER BY 字段名,... [ASC,DESC];
```

* 可以同时设定多个字段进行排序
* ASC升序，DESC降序，默认是升序
* 同时可以添加 WHERE...LIKE 子句来设置条件

#### 分组(GROUP BY)

```mysql

```

#### 连接(JOIN)

```mysql
SELECT 条件 FROM 数据源1 [INNER,LEFT,RIGHT]JOIN 数据源2;
```

* **INNER JOIN（内连接,或等值连接）**：获取两个表中字段匹配关系的记录,可省略INNER关键字
* **LEFT JOIN（左连接）：**获取左表所有记录，即使右表没有对应匹配的记录
* **RIGHT JOIN（右连接）：** 与 LEFT JOIN 相反，一般很少用，LEFT JOIN 交换数据源可实现同样的效果

### 插入数据

```mysql
INSERT INTO 表名 (字段名，...) VALUES (值，...);
```

* 如果数据是字符型，必须使用单引号或者双引号，如："simple"。

### 更新数据

```mysql
UPDATE 表名 SET 字段名=字段值,... [WHERE 条件语句]
```

* 可用同时更新一个或多个字段
* 可以在WHERE字句中指定条件

### 删除数据

```mysql
DELETE FROM 表名 [WHERE 条件语句]
```

* 不加 WHERE 条件语句 将会删除表中所有数据

### WHERE字句

```mysql
SELECT 条件 FROM 数据源 WHERE 条件语句 [AND,OR] 条件语句;
```

* 可以使用 AND 或者 OR 指定一个或多个条件
* WHERE 子句也可以运用于 SQL 的 DELETE 或者 UPDATE 命令
* WHERE 子句类似于程序语言中的 if 条件，根据 MySQL 表中的字段值来读取指定的数据

### LIKE字句

```mysql
SELECT 条件 FROM 数据源  WHERE 字段名 LIKE '%字符' [[AND,OR] 条件语句] 
```

* 可以在 DELETE 或 UPDATE 命令中使用 WHERE...LIKE 子句来指定条件
* LIKE 通常与 % 一同使用


### ALTER命令

当需要修改数据表名或者修改数据表字段时，就需要使用ALTER命令

##### 重命名表名

```mysql
ALTER TABLE 表名 RENAME TO 新表名;
```

##### 删除字段

```mysql
ALTER TABLE 表名 DROP 字段名；
```

##### 新增字段

```mysql
ALTER TABLE 表名 ADD 字段名 字段类型；
```

##### 修改字段类型及名称

```mysql
ALTER TABLE 表名 MODIFY 字段名 修改后的字段类型；
```

```mysql
ALTER TABLE 表名 CHANGE 字段名 新字段名 字段类型；
```

##### 修改字段默认值

```mysql
ALTER TABLE 表名 ALTER 字段名 SET DEFAULT 默认值；
```

##### 删除字段默认值

```mysql
ALTER TABLE 表名 ALTER 字段名 DROP DEFAULT；
```

##### 修改存储引擎

```mysql
ALTER TABLE 表名 ENGINE = 引擎类型；
```

