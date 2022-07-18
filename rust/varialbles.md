# 变量

```rust
let a = "hello world";
```
rust的变量也有类型推导，当然也可以显示标注变量类型，也是用`:`符号后置标注法。

```rust
let a: &str= "hello world";
```

rust变量默认是不可变的，使用`mut`关键字让变量变为可变的。

```rust
let mut a = "hello world";
```

可以使用`下划线`开头忽略未使用的变量

```rust
let _x = 5;
let y = 6;//未使用变量在编译时会给出警告
```

变量解构

```rust
let (a, mut b): (bool, bool) = (true, false);
```

`变量遮蔽(shadowing)`

```rust
let x = 5;
let x = x + 1;
```