### let和const

* 块级作用域

* 同一作用域不可重复声明

* 变量无法再声明前使用

ES6新增了`let`关键字用来声明变量，和`var`关键字使用方法类似，但是`let`的作用域是块级作用域。也就是说用`let`声明的变量只在该代码块中使用。

```javascript
{

    let a = 1;

    var b = 2;

}

a;// ReferenceError: a is not defined.

b;//2

```

### const

常量，声明后即不可以改变。

```javascript

const PI = 3.14;

PI;//3.14

PI = 5;//Uncaught TypeError: Assignment to constant variable

```

声明的同时必须初始化

```javascript

const PI;//Uncaught SyntaxError: Missing initializer in const declaration

```

作用域也是块级

```javascript

if(true){

    const PI = 3.14;

    PI;

}

PI; // Uncaught ReferenceError: PI is not defined

```