## 简介

**Docker**是一个开源的应用容器引擎；是一个轻量级容器技术；

Docker支持将软件编译成一个镜像；然后在镜像中各种软件做好配置，将镜像发布出去，其他使用者可以直接使用这个镜像；

运行中的这个镜像称为容器，容器启动是非常快速的。

[官网](https://www.docker.com/)

[docker hub](https://hub.docker.com/)

## 安装

## 常用命令

### 搜索镜像


```shell
docker search 关键字
```

>  docker search mysql

### 拉取镜像

```shell
docker pull 镜像名:tag
```

**tag**是可选的，tag表示标签，多为软件的版本，默认是latest

```shell
docker search mysql
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

### 删除本地镜像

> docker rmi image-id

### 使用镜像启动容器

```shell
docker run --name 容器名称 -d tomcat:latest
```

### 显示已启动的容器

```shell
docker ps
```

> root@VM-0-15-ubuntu:/home/ubuntu# docker ps
> CONTAINER ID        IMAGE                          COMMAND                  CREATED             STATUS              PORTS                    NAMES
> 19e2ea0a7a37        dominate/idea-license-server   "/docker-entrypoint.…"   2 months ago        Up 2 months         0.0.0.0:1017->1017/tcp   idea_server

### 删除容器

```
docker rm container-id
```

### 停止容器

```shell
docker stop container-id
```

### 启动容器

```shell
docker start container-id
```

> docker start container-id -a 

```shell
-a: 查看输出日志
```

### 后台运行，端口映射

```shell
-d：后台运行
-p: 将主机的端口映射到容器的一个端口    主机端口:容器内部的端口
-v：数据卷的挂载。
```


> docker run -d -p 8888:8080 tomcat

这里涉及到docker container的一个特性，container如果停止运行了，那么再次启动时，之前所有运行相关的数据和文件就都不存在了，就类似于设置了自动还原的电脑一般，无论你做了多少的操作，一旦关机重启之后就又恢复到最初的状态。数据卷就是来解决上述问题的，通过Docker container外部的文件夹的挂载，将可持久化的文件存储到外部挂载的文件夹中。

[命令wiki](https://docs.docker.com/engine/reference/commandline/docker/)