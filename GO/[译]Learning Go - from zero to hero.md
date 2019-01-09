# Learning Go - from zero to hero

[原文链接](https://medium.freecodecamp.org/learning-go-from-zero-to-hero-d2a3223b3d86)

让我们从Go（或Golang）的一个小介绍开始。Go由Google工程师Robert Griesemer，Rob Pike和Ken Thompson设计，它是一种静态类型的编译语言。第一个版本于2012年3月作为开源发布。

> “Go是一种开源编程语言，可以轻松构建简单，可靠，高效的软件”
>
> ​	——GoLang

在许多语言中，有许多方法可以解决给定的问题。程序员可能花很多时间去思考解决问题的最佳方法。

另一方面，Go相信更少的功能 - 只有一种正确的方法来解决问题。这节省了开发人员的时间，并使大型代码库易于维护。

Go中没有像`maps`和`filters`这种富有表现力的功能。

> “当你使用这种富有表现力的功能时，通常会带来额外的负担”
>
> ​	——Rob Pike

## 入门

Go由包组成。`main`包告诉Go编译器程序被编译为可执行文件，而不是共享库。它是应用程序的入口点。

```go
package main
```

让我们通过在Go工作区中创建一个文件`main.go`来编写一个简单的hello world示例

## 工作区（Workspace）

Go中的Workspace由环境变量`GOPATH`定义

您编写的任何代码都将写入工作区内，Go将搜索`GOPATH`目录中的任何包，或者在安装Go时默认设置的`GOROOT`目录。`GOROOT`是安装go的路径。

将GOPATH设置为所需的目录。现在，让我们将其添加到文件夹中`~/workspace`。

```shell
# export env
export GOPATH=~/workspace
# go inside the workspace directory
cd ~/workspace
```

在`workspace`目录下创建`main.go`

## HelloWorld

```go
package main

import(
	"fmt"
)

func main(){
    fmt.Println("Hello World")
}
```

在上面这个例子中，`fmt`是Go中的内置包，它实现了格式化I / O的功能。

我们使用关键字`import`导入一个包。`func main`是代码执行的入口点。`Println`是`fmt`包中的一个函数，它为我们打印`Hello Wrold`。

让我们看一下运行这个文件。我们可以通过两种方式运行Go命令。我们知道，Go是一种编译语言，所以我们首先需要在执行之前编译它。

```shell
> go build main.go
```

这将创建一个二进制可执行文件main，现在我们可以运行它

```shell
 > ./main
 # Hello World!
```

还有另一种更简单的方法来运行程序。` go run`命令有助于抽象编译步骤。您只需运行以下命令即可执行该程序。

```shell
> go run main.go
 # Hello World!
```

[在线运行Go代码   https://play.golang.org/](https://play.golang.org/)

## 变量（variables）

变量在Go中是明确类型的，Go是一门静态类型语言。这意味着在变量声明时会检查变量类型，变量可以声明为：

```go
var a int
```

在这种情况下，这个变量被设置为0。使用以下语法声明和初始化具有不同值的变量：

```go
var a = 1
```

这里的变量a被自动指定为int类型。我们还可以使用变量声明的简写定义：

```go
message := "hello world"
```

我们也可以在同一行中声明多个变量:

```go
var b,c int = 2,3
```

**tips：在go中声明变量后面可以不用分号结尾，go采用类型后置声明法**

## 数据类型（Data types）

像其他语言一样，Go也支持各种不同的数据结构。我们来探讨其中一些：

### 数字，字符串，布尔（Number，String， Boolean）

一些受支持的数字存储类型是`int`,`int8`,`int16`,`int32`,`int64`,`uint`,`uint8`,`uint16`,`uint32`,`uintptr`...

字符串类型存储一系列字节,它用关键字`string`表示和声明。

使用关键字`bool`存储布尔值。

Go还支持复数类型数据类型吗，可以用`complex64`和`complex128`声明。

```go
var a bool = true
var b int = 1
var c string = 'hello world'
var d float32 = 1.222
var x complex128 = cmplx.Sqrt(-5 + 12i)
```

### 数组，切片，映射（Arrays，Slices，Maps）

数组是相同数据类型的元素序列，数组在声明时需要定义数组的长度，所有它不能扩容。数组声明为：

```go
var a [5]int
```

数组也可以声明为多维数组：

```go
var multiD [2][3]int
```

当数组的值需要在运行时更改时，数组限制了这种情况。数组也不提供获取子数组的能力。为此，Go有一个名为`slices`的数据类型。

`Slices`存储一系列元素，可以随时扩展。切片声明类似于数组声明。只是没有定义数组的容量。

```go
var b []int
```

这将创建一个零容量，零长度的切片。切片也可以定义容量和长度。我们可以使用以下语法：

```go
numbers := make([]int,5,10)
```

在这里，切片的初始长度为5，容量为10。

切片是数组的抽象，切片使用数组作为底层结构，切片包含三个组件：容量，长度和指向底层数组的指针。

通过使用append或copy函数可以增加切片的容量。 append函数可以为数组的末尾添加值，并在需要时增加容量。

```go
numbers = append(numbers, 1, 2, 3, 4)
```

增加切片容量的另一种方法是使用复制功能，只需创建另一个具有更大容量的切片，然后将原始切片复制到新创建的切片。

```go
// create a new slice
number2 := make([]int, 15)
// copy the original slice to new slice
copy(number2, number)
```

我们可以创建切片的子切片。这可以使用以下命令简单地完成：

```go
// initialize a slice with 4 len and values
number2 = []int{1,2,3,4}
fmt.Println(numbers) // -> [1 2 3 4]
// create sub slices
slice1 := number2[2:]
fmt.Println(slice1) // -> [3 4]
slice2 := number2[:3]
fmt.Println(slice2) // -> [1 2 3]
slice3 := number2[1:4]
fmt.Println(slice3) // -> [2 3 4]
```

`map`是Go中的数据类型，它将`键`映射到`值`。我们可以使用以下命令定义map：

```go
var m map[string]int
```

这里m是新的map变量，它的键为字符串，值为整数。我们可以轻松地将键和值添加到map中：

```go
m['clearity'] = 2
m['simplicity'] = 3
// printing the values
fmt.Println(m['clearity']) // -> 2
fmt.Println(m['simplicity']) // -> 3
```

### 类型强转

可以使用类型转换将一种类型的数据类型转换为另一种类型，我们来看一个简单的类型转换：

```go
a := 1.1
b := int(a)
fmt.Println(b)
//-> 1
```

并非所有类型的数据类型都可以转换为其他类型，确保数据类型与转换类型是否兼容。

## 条件语句

### if else

对于条件语句，我们可以使用if-else语句，如下例所示。确保花括号与条件位于同一行。

```go
if num := 9; num < 0 {
 fmt.Println(num, "is negative")
} else if num < 10 {
 fmt.Println(num, "has 1 digit")
} else {
 fmt.Println(num, "has multiple digits")
}
```

**tips：go中的代码块括号不换行，并且条件判断的表达式不加括号**

### switch case

switch case 有助于组织多个条件语句，以下示例显示了一个简单的switch case语句：

```go
i := 2
switch i {
case 1:
 fmt.Println("one")
case 2:
 fmt.Println("two")
default:
 fmt.Println("none")
}
```

## 循环

go只有一个关键字`for`来实现循环操作

```go
i := 0
sum := 0
for i < 10 {
 sum += 1
  i++
}
fmt.Println(sum)
```

上面的这个例子类似于C语言中的`while`循环，相同的for语句可用于正常for循环：

```go
sum := 0
for i := 0; i < 10; i++ {
  sum += i
}
fmt.Println(sum)
```

Go中的无限循环：

```go
for {
}
```

## 指针

Go也提供了指针变量，指针是保存值地址的变量。指针用`*`号定义，根据数据类型定义指针

```go
var ap *int
```

这里的`ap`是指向整数类型的指针，`＆`运算符（取地址符）可用于获取变量的地址。

```go
a := 12
ap = &a
```

可以使用`*运算符`访问指针指向的值：

```go
fmt.Println(*ap)
// => 12
```

指针通常在当**将结构作为参数传递**或者为**已定义的类型声明方法**时使用

1. 值传递时，复制的值意味着消耗更多的内存

2. 传递指针后，函数更改的值将反映在方法/函数调用者中

```go
func increment(i *int) {
  *i++
}
func main() {
  i := 10
  increment(&i)
  fmt.Println(i)
}
//=> 11
```

注意：在博客中尝试示例代码时，不要忘记将其包含在main包中，并在需要时导入fmt或其他包，如上面第一个main.go示例所示。

## 函数

main函数是被定义在main包下的主程序的入口。当然我们自己也可以定义更多的函数来使用。

```go
func add(a int, b int) int {
  c := a + b
  return c
}
func main() {
  fmt.Println(add(2, 1))
}
//=> 3
```

正如我们在上面的例子中看到的那样，使用`func`关键字后跟函数名定义Go函数。函数所需的参数需要根据其数据类型定义，最后是返回的数据类型。

函数的返回也可以在函数中预定义：

```go
func add(a int, b int) (c int) {
  c = a + b
  return
}
func main() {
  fmt.Println(add(2, 1))
}
//=> 3
```

这里c被定义为返回变量。因此，定义的变量c将自动返回，而无需在结尾的return语句中定义。

您还可以从使用逗号分隔返回值的单个函数返回多个返回值：

```go
func add(a int, b int) (int, string) {
  c := a + b
  return c, "successfully added"
}
func main() {
  sum, message := add(2, 1)
  fmt.Println(message)
  fmt.Println(sum)
}
```

## 方法，结构，接口（Method, Structs, and Interfaces）

Go不是一种完全面向对象的语言，但是对于结构，接口和方法，它有很多面向对象的支持和感觉。

### 结构（struct）

结构是不同字段的类型集合，结构用于将数据组合在一起。例如，如果我们想要定义Person类型的数据组合，我们会定义一个人的属性，其中可能包括姓名，年龄，性别。可以使用以下语法定义结构：

```go
type person struct {
  name string
  age int
  gender string
}
```

在定义了person类型结构的情况下，现在让我们创建一个person对象：

```go
//way 1: specifying attribute and value
p = person{name: "Bob", age: 42, gender: "Male"}
//way 2: specifying only value
person{"Bob", 42, "Male"}
```

我们可以使用`点运算符（.）`轻松访问对象的属性。

```go
p.name
//=> Bob
p.age
//=> 42
p.gender
//=> Male
```

您还可以使用其指针直接访问结构的属性：

```go
pp = &person{name: "Bob", age: 42, gender: "Male"}
pp.name
//=> Bob
```

### 方法（method）

方法是具有接收器的特殊类型的函数。接收器既可以是值，也可以是指针。让我们创建一个名为describe的方法，它具有我们在上面的例子中创建类型为person的接收器。

```go
package main
import "fmt"

// struct defination
type person struct {
  name   string
  age    int
  gender string
}

// method defination
func (p *person) describe() {
  fmt.Printf("%v is %v years old.", p.name, p.age)
}
func (p *person) setAge(age int) {
  p.age = age
}

func (p person) setName(name string) {
  p.name = name
}

func main() {
  pp := &person{name: "Bob", age: 42, gender: "Male"}
  pp.describe()
  // => Bob is 42 years old
  pp.setAge(45)
  fmt.Println(pp.age)
  //=> 45
  pp.setName("Hari")
  fmt.Println(pp.name)
  //=> Bob
}
```

正如我们在上面的例子中所看到的，方法`describe`现在可以使用点运算符来调用该方法`pp.describe()`。请注意，接收器是指针。使用指针，我们传递对值的引用，因此如果我们对方法进行任何更改，它将反映在接收器`pp`中。它也不会创建对象的新副本，从而节省了内存。

请注意，在上面的示例中，age的值已更改，而name的值未更改，因为方法setName属于接收器类型，而setAge属于指针类型。

### 接口（interface）

Go中的接口是方法的集合。接口有助于将类型的属性组合在一起。我们以接口animal为例：

```go
type animal interface {
  description() string
}
```

这里的animal是一种接口类型，现在让我们创建两种不同类型的动物来实现animal接口类型。

```go
package main

import (
  "fmt"
)

type animal interface {
  description() string
}

type cat struct {
  Type  string
  Sound string
}

type snake struct {
  Type      string
  Poisonous bool
}

func (s snake) description() string {
  return fmt.Sprintf("Poisonous: %v", s.Poisonous)
}

func (c cat) description() string {
  return fmt.Sprintf("Sound: %v", c.Sound)
}

func main() {
  var a animal
  a = snake{Poisonous: true}
  fmt.Println(a.description())
  a = cat{Sound: "Meow!!!"}
  fmt.Println(a.description())
}

//=> Poisonous: true
//=> Sound: Meow!!!
```

在main函数中，我们创建一个动物类型的变量a，我们为动物分配蛇和猫类型，并使用Println打印a.description。

由于我们以不同的方式实现了两种类型（猫和蛇）中描述的方法，我们就可以打印动物的描述（description）。

[鸭子类型 duck typing](https://zh.wikipedia.org/wiki/%E9%B8%AD%E5%AD%90%E7%B1%BB%E5%9E%8B)

## 包（packages）

我们在Go的包中书写所有的代码。主程序包是程序执行的入口点。这里有许多Go中的内置包。我们一直使用的最着名的是`fmt`包。

### 安装包

```shell
go get <package-url-github>
// example
go get github.com/satori/go.uuid
```

我们安装的软件包保存在GOPATH env中，这是我们的工作目录。您可以通过`cd $GOPATH/pkg`进入我们工作目录中的pkg包文件夹。

### 创建自定义的包

让我们从创建一个文件夹custom_package开始：

```shell
> mkdir custom_package
> cd custom_package
```

要创建自定义包，我们需要首先使用我们需要的包名创建一个文件夹。假设我们正在建立一个包`person`，为此，我们在`custom_package`文件夹中创建一个名为`person`的文件夹。

```shell
> mkdir person
> cd person
```

现在让我们在这个文件夹中创建一个文件`person.go`。

```go
package person
func Description(name string) string {
  return "The person name is: " + name
}
func secretName(name string) string {
  return "Do not share"
}
```

我们现在需要安装包，以便可以导入和使用它。

```shell
go install
```

现在让我们回到`custom_package`文件夹并创建一个`main.go`文件。

```go
package main
import(
  "custom_package/person"
  "fmt"
)
func main(){ 
  p := person.Description("Milap")
  fmt.Println(p)
}
// => The person name is: Milap
```

现在，我们可以导入我们创建的`person`包并使用函数Description。请注意，我们在包中创建的函数secretName将无法访问（注：Go包访问权限使用函数名首字母大小写区分的）。在Go中，小写字母开头的的函数访问权限是`private`。

### 包文档（Packages Documentation）

Go内置了对包文档的支持 ，运行以下命令以生成文档：

```shell
godoc person Description
```

这将为person包内的Description函数生成文档，要查看文档，请使用以下命令运行Web服务器：

```shell
godoc -http=":8080"
```

现在转到URL` http:// localhost:8080/pkg/`并查看我们刚创建的包的文档。

### Go中的一些内置包

#### fmt

该包实现了格式化的`I / O`（输入/输出）功能。我们已经使用过该包打印到stdout。

#### json

Go中另一个有用的包是json包。它帮助我们编码/解码（encode/decode）Json格式的文件。

```go
// Encode
package main

import (
  "fmt"
  "encoding/json"
)

func main(){
  mapA := map[string]int{"apple": 5, "lettuce": 7}
  mapB, _ := json.Marshal(mapA)
  fmt.Println(string(mapB))
}
```

```go
// Decode
package main

import (
  "fmt"
  "encoding/json"
)

type response struct {
  PageNumber int `json:"page"`
  Fruits []string `json:"fruits"`
}

func main(){
  str := `{"page": 1, "fruits": ["apple", "peach"]}`
  res := response{}
  json.Unmarshal([]byte(str), &res)
  fmt.Println(res.PageNumber)
}
//=> 1
```

在使用`unmarshal`解码json字节时，第一个参数是json字节，第二个参数是我们希望json映射到的响应类型struct的地址。请注意`json:”page”`将json中的page属性映射给struct中PageNumber属性。

## 错误处理（Error Handling）

errors是程序没有按照预期执行而导致的结果。假设我们正在对外部服务进行API调用，此API调用可能成功或可能失败，当存在错误类型时，Go程序中的错误可以被标记识别出来：

```go
resp, err := http.Get("http://example.com/")
```

这里对错误对象的API调用可能通过或可能失败。我们可以检查错误是否为`nil`，并相应地处理响应：

```go
package main

import (
  "fmt"
  "net/http"
)

func main(){
  resp, err := http.Get("http://example.com/")
  if err != nil {
    fmt.Println(err)
    return
  }
  fmt.Println(resp)
}
```

### 给函数返回自定义的错误类型

当我们编写自己的函数时，有些情况下我们会遇到错误。可以在错误对象的帮助下返回这些错误：

```go
func Increment(n int) (int, error) {
  if n < 0 {
    // return error object
    return nil, errors.New("math: cannot process negative number")
  }
  return (n + 1), nil
}
func main() {
  num := 5
 
  if inc, err := Increment(num); err != nil {
    fmt.Printf("Failed Number: %v, error message: %v", num, err)
  }else {
    fmt.Printf("Incremented Number: %v", inc)
  }
}
```

使用Go构建的大多数软件包或我们使用的外部软件包都有一种错误处理机制。所以我们调用的任何函数都可能存在错误。这些错误永远不应该被忽略，并且总是在我们调用这些函数的地方优雅地处理，就像我们在上面的例子中所做的那样。

### 恐慌（panic）

`Panic`是在程序执行期间突然发生的未经处理的异常。在Go中，panic不是处理程序中异常的理想方式，建议使用错误对象。发生panic时，程序执行停止。panic之后执行的事情就是defer。

### 延迟（defer）

Defer总是在函数结束时执行。

```go
//Go
package main

import "fmt"

func main() {
    f()
    fmt.Println("Returned normally from f.")
}

func f() {
    defer func() {
        if r := recover(); r != nil {
            fmt.Println("Recovered in f", r)
        }
    }()
    fmt.Println("Calling g.")
    g(0)
    fmt.Println("Returned normally from g.")
}

func g(i int) {
    if i > 3 {
        fmt.Println("Panicking!")
        panic(fmt.Sprintf("%v", i))
    }
    defer fmt.Println("Defer in g", i)
    fmt.Println("Printing in g", i)
    g(i + 1)
}
```

在上面的例子中，我们使用`panic()`在执行程序时制造一个`panic`。正如您所注意到的，有一个延迟语句，它将使程序在程序执行结束时执行该行。当我们需要在函数末尾执行某些操作时，也可以使用Defer，例如关闭文件。

## 并发（Concurrency）

Go是建立在并发性的基础上的。Go中的并发可以通过轻量级线程的Go routines（协程）来实现。

### 协程（routine）

Go routine 是可以与另一个函数并行或同时运行的函数。创建一个Go routine很简单，简单到只需要在函数名前面加一个关键字`go`即可，我们就可以让这个函数并行执行。Go routines是非常轻量级的，所有我们可以创建成千上万的。让我们来看一个简单的示例：

```go
package main
import (
  "fmt"
  "time"
)
func main() {
  go c()
  fmt.Println("I am main")
  time.Sleep(time.Second * 2)
}
func c() {
  time.Sleep(time.Second * 2)
  fmt.Println("I am concurrent")
}
//=> I am main
//=> I am concurrent
```

正如您在上面的示例中看到的那样，函数c是一个Go routine并且它并行的执行在Go的主线程中。有时我们想要在多个线程之间共享资源，Go更喜欢不与另一个线程共享变量，因为这会增加死锁和资源等待的可能性，还有另一种在Go routine之间共享资源的方法：通过 Go 中的 `channels`。

### 通道（Channels）

我们可以使用`Channels`在两个Go协程之间传递数据。在创建Channel时，必须指定Channels接收的数据类型。

让我们创建一个字符串类型的简单Channel，如下所示：

```go
c := make(chan string)
```

使用这个Channel，我们可以发送字符串类型数据，并且我们可以同时在此channel中发送和接收数据：

```go
package main

import "fmt"

func main(){
  c := make(chan string)
  go func(){ c <- "hello" }()
  msg := <-c
  fmt.Println(msg)
}
//=>"hello"
```

接收方的channel等待直到发送方的channel发送数据。

### 单向的通道（One Way Channel）

在某些情况下，我们希望Go routine通过channel接收数据但不发送数据，反之亦然。为此，我们还可以创建单向的channel。

```go

package main

import (
 "fmt"
)

func main() {
 ch := make(chan string)
 
 go sc(ch)
 fmt.Println(<-ch)
}

func sc(ch chan<- string) {
 ch <- "hello"
}
```

在上面的例子中，sc是一个Go routine，它只能向channel发送消息但不能接收消息。

### 使用select为Go routine组织多个channel

函数可能有多个channel正在等待。为此，我们可以使用select语句。让我们看一个更清晰的例子：

```go
package main

import (
 "fmt"
 "time"
)

func main() {
 c1 := make(chan string)
 c2 := make(chan string)
 go speed1(c1)
 go speed2(c2)
 fmt.Println("The first to arrive is:")
 select {
 case s1 := <-c1:
  fmt.Println(s1)
 case s2 := <-c2:
  fmt.Println(s2)
 }
}

func speed1(ch chan string) {
 time.Sleep(2 * time.Second)
 ch <- "speed 1"
}

func speed2(ch chan string) {
 time.Sleep(1 * time.Second)
 ch <- "speed 2"
}
```

在上面这个列子中，在主线程中有两个等待的channels，c1和c2。在主函数中使用`select case`打印从通道中发送的消息，无论先收到谁。

### 带缓冲的通道（Buffered channel）

有些情况下我们需要向通道发送多个数据。您可以为此创建缓冲通道。使用缓冲通道，接收器在缓冲区已满之前不会收到消息。让我们来看看这个例子：

```go
package main

import "fmt"

func main(){
  ch := make(chan string, 2)
  ch <- "hello"
  ch <- "world"
  fmt.Println(<-ch)
}
```

## Great!

我们了解了Go的一些主要组件和功能。

1. Variables, Datatypes
2. Array slices and maps
3. Functions
4. Looping and conditional statements
5. Pointers
6. Packages
7. Method, Structs, and Interfaces
8. Error Handling
9. Concurrency — Go routines and channels





