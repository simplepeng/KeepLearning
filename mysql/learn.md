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

```mysql
CREATE DATABASE 数据库名;
```

### 选择数据库

```mysql
use 数据库名;
```

### 删除数据库

```mysql
drop database <数据库名>;
```

### 显示所有数据库

```mysql
SHOW DATABASES;
```

## 表操作

### 数据类型

#### 数值类型

| 类型         | 大小                                     | 范围（有符号）                                               | 范围（无符号）                                               | 用途            |
| ------------ | ---------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | --------------- |
| TINYINT      | 1 字节                                   | (-128，127)                                                  | (0，255)                                                     | 小整数值        |
| SMALLINT     | 2 字节                                   | (-32 768，32 767)                                            | (0，65 535)                                                  | 大整数值        |
| MEDIUMINT    | 3 字节                                   | (-8 388 608，8 388 607)                                      | (0，16 777 215)                                              | 大整数值        |
| INT或INTEGER | 4 字节                                   | (-2 147 483 648，2 147 483 647)                              | (0，4 294 967 295)                                           | 大整数值        |
| BIGINT       | 8 字节                                   | (-9 233 372 036 854 775 808，9 223 372 036 854 775 807)      | (0，18 446 744 073 709 551 615)                              | 极大整数值      |
| FLOAT        | 4 字节                                   | (-3.402 823 466 E+38，-1.175 494 351 E-38)，0，(1.175 494 351 E-38，3.402 823 466 351 E+38) | 0，(1.175 494 351 E-38，3.402 823 466 E+38)                  | 单精度 浮点数值 |
| DOUBLE       | 8 字节                                   | (-1.797 693 134 862 315 7 E+308，-2.225 073 858 507 201 4 E-308)，0，(2.225 073 858 507 201 4 E-308，1.797 693 134 862 315 7 E+308) | 0，(2.225 073 858 507 201 4 E-308，1.797 693 134 862 315 7 E+308) | 双精度 浮点数值 |
| DECIMAL      | 对DECIMAL(M,D) ，如果M>D，为M+2否则为D+2 | 依赖于M和D的值                                               | 依赖于M和D的值                                               | 小数值          |

#### 时间类型

| 类型      | 大小 (字节) | 范围                                                         | 格式                | 用途                     |
| --------- | ----------- | ------------------------------------------------------------ | ------------------- | ------------------------ |
| DATE      | 3           | 1000-01-01/9999-12-31                                        | YYYY-MM-DD          | 日期值                   |
| TIME      | 3           | '-838:59:59'/'838:59:59'                                     | HH:MM:SS            | 时间值或持续时间         |
| YEAR      | 1           | 1901/2155                                                    | YYYY                | 年份值                   |
| DATETIME  | 8           | 1000-01-01 00:00:00/9999-12-31 23:59:59                      | YYYY-MM-DD HH:MM:SS | 混合日期和时间值         |
| TIMESTAMP | 4           | 1970-01-01 00:00:00/2038结束时间是第 **2147483647** 秒，北京时间 **2038-1-19 11:14:07**，格林尼治时间 2038年1月19日 凌晨 03:14:07 | YYYYMMDD HHMMSS     | 混合日期和时间值，时间戳 |

#### 字符串类型

| 类型       | 大小                | 用途                            |
| ---------- | ------------------- | ------------------------------- |
| CHAR       | 0-255字节           | 定长字符串                      |
| VARCHAR    | 0-65535 字节        | 变长字符串                      |
| TINYBLOB   | 0-255字节           | 不超过 255 个字符的二进制字符串 |
| TINYTEXT   | 0-255字节           | 短文本字符串                    |
| BLOB       | 0-65 535字节        | 二进制形式的长文本数据          |
| TEXT       | 0-65 535字节        | 长文本数据                      |
| MEDIUMBLOB | 0-16 777 215字节    | 二进制形式的中等长度文本数据    |
| MEDIUMTEXT | 0-16 777 215字节    | 中等长度文本数据                |
| LONGBLOB   | 0-4 294 967 295字节 | 二进制形式的极大文本数据        |
| LONGTEXT   | 0-4 294 967 295字节 | 极大文本数据                    |

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
SELECT 条件 FROM 数据源 GROUP BY 字段名
```

#### 连接(JOIN)

```mysql
SELECT 条件 FROM 数据源1 [INNER,LEFT,RIGHT]JOIN 数据源2;
```

* **INNER JOIN（内连接,或等值连接）**：获取两个数据源中字段匹配关系的记录,可省略INNER关键字
* **LEFT JOIN（左连接）：**获取左数据源所有记录，即使右数据源没有对应匹配的记录
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
