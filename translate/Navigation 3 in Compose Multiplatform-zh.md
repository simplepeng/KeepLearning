## Compose Multiplatform 中的 Navigation 3

[Android 的 Navigation 库](https://developer.android.com/guide/navigation)已升级至 Navigation 3，引入了适用于 Compose 的重构导航方法，并考虑了先前版本的库的反馈。从 1.10 版本开始，Compose Multiplatform 支持在跨平台项目中采用 Navigation 3，适用于所有支持的平台：Android、iOS、桌面和 Web。

## 关键变更

Navigation 3 不仅仅是一个新版本的库——在很多方面，它完全是一个全新的库。要了解更多关于这次重新设计的理念，请查看 [Android Developers 的博客文章](https://android-developers.googleblog.com/2025/05/announcing-jetpack-navigation-3-for-compose.html)。

Navigation 3 中的主要变化包括：

* 用户拥有的后堆栈。您不是操作单个库的后堆栈，而是创建和管理一组状态，UI 直接观察这些状态。
* 底层的构建模块。得益于与 Compose 的紧密集成，该库允许在实现您自己的导航组件和行为时具有更高的灵活性。
* 自适应布局系统。通过自适应设计，您可以同时显示多个目的地，并无缝切换布局。

在 [Android 文档](https://developer.android.com/guide/navigation/navigation-3)中了解更多关于 Navigation 3 的总体设计。

## 依赖项设置

要尝试 Navigation 3 的多平台实现，将以下依赖项添加到您的版本目录中：

```toml
[versions]
multiplatform-nav3-ui = "1.0.0-alpha05"

[libraries]
jetbrains-navigation3-ui = { module = "org.jetbrains.androidx.navigation3:navigation3-ui", version.ref = "multiplatform-nav3-ui" }
```

> 虽然 Navigation 3 以两个组件发布， `navigation3:navigation3-ui` 和 `navigation3:navigation3-common` ，但只有 `navigation3-ui` 有独立的 Compose Multiplatform 实现。对 `navigation3-common` 的依赖是传递性的。

 对于使用 Material 3 Adaptive 和 ViewModel 库的项目，还需添加以下导航支持组件：

```toml
[versions]
compose-multiplatform-adaptive = "1.3.0-alpha02"
compose-multiplatform-lifecycle = "2.10.0-alpha05"

[libraries]
jetbrains-material3-adaptiveNavigation3 = { module = "org.jetbrains.compose.material3.adaptive:adaptive-navigation3", version.ref = "compose-multiplatform-adaptive" }
jetbrains-lifecycle-viewmodelNavigation3 = { module = "org.jetbrains.androidx.lifecycle:lifecycle-viewmodel-navigation3", version.ref = "compose-multiplatform-lifecycle" }
```

 最后，你可以尝试由一位 JetBrains 工程师创建的概念验证库。该库将跨平台 Navigation 3 与网页上的浏览器历史导航集成：

```toml
[versions]
compose-multiplatform-navigation3-browser = "0.2.0"

[libraries]
navigation3-browser = { module = "com.github.terrakok:navigation3-browser", version.ref = "compose-multiplatform-navigation3-browser" }
```

浏览器历史记录导航预计将在 1.1.0 版本的 Compose Multiplatform 基础多平台 Navigation 3 库中得到支持。

## 多平台支持

Navigation 3 与 Compose 紧密集成，允许 Android 导航实现以最小的改动在共享的 Compose Multiplatform 代码中工作。为了支持非 JVM 平台（如 Web 和 iOS），你需要为目的地键实现多态序列化。

你可以在 GitHub 上比较使用 Navigation 3 的仅 Android 和多平台应用的广泛示例：

- [原始 Android 仓库中的 Navigation 3 实例](https://github.com/android/nav3-recipes)
- [Compose Multiplatform 项目使用大部分相同的配方](https://github.com/terrakok/nav3-recipes)

### 多态序列化用于目标键

在 Android 上，Navigation 3 依赖于基于反射的序列化，而在 iOS 等非 JVM 平台上不可用。为了解决这个限制，该库为 `rememberNavBackStack()` 函数提供了两个重载版本：

- 第一个重载只接受一组 `NavKey` 引用，并且需要一个基于反射的序列化器。
- 第二个重载也接受一个 `SavedStateConfiguration` 参数，允许你提供 `SerializersModule` 并处理跨所有平台的开放多态。

Navigation 3 多平台示例定义了路由，并使用 `SavedStateConfiguration` 注册它们，如下所示：

```kotlin
@Serializable
private data object RouteA : NavKey

@Serializable
private data class RouteB(val id: String) : NavKey

// Creates the required serialization configuration for open polymorphism
private val config = SavedStateConfiguration {
    serializersModule = SerializersModule {
        polymorphic(NavKey::class) {
            subclass(RouteA::class, RouteA.serializer())
            subclass(RouteB::class, RouteB.serializer())
        }
    }
}

@Composable
fun BasicDslActivity() {
    // Consumes the serialization configuration
    val backStack = rememberNavBackStack(config, RouteA)

    NavDisplay(
        backStack = backStack,
        //...
    )
}
```

### 推荐的序列化方法

 在实现跨平台导航时，你需要选择如何组织和序列化你的路由定义。根据你项目的复杂性和模块化程度，使用以下三种模式中的一种。

#### 单一模块与密封类型

对于所有路由都存在于一个模块的小型项目，使用 `sealed interface` 。这是最直接的方法，因为 Kotlin 序列化会自动处理层次结构：

```kotlin
@Serializable
sealed interface Route : NavKey

@Serializable
data object RouteA : Route

@Serializable
data class RouteB(val id: String) : Route

// Backstack with default serializer
val backStack: MutableList<Route> =
    rememberSerializable(serializer = SnapshotStateListSerializer()) {
        mutableStateListOf(RouteA)
    }
```

 或者，如果你想显式使用 `rememberNavBackStack()` 函数，这里有一个稍微不同的配置：

```kotlin
private val config = SavedStateConfiguration {
    serializersModule = SerializersModule {
        polymorphic(NavKey::class) {
            subclassesOfSealed<Route>()
        }
    }
}
val backStack = rememberNavBackStack(config, RouteA)
```

#### 多模块聚合密封类型

对于包含在多个模块中定义路由的更复杂项目，您可以为每个模块定义一个密封类型。然后，在 `app` 模块中使用 `subclassesOfSealed()` 函数聚合它们的序列化器。

```kotlin
// Module A
@Serializable sealed interface FeatureA : NavKey
@Serializable data object RouteA1 : FeatureA
@Serializable data object RouteA2 : FeatureA

// Module B
@Serializable sealed interface FeatureB : NavKey
@Serializable data class RouteB1(val id: String) : FeatureB
@Serializable data class RouteB2(val id: String) : FeatureB

// Module app
private val config = SavedStateConfiguration {
    serializersModule = SerializersModule {
        polymorphic(NavKey::class) {
            subclassesOfSealed<FeatureA>()
            subclassesOfSealed<FeatureB>()
        }
    }
}
val backStack = rememberNavBackStack(config, RouteA1)
```

 使用依赖注入（DI），您还可以使用 DI 容器从每个模块中收集密封类型的序列化器，并将它们收集到一个 `Set<KSerializer>` 动态中。

#### 多模块，单独路由注册

 如果你的路由不能被组合成密封类型，你可以手动从不同模块组合 `SerializersModule` 实例。

```kotlin
// Module A
@Serializable data object RouteA1 : NavKey
@Serializable data object RouteA2 : NavKey

val serializerModuleA = SerializersModule {
    polymorphic(NavKey::class) {
        subclass(RouteA1::class, RouteA1.serializer())
        subclass(RouteA2::class, RouteA2.serializer())
    }
}

// Module B
@Serializable data class RouteB1(val id: String) : NavKey
@Serializable data class RouteB2(val id: String) : NavKey

val serializerModuleB = SerializersModule {
    polymorphic(NavKey::class) {
        subclass(RouteB1::class, RouteB1.serializer())
        subclass(RouteB2::class, RouteB2.serializer())
    }
}

// Module app
private val config = SavedStateConfiguration {
    serializersModule = serializerModuleA + serializerModuleB
}
val backStack = rememberNavBackStack(config, RouteA1)
```

这种方法提供了高度的灵活性和解耦，但它需要更多的手动维护。类似于使用聚合密封类型的多模块方法，你可以使用依赖注入来动态组装序列化器的列表，这可以提高灵活性。

## 接下来是什么

Navigation 3 在 Android 开发者门户中有详细的介绍。虽然部分文档使用 Android 特定的示例，但核心概念和导航原则在所有平台上都是一致的：

- [Navigation 3 概述](https://developer.android.com/guide/navigation/navigation-3)，包含关于管理状态、模块化导航代码和动画的建议。
- [从 Navigation 2 迁移到 Navigation3](https://developer.android.com/guide/navigation/navigation-3/migration-guide)，将 Navigation 3 视为一个新库比将其视为现有库的新版本更容易，因此迁移过程更多的是重写而非简单的迁移。但指南指出了需要采取的一般步骤。
