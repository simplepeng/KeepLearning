## 连接mysql
```mysql
mysql -u 用户名 -p
```

## 数据库操作



## 表操作

### 创建数据表

```mysql
CREATE TABLE 表名 (字段名 字段类型);
```

## 删除数据表

```mysql
DROP TABLE 表名;
```

### 重命名表名

```mysql
ALTER  TABLE  table_name RENAME TO new_table_name;
```



## 查询数据

#### 基本查询

```mysql
SELECT 条件 FROM 数据源;
```

#### 选择查询

```mysql
SELECT 条件 FROM 数据源 WHERE 条件语句;
```



## 插入数据

```mysql
INSERT INTO 表名 (字段名，...) VALUES (值，...);
```

* 如果数据是字符型，必须使用单引号或者双引号，如："simple"。



## 更新数据

```mysql
UPDATE 表名 SET 字段名=字段值,... [WHERE 条件语句]
```

* 可用同时更新一个或多个字段
* 可以在WHERE字句中指定条件



## 删除数据

```mysql
DELETE FROM 表名 [WHERE 条件语句]
```



## 常用操作

### 查看端口

```mysql
SHOW VARIABLES LIKE 'port';
```

