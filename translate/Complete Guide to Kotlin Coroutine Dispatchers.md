---
title: "Complete Guide to Kotlin Coroutine Dispatchers"
source: "https://proandroiddev.com/complete-guide-to-kotlin-coroutine-dispatchers-38267cd295c8"
---

# Complete Guide to Kotlin Coroutine Dispatchers Kotlin 协程调度器完全指南

## Introduction 介绍

Coroutine dispatchers are fundamental components in Kotlin’s coroutines framework that determine which thread or threads a coroutine uses for its execution. Understanding dispatchers is crucial for writing efficient, responsive, and well-structured concurrent code.  
协程调度器是 Kotlin 协程框架中的基础组件，决定协程在执行时使用哪个线程或哪些线程。理解调度器对于编写高效、响应迅速且结构良好的并发代码至关重要。

## What is a CoroutineDispatcher? 什么是 CoroutineDispatcher？

A `CoroutineDispatcher` is a service that determines which thread or threads a coroutine runs on. It’s part of the coroutine context and controls coroutine execution by dispatching coroutines to appropriate threads from a thread pool.  
`CoroutineDispatcher` 是一种服务，它决定协程在哪个线程或哪些线程上运行。它是协程上下文的一部分，通过将协程从线程池调度到合适的线程来控制协程的执行。

![](https://miro.medium.com/v2/resize:fit:640/format:webp/0*4YCEFv_7W2KGKc7D.png)

## The Four Main Dispatchers 四个主要的调度器

Kotlin provides four built-in dispatchers through the `Dispatchers` object, each optimized for different use cases.  
Kotlin 通过 `Dispatchers` 对象提供了四个内置调度器，每个都针对不同的用例进行了优化。

## 1\. Dispatchers.Default

**Purpose**: CPU- intensive computations  
用途：CPU 密集型计算

The Default dispatcher is backed by a shared pool of threads whose size equals the number of CPU cores (with a minimum of 2). It’s optimized for CPU-bound work that doesn’t block threads.  
Default 调度器由一个共享线程池提供支持，线程数量等于 CPU 核心数（最少为 2）。它针对不阻塞线程的 CPU 密集型工作进行了优化。

**Use Cases**: 使用场景：

- Complex calculations  复杂计算
- Data processing  数据处理
- Sorting large collections  对大型集合进行排序
- Image manipulation  图像处理
- JSON parsing  JSON 解析

**Example**: 示例：

```c
launch(Dispatchers.Default) {
    val result = performHeavyComputation()
    println(”Computation complete: $result”)
}
```
![](https://miro.medium.com/v2/resize:fit:640/format:webp/0*RwZRtuQNmGoejzas.png)

**Thread Pool Size**: Defaults to the number of CPU cores, configurable via system property `kotlinx.coroutines.default.parallelism`.  
线程池大小：默认为 CPU 内核数，可通过系统属性 `kotlinx.coroutines.default.parallelism` 配置。

## 2\. Dispatchers.IO

**Purpose**: I/O operations and blocking tasks  
目的：I/O 操作和阻塞任务

The IO dispatcher is designed for offloading blocking I/O operations to a shared pool of threads. It has elastic scaling capabilities and can create additional threads on demand.  
IO 调度器用于将阻塞性 I/O 操作卸载到一个共享的线程池。它具有弹性扩展能力，能够根据需要创建额外的线程。

**Use Cases**:使用场景：

- Network requests  网络请求
- Database operations  数据库操作
- File I/O  文件输入/输出
- Blocking API calls  阻塞的 API 调用
- Reading/writing to disk   读写磁盘

**Example**:

```c
withContext(Dispatchers.IO) {
    val data = database.query()
    val file = File(”output.txt”).readText()
}
```
![](https://miro.medium.com/v2/resize:fit:640/format:webp/0*Gf-3LHuBoyPzPDzP.png)

**Key Features**: 主要特性：

- Default parallelism: 64 threads or number of CPU cores (whichever is larger)  
	默认并行度：64 线程或 CPU 核心数（以较大者为准）
- Configurable via `kotlinx.coroutines.io.parallelism` system property  
	可通过 `kotlinx.coroutines.io.parallelism` 系统属性配置
- Shares threads with Dispatchers.Default  
	与 Dispatchers.Default 共享线程
- Elastic: can exceed default parallelism when using `limitedParallelism()`  
	弹性：在使用 `limitedParallelism()` 时可超过默认并行度

## 3\. Dispatchers.Main

**Purpose**: UI operations (Android, JavaFX, Swing)  
目的：UI 操作（Android、JavaFX、Swing）

The Main dispatcher is confined to the main/UI thread. It’s primarily used in UI applications where updates must occur on the main thread.  
Main 调度器限定在主/UI 线程。它主要用于需要在主线程上进行更新的 UI 应用中。

**Use Cases**: 使用场景：

- Updating UI components  更新 UI 组件
- Handling user interactions  处理用户交互
- Animation updates  动画更新
- View modifications  查看修改

**Example (Android)**:

```c
launch(Dispatchers.Main) {
    val data = withContext(Dispatchers.IO) {
        fetchDataFromNetwork()
    }
    textView.text = data // Update UI on Main thread
}
```
![](https://miro.medium.com/v2/resize:fit:640/format:webp/0*lYhhWKwlVyVVyayh.png)

**Platform- Specific**: 特定于平台的：

- Android: Uses the UI thread looper  
	Android：使用 UI 线程的 looper
- JavaFX: Uses JavaFX Application thread  
	JavaFX：使用 JavaFX 应用线程
- Swing: Uses Swing EDT (Event Dispatch Thread)  
	Swing：使用 Swing EDT（事件分发线程）

## 4\. Dispatchers.Unconfined

**Purpose**: Special dispatcher that doesn’t confine coroutine execution  
用途：一种特殊的调度器，不会约束协程的执行线程

The Unconfined dispatcher starts coroutine execution in the caller thread, but only until the first suspension point. After suspension, it resumes in whatever thread the suspending function resumed in.  
Unconfined 调度器在调用线程启动协程的执行，但仅持续到第一个挂起点。挂起后，它会在挂起函数恢复时所使用的线程上继续执行。

**Use Cases**: 使用场景：

- Advanced scenarios requiring specific threading behavior  
	需要特定线程行为的高级场景
- Performance- critical code where thread switching overhead matters  
	对性能非常敏感、线程切换开销重要的代码
- Testing scenarios 测试场景

**Example**:

```c
launch(Dispatchers.Unconfined) {
    println(”Thread 1: ${Thread.currentThread().name}”)
    delay(100)
    println(”Thread 2: ${Thread.currentThread().name}”) // Likely different!
}
```
![](https://miro.medium.com/v2/resize:fit:640/format:webp/0*btI9DBzjdtWNoD1D.png)

**Warning**: Not recommended for general use. Can lead to unpredictable threading behavior and stack overflow in certain cases.  
警告：不推荐一般性使用。在某些情况下可能导致不可预测的线程行为和栈溢出。

## Thread Sharing Between Dispatchers 调度器之间的线程共享

One of the key implementation details is that Dispatchers.Default and Dispatchers.IO share threads for efficiency.  
实现细节的一个关键点是 Dispatchers.Default 和 Dispatchers.IO 为了效率而共享线程。

![](https://miro.medium.com/v2/resize:fit:640/format:webp/0*MUx01Vn_Zuskw7Od.png)

This means switching from Default to IO context often doesn’t result in actual thread switching, which is an optimization for performance.  
这意味着从 Default 切换到 IO 上下文通常不会导致实际的线程切换，这是一种用于提升性能的优化。

## Advanced: limitedParallelism()

The `limitedParallelism()` extension function creates a view of a dispatcher with limited parallelism, useful for resource- constrained operations.  
`limitedParallelism()` 扩展函数创建了一个并行度受限的调度器视图，适用于受资源限制的操作。

```c
// Create a dispatcher limited to 100 threads for MySQL
val mysqlDispatcher = Dispatchers.IO.limitedParallelism(100)

// Create a dispatcher limited to 60 threads for MongoDB
val mongoDbDispatcher = Dispatchers.IO.limitedParallelism(60)
// These share resources with Dispatchers.IO but have their own limits
launch(mysqlDispatcher) {
    // MySQL operations with up to 100 concurrent threads
}
```
![](https://miro.medium.com/v2/resize:fit:640/format:webp/0*M4a2O6RxSv2rfnav.png)

## Elasticity Property 弹性特性

Dispatchers.IO has a unique elasticity property: views created with `limitedParallelism()` are not restricted by the IO dispatcher’s default parallelism limit. This allows for fine- grained control over resource allocation while still sharing the underlying thread pool.  
Dispatchers.IO 具有独特的弹性属性：用 `limitedParallelism()` 创建的视图不受 IO 调度器默认并行度限制的约束。这允许在仍然共享底层线程池的同时对资源分配进行细粒度控制。

## Dispatcher Selection Decision Tree 调度器选择决策树

![](https://miro.medium.com/v2/resize:fit:640/format:webp/0*CBLC9F7TfBei9vcT.png)

## Best Practices 最佳实践

## 1\. Choose the Right Dispatcher 1. 选择合适的调度器

```c
// ❌ Wrong: CPU-intensive work on IO
launch(Dispatchers.IO) {
    val result = (1..1000000).map { it * it }.sum()
}

// ✅ Correct: CPU-intensive work on Default
launch(Dispatchers.Default) {
    val result = (1..1000000).map { it * it }.sum()
}
// ❌ Wrong: Blocking I/O on Default
launch(Dispatchers.Default) {
    val file = File("large.txt").readText()
}
// ✅ Correct: Blocking I/O on IO
launch(Dispatchers.IO) {
    val file = File("large.txt").readText()
}
```

## 2\. Minimize Dispatcher Switching 2. 将调度程序切换降到最低

```c
// ❌ Inefficient: Multiple context switches
suspend fun loadData() = withContext(Dispatchers.IO) {
    val data1 = withContext(Dispatchers.Default) { 
        process1() 
    }
    val data2 = withContext(Dispatchers.Default) { 
        process2() 
    }
    combine(data1, data2)
}
// ✅ Better: Batch context switches
suspend fun loadData() = withContext(Dispatchers.IO) {
    val processedData = withContext(Dispatchers.Default) {
        val data1 = process1()
        val data2 = process2()
        listOf(data1, data2)
    }
    combine(processedData[0], processedData[1])
}
```

## 3\. Use limitedParallelism for Resource Control 3. 使用 limitedParallelism 控制资源

```c
class DatabaseManager {
    // Limit concurrent database connections
    private val dbDispatcher = Dispatchers.IO.limitedParallelism(10)
    
    suspend fun query(sql: String) = withContext(dbDispatcher) {
        // Only 10 concurrent queries allowed
        database.execute(sql)
    }
}
```

## 4\. Don’t Block Dispatchers.Default 4. 不要阻塞 Dispatchers.Default

```c
// ❌ Wrong: Blocking Default dispatcher
launch(Dispatchers.Default) {
    Thread.sleep(1000) // Blocks a worker thread!
}
// ✅ Correct: Use delay or move to IO
launch(Dispatchers.Default) {
    delay(1000) // Suspends without blocking
}
// Or for actual blocking:
launch(Dispatchers.IO) {
    Thread.sleep(1000) // OK on IO dispatcher
}
```

## Dispatcher Lifecycle  Dispatcher 生命周期

![](https://miro.medium.com/v2/resize:fit:640/format:webp/0*d-zHP-jmK5svjx1F.png)

## Shutdown 关闭

The `Dispatchers.shutdown()` function is a delicate API that stops all built-in dispatchers:  
`Dispatchers.shutdown()` 函数是一个非常敏感的 API，它会停止所有内置的调度器：

```c
@DelicateCoroutinesApi
Dispatchers.shutdown()
```

**Important**:重要：

- Irreversible operation 不可逆的操作
- Should only be called when no coroutines are running  
	仅在没有协程运行时调用
- Primarily for containerized environments (OSGi, IDE plugins)  
	主要用于容器化环境（OSGi、IDE 插件）
- Makes coroutines framework inoperable  
	使协程框架无法运行
- Enables proper class unloading by JVM  
	使 JVM 能正确卸载类

## Performance Comparison 性能比较

![](https://miro.medium.com/v2/resize:fit:640/format:webp/0*4DQgtePpkNm0a_Ex.png)

## Common Patterns 常见模式

## Pattern 1: Background Work with UI Update模式 1：带有 UI 更新的后台工作

```c
launch {
    val result = withContext(Dispatchers.IO) {
        // Network or database operation
        fetchDataFromServer()
    }
    // Automatically back on the original context (often Main)
    updateUI(result)
}
```
![](https://miro.medium.com/v2/resize:fit:640/format:webp/0*tveMMrVjz0RGUfSx.png)

## Pattern 2: Parallel Decomposition模式 2：并行分解

```c
suspend fun loadDashboard() = coroutineScope {
    val userData = async(Dispatchers.IO) { fetchUserData() }
    val stats = async(Dispatchers.IO) { fetchStatistics() }
    val notifications = async(Dispatchers.IO) { fetchNotifications() }
    
    Dashboard(
        user = userData.await(),
        stats = stats.await(),
        notifications = notifications.await()
    )
}
```
![](https://miro.medium.com/v2/resize:fit:640/format:webp/0*9uAKnO4tglnniLBI.png)

## Pattern 3: Resource-Specific Dispatchers模式 3：资源特定的调度器

```c
class ApiClient {
    private val networkDispatcher = Dispatchers.IO.limitedParallelism(50)
    
    suspend fun makeRequest(url: String) = withContext(networkDispatcher) {
        // Limited to 50 concurrent network requests
        httpClient.get(url)
    }
}
class ImageProcessor {
    private val processingDispatcher = Dispatchers.Default.limitedParallelism(4)
    
    suspend fun processImage(image: Bitmap) = withContext(processingDispatcher) {
        // Limited to 4 concurrent image processing tasks
        applyFilters(image)
    }
}
```

## Testing with Dispatchers 使用调度器进行测试

```c
// Use TestDispatcher for testing
@Test
fun testCoroutine() = runTest {
    val dispatcher = StandardTestDispatcher()
    
    launch(dispatcher) {
        // Test code
    }
    
    advanceUntilIdle() // Execute all pending coroutines
}
```

## Conclusion 结论

Understanding Kotlin coroutine dispatchers is essential for writing efficient concurrent code. Key takeaways:  
理解 Kotlin 协程调度器对于编写高效的并发代码至关重要。要点如下：

1. **Dispatchers.Default** for CPU- intensive work  
	Dispatchers.Default 用于 CPU 密集型工作
2. **Dispatchers.IO** for blocking I/O operations  
	Dispatchers.IO 用于阻塞的 I/O 操作
3. **Dispatchers.Main** for UI updates  
	Dispatchers.Main 用于 UI 更新
4. **Dispatchers.Unconfined** for advanced scenarios (use sparingly)  
	Dispatchers.Unconfined 用于高级场景（谨慎使用）
5. Use `limitedParallelism()` for fine- grained resource control  
	对细粒度资源控制使用 `limitedParallelism()`
6. Minimize unnecessary dispatcher switching  
	尽量减少不必要的调度器切换
7. Never block Dispatchers.Default threads  
	切勿阻塞 Dispatchers.Default 线程
8. Choose dispatchers based on the nature of your work, not arbitrary preference  
	根据任务性质选择调度器，而非随意偏好

By following these guidelines and understanding the threading model, you can build responsive, efficient, and maintainable coroutine-based applications.  
通过遵循这些指导原则并理解线程模型，你可以构建响应迅速、高效且易于维护的基于协程的应用程序。