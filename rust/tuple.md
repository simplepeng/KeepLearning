# 元组

元组是一个将多个其他类型的值组合进一个复合类型的主要方式。

元组长度固定：一旦声明，其长度不会增大或缩小。

```rust
let tup: (i32, f64, u8) = (500, 6.4, 1);
```

元组解构

```rust
let tup = (500, 6.4, 1);
let (x, y, z) = tup;
println!("The value of y is: {y}");
```