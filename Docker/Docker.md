## 简介

**Docker**是一个开源的应用容器引擎；是一个轻量级容器技术；

Docker支持将软件编译成一个镜像；然后在镜像中各种软件做好配置，将镜像发布出去，其他使用者可以直接使用这个镜像；

运行中的这个镜像称为容器，容器启动是非常快速的。

[官网](https://www.docker.com/)

[docker hub](https://hub.docker.com/)

## 安装

## 配置阿里云镜像



## 镜像

### 搜索镜像


```shell
docker search 关键字
```

>  docker search mysql

### 拉取镜像

```shell
docker pull 镜像名:tag
```

**tag**是可选的，tag表示标签，多为软件的版本，默认是latest（最新的）

```shell
docker pull mysql
```

### 查看本地镜像

```shell
docker images
```

> root@VM-0-15-ubuntu:/home/ubuntu# docker images
> REPOSITORY                     TAG                 IMAGE ID            CREATED             SIZE
> tomcat                         latest              2d43521f2b1a        3 months ago        463MB
> jenkins                        latest              cd14cecfdb3a        3 months ago        696MB
> mysql                          latest              f45277861b04        3 months ago        445MB
> dominate/idea-license-server   latest              ec21bba92a2f        11 months ago       127MB

`-a`, 列出所有相关信息（含中间印象层）

`-q`，只显示镜像id

`--digest`，显示镜像的摘要信息

`--no-trunc`，显示完整的镜像信息

### 删除本地镜像

```
docker rmi image-id
```

如果已经使用镜像（image）创建过容器（container），可能会删除不了，报错：

```shell
unable to delete ec21bba92a2f (must be forced) - image is being used by stopped container
```

这是需要使用`-f`强制删除:

```
docker rmi -f image-id
```

#### 删除全部

```
docker rmi -f ${docker images -qa}
```

### 构建镜像

使用Dockerfile文件构建新的镜像

```shell
docker build -f /root/Dockerfile -t new-image-name:tag .
```

命令结尾有个`.`表示当前目录

## 容器

### 使用镜像启动容器

```
docker run [options] image [command][arg...]
```

```shell
docker run --name 容器名称 -d -v 主机绝对路径 : 容器内路径 tomcat:latest
```

```shell
--name:为容器指定一个名称
-d：后台运行
-i:以交互模式运行容器，通常与-t同时使用
-t:为容器随机分配一个伪输入终端，通常与-i同时使用
-P:随机端口映射
-p: 将主机的端口映射到容器的一个端口（主机端口:容器内部的端口）
-v：数据卷的挂载(主机绝对路径 : 容器内路径)
```


> docker run -d -p 8888:8080 tomcat

这里涉及到docker container的一个特性，container如果停止运行了，那么再次启动时，之前所有运行相关的数据和文件就都不存在了，就类似于设置了自动还原的电脑一般，无论你做了多少的操作，一旦关机重启之后就又恢复到最初的状态。数据卷就是来解决上述问题的，通过Docker container外部的文件夹的挂载，将可持久化的文件存储到外部挂载的文件夹中。

[命令wiki](https://docs.docker.com/engine/reference/commandline/docker/)

### 显示已启动的容器

```shell
docker ps -a
-a:显示全部，包括启动失败的
```

> root@VM-0-15-ubuntu:/home/ubuntu# docker ps
> CONTAINER ID        IMAGE                          COMMAND                  CREATED             STATUS              PORTS                    NAMES
> 19e2ea0a7a37        dominate/idea-license-server   "/docker-entrypoint.…"   2 months ago        Up 2 months         0.0.0.0:1017->1017/tcp   idea_server

### 退出容器

exit：容器停止退出

ctrl+P+Q：容器不停止退出

### 删除容器

```
docker rm container-id
```

### 停止容器

```shell
docker stop container-id #
docker kill container-id # 强制停止容器
```

### 启动容器

```shell
docker start container-id
```

> docker start container-id -a 

```shell
-a: 查看输出日志
```

### 查看容器日志

```shell
docker logs -f -t --tail container-id
```

```shell
-f：加入时间戳
-t：跟随最新的日志打印
--tail：数字 显示最后多少条
```

### 查看容器内的进程

```shell
docker top container-id
```

### 查看容器内部细节

```shell
docker inspect container-id
```

### 进入容器内并命令交互

```shell
# 直接进入容器启动命令的终端，不会启动新的进程
docker attach container-id 
# 是在容器中打开新的终端，并且可以启动新的进程
docker exec -it container-id bashShell
```

### 从容器内拷贝文件到主机上

```shell
docker cp container-id:容器内路径 目的主机路径
```

```shell
docker cp container-id:/tmp/xxx.log /root/xxx.log
```

## 从容器创建一个新的镜像

 ```shell
docker commit -m "提交的描述信息" -a "作者" container-id	image-name:tag
 ```

```shell
-p：在commit时，将容器暂停
-c：使用Dockerfile指令创建镜像
```

## 容器数据卷

### 是什么

### 能干嘛

### 数据卷

```shell
docker run -it -v 主机绝对路径目录:容器绝对路径目录 image-name
```

```shell
:ro # readOnly 只能读不能写，新建文件都不可以
docker run -it -v 主机绝对路径目录:容器绝对路径目录:ro image-name
```



### 数据卷容器



## Dockerfile

Dockerfile 是一个文本文件，其内包含了一条条的**指令(Instruction)**，每一条指令构建一层，因此每一条指令的内容，就是描述该层应当如何构建。

Dockerfile是用来构建Docker镜像的构建文件，是由一系列命令和参数构成的脚本。

### 基础知识

1. 每条保留字指令都必须为大写字母且后面要跟随至少一个参数
2. 指令按照从上到下，顺序执行
3. `#`是注释
4. 每条指令都会创建一个新的镜像层，并对镜像进行提交

### Docker执行Dockerfile的大致流程

1. docker从基础镜像运行一个容器
2. 执行一条指令并对容器作出修改
3. 执行类似docker commit的操作提交一个新的镜像层
4. docker再基于刚提交的镜像运行一个新的容器
5. 执行dockerfile中的下一条指令直到所有指令都执行完毕

### 保留字指令

* FROM : 基础镜像，当前新镜像是基于哪个镜像的
* MAINTAINER : 镜像维护者的姓名和邮箱地址
* RUN : 容器构建时需要运行的命令
* EXPOSE : 当前容器对外暴露出的端口
* WORKDIR : 指定在创建容器后，终端默认登录进来的工作目录，一个落脚点
* ENV : 用来在构建镜像过程中设置环境变量
* ADD : 将宿主机目录下的文件拷贝进镜像，且ADD命令会自动处理URL和解压压缩包
* COPY : 类似ADD命令，但是不会解压压缩文件 
* VOLUME : 容器数据卷，用于数据保存和持久化工作
* CMD : 指定一个容器启动时要运行的命令，Dockerfile中可以有多个CMD指令，但是只有最后一个生效，CMD会被docker run 之后的参数替换
* ENTRYPOINT : 和`CMD`命令类似，但是`ENTRYPOINT`命令可以追加参数
* ONBUILD : 当构建一个被继承的Dockerfile时运行命令

## 其他

```shell
--privileged=true # 写权限不够，加上该参数
```

