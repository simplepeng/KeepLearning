# kotlin使用Parcelize注解简化Parcelable的书写

##Parcelize注解

kotlin在1.1.4版本增加了对parcelable的支持

Android扩展插件现在包含一个实现了Parcelable的自动生成器。在主构造函数中声明序列化的属性并添加一个@Parcelize注解，生成器就会自动创建writeToParcel（）/ createFromParcel（）方法

## 需求环境

Kotlin版本为1.1.4或者更高

## 开始使用

### 在build.gradle中添加支持

```groovy
apply plugin: ‘kotlin-android-extensions’
....
androidExtensions {
    experimental = true
}
```

### 实体类

Student.kt 

```kotlin
@Parcelize
data class Student(val id: String, val name: String, val grade: String) : Parcelable
```

### 对比Java实体类

Student.java

```java
public class Student implements Parcelable{
        private String id;
        private String name;
        private String grade;

        // Constructor
        public Student(String id, String name, String grade){
            this.id = id;
            this.name = name;
            this.grade = grade;
       }
       // Getter and setter methods
       .........
       .........

       // Parcelling part
       public Student(Parcel in){
           String[] data = new String[3];

           in.readStringArray(data);
           // the order needs to be the same as in writeToParcel() method
           this.id = data[0];
           this.name = data[1];
           this.grade = data[2];
       }

       @Оverride
       public int describeContents(){
           return 0;
       }

       @Override
       public void writeToParcel(Parcel dest, int flags) {
           dest.writeStringArray(new String[] {this.id,
                                               this.name,
                                               this.grade});
       }
       public static final Parcelable.Creator CREATOR = new Parcelable.Creator() {
           public Student createFromParcel(Parcel in) {
               return new Student(in); 
           }

           public Student[] newArray(int size) {
               return new Student[size];
           }
       };
   }
```

## 关于Lint检查报错

现在Android Studio会爆出下面图中的这个错误，这是IntelliJ的Bug，你可以在下面的链接找到相应的答案

[https://youtrack.jetbrains.com/issue/KT-19300]()

![这里写图片描述](http://img.blog.csdn.net/20171205120006608?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvcXFfMjE3OTM0NjM=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

所以你可以忽略这个警告并编译项目，或者也可以添加@SuppressLint("ParcelCreator")注解

### 英文原文链接

[https://android.jlelse.eu/yet-another-awesome-kotlin-feature-parcelize-5439718ba220]()

