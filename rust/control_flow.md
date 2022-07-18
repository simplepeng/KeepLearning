# 流程控制

rust 使用`if-else`做条件分支，`loop`，`while`，`for`做循环分支。

### if

```rust
if a < b {

} else {

}
```

rust 的判断表达式不用加`()`括号。

if 表达式可以返回值，但是不能加`;`分号。

```rust
let a = if condition { 5 } else { 6 };
```

### loop

```rust
loop {
    println!("again!");
}
```

### while

```rust
let mut number = 3;
while number != 0 {
    println!("{number}!");
    number -= 1;
}
println!("LIFTOFF!!!");
```

### for

```rust
for number in (1..4).rev() {
    println!("{number}!");
}
println!("LIFTOFF!!!");
```
