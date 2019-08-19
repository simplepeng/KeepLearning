## 发布到本地Maven

1. 在`module`的`build.gradle`中加入下面的代码

```groovy
uploadArchives {
    repositories.mavenDeployer {
        // 本地仓库路径
        repository(url: 'file:///Users/chenpeng/Desktop/Repositories/')
        // 唯一标识
        pom.groupId = "me.simple"
        // 项目名称
        pom.artifactId = "itemdecorator"
        // 版本号
        pom.version = "1.0.0"
    }
}
```

2. 刷新gradle，并点击上传

![](https://raw.githubusercontent.com/simplepeng/ImageRepo/master/update_archives.png)

这样就可以在本地的Maven仓库里看到我们上传的包。

![](https://raw.githubusercontent.com/simplepeng/ImageRepo/master/mave_local.png)

3. 在需要导入本地包的项目的根`build.gradle`引入自定义Maven仓库

```groovy
   allprojects {
       repositories {
           mavenLocal()
           maven {
               url "file:///Users/chenpeng/Desktop/Repositories/"
           }
           google()
           jcenter()
       }
   }
```

4. 引入依赖

```groovy
 implementation 'me.simple:itemdecorator:1.0.0'
```

