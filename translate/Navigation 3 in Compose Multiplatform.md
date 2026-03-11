---
title: "Navigation 3 in Compose Multiplatform | Kotlin Multiplatform"
source: "https://kotlinlang.org/docs/multiplatform/compose-navigation-3.html#recommended-serialization-approaches"
created: 2026-03-11
## Navigation 3 in Compose Multiplatform Compose Multiplatform 中的 Navigation 3

03 March 2026

[Android's Navigation library](https://developer.android.com/guide/navigation) has been upgraded to Navigation 3, introducing a redesigned approach to navigation that works with Compose and takes into account feedback to the previous version of the library. Starting with version 1.10, Compose Multiplatform supports adopting Navigation 3 in multiplatform projects for all supported platforms: Android, iOS, desktop, and web.  
Android 的 Navigation 库已升级至 Navigation 3，引入了适用于 Compose 的重构导航方法，并考虑了先前版本的库的反馈。从 1.10 版本开始，Compose Multiplatform 支持在跨平台项目中采用 Navigation 3，适用于所有支持的平台：Android、iOS、桌面和 Web。

## Key changes 关键变更

Navigation 3 is more than a new version of the library — in a lot of ways it's a new library entirely. To learn more about the philosophy behind this redesign, see the [Android Developers blog post](https://android-developers.googleblog.com/2025/05/announcing-jetpack-navigation-3-for-compose.html).  
Navigation 3 不仅仅是一个新版本的库——在很多方面，它完全是一个全新的库。要了解更多关于这次重新设计的理念，请查看 Android Developers 的博客文章。

Key changes in Navigation 3 include:  
Navigation 3 中的主要变化包括：

- User-owned back stack. Instead of operating a single library back stack, you create and manage a `SnapshotStateList` of states, which the UI observes directly.  
	用户拥有的后堆栈。您不是操作单个库的后堆栈，而是创建和管理一组状态，UI 直接观察这些状态。
- Low-level building blocks. Thanks to closer integration with Compose, the library allows more flexibility in implementing your own navigation components and behavior.  
	底层的构建模块。得益于与 Compose 的紧密集成，该库允许在实现您自己的导航组件和行为时具有更高的灵活性。
- Adaptive layout system. With adaptive design, you can display multiple destinations at the same time and seamlessly switch between layouts.  
	自适应布局系统。通过自适应设计，您可以同时显示多个目的地，并无缝切换布局。

Learn more about general design of Navigation 3 in [Android documentation](https://developer.android.com/guide/navigation/navigation-3).  
在 Android 文档中了解更多关于 Navigation 3 的总体设计。

## Dependencies setup 依赖项设置

To try out the multiplatform implementation of Navigation 3, add the following dependency to your version catalog:  
要尝试 Navigation 3 的多平台实现，将以下依赖项添加到您的版本目录中：

> ### note
> 
> While Navigation 3 is released as two artifacts, `navigation3:navigation3-ui` and `navigation3:navigation3-common`, only `navigation3-ui` has a separate Compose Multiplatform implementation. A dependency on `navigation3-common` is added transitively.  
> 虽然 Navigation 3 以两个组件发布， `navigation3:navigation3-ui` 和 `navigation3:navigation3-common` ，但只有 `navigation3-ui` 有独立的 Compose Multiplatform 实现。对 `navigation3-common` 的依赖是传递性的。

For projects using the Material 3 Adaptive and ViewModel libraries, also add the following navigation support artifacts:  
对于使用 Material 3 Adaptive 和 ViewModel 库的项目，还需添加以下导航支持组件：

Finally, you can try out the [proof -of- concept library](https://github.com/terrakok/navigation3-browser) created by a JetBrains engineer. The library integrates the multiplatform Navigation 3 with browser history navigation on the web:  
最后，你可以尝试由一位 JetBrains 工程师创建的概念验证库。该库将跨平台 Navigation 3 与网页上的浏览器历史导航集成：

Browser history navigation is expected to be supported by the base multiplatform Navigation 3 library in version 1.1.0.  
浏览器历史记录导航预计将在 1.1.0 版本的 Compose Multiplatform 基础多平台 Navigation 3 库中得到支持。

## Multiplatform support 多平台支持

Navigation 3 is closely aligned with Compose, allowing an Android navigation implementation to work in shared Compose Multiplatform code with minimal changes. To support non-JVM platforms like web and iOS, you need to implement [polymorphic serialization for destination keys](https://kotlinlang.org/docs/multiplatform/compose-navigation-3.html#polymorphic-serialization-for-destination-keys).  
Navigation 3 与 Compose 紧密集成，允许 Android 导航实现以最小的改动在共享的 Compose Multiplatform 代码中工作。为了支持非 JVM 平台（如 Web 和 iOS），你需要为目的地键实现多态序列化。

You can compare extensive examples of Android-only and multiplatform apps using Navigation 3 on GitHub:  
你可以在 GitHub 上比较使用 Navigation 3 的仅 Android 和多平台应用的广泛示例：

- [original Android repository with Navigation 3 recipes  
	原始 Android 仓库中的 Navigation 3 实例](https://github.com/android/nav3-recipes)
- [Compose Multiplatform project with most of the same recipes  
	Compose Multiplatform 项目使用大部分相同的配方](https://github.com/terrakok/nav3-recipes)

### Polymorphic serialization for destination keys多态序列化用于目标键

On Android, Navigation 3 relies on reflection-based serialization, which is not available when you target non-JVM platforms like iOS. To address this limitation, the library has two overloads for the `rememberNavBackStack()` function:  
在 Android 上，Navigation 3 依赖于基于反射的序列化，而在 iOS 等非 JVM 平台上不可用。为了解决这个限制，该库为 `rememberNavBackStack()` 函数提供了两个重载版本：

- [The first overload](https://developer.android.com/reference/kotlin/androidx/navigation3/runtime/package-summary#rememberNavBackStack\(kotlin.Array\)) only takes a set of `NavKey` references and requires a reflection-based serializer.  
	第一个重载只接受一组 `NavKey` 引用，并且需要一个基于反射的序列化器。
- [The second overload](https://developer.android.com/reference/kotlin/androidx/navigation3/runtime/package-summary#rememberNavBackStack\(androidx.savedstate.serialization.SavedStateConfiguration,kotlin.Array\)) also takes a `SavedStateConfiguration` parameter that allows you to provide a `SerializersModule` and handle open polymorphism across all platforms.  
	第二个重载也接受一个 `SavedStateConfiguration` 参数，允许你提供 `SerializersModule` 并处理跨所有平台的开放多态。

The Navigation 3 [multiplatform examples](https://github.com/terrakok/nav3-recipes/blob/8ff455499877225b638d5fcd82b232834f819422/sharedUI/src/commonMain/kotlin/com/example/nav3recipes/basicdsl/BasicDslActivity.kt#L40) define routes and register them with a `SavedStateConfiguration`, as shown below:  
Navigation 3 多平台示例定义了路由，并使用 `SavedStateConfiguration` 注册它们，如下所示：

### Recommended serialization approaches推荐的序列化方法

When implementing multiplatform navigation, you'll need to choose how to organize and serialize your route definitions. Depending on your project's complexity and modularization, use one of the following three patterns.  
在实现跨平台导航时，你需要选择如何组织和序列化你的路由定义。根据你项目的复杂性和模块化程度，使用以下三种模式中的一种。

#### Single module with sealed type单一模块与密封类型

For small projects where all routes exist in one module, use a `sealed interface`. This is the most straightforward approach as Kotlin serialization handles the hierarchy automatically:  
对于所有路由都存在于一个模块的小型项目，使用 `sealed interface` 。这是最直接的方法，因为 Kotlin 序列化会自动处理层次结构：

Alternatively, if you want to use the `rememberNavBackStack()` function explicitly, here's a slightly different configuration:  
或者，如果你想显式使用 `rememberNavBackStack()` 函数，这里有一个稍微不同的配置：

#### Multi-module with aggregated sealed types多模块聚合密封类型

For more complex projects with routes defined in multiple modules, you can define a sealed type for each module. Then, aggregate their serializers in the `app` module using the `subclassesOfSealed()` function.  
对于包含在多个模块中定义路由的更复杂项目，您可以为每个模块定义一个密封类型。然后，在 `app` 模块中使用 `subclassesOfSealed()` 函数聚合它们的序列化器。

With Dependency Injection (DI), you can also use DI containers to collect serializers for sealed types from each module into a `Set<KSerializer>` dynamically.  
使用依赖注入（DI），您还可以使用 DI 容器从每个模块中收集密封类型的序列化器，并将它们收集到一个 `Set<KSerializer>` 动态中。

#### Multi-module with individual route registration多模块，单独路由注册

If your routes cannot be grouped into sealed types, you can manually combine `SerializersModule` instances from different modules.  
如果你的路由不能被组合成密封类型，你可以手动从不同模块组合 `SerializersModule` 实例。

This approach offers a high level of flexibility and decoupling, though it requires more manual maintenance. Similar to the [multi-module with aggregated sealed types](https://kotlinlang.org/docs/multiplatform/compose-navigation-3.html#multi-module-with-aggregated-sealed-types) approach, you can use DI to assemble the list of serializers dynamically, which can improve flexibility.  
这种方法提供了高度的灵活性和解耦，但它需要更多的手动维护。类似于使用聚合密封类型的多模块方法，你可以使用依赖注入来动态组装序列化器的列表，这可以提高灵活性。

## What's next 接下来是什么

Navigation 3 is covered in- depth on the Android Developer portal. While some of the documentation uses Android- specific examples, the core concepts and navigation principles remain consistent across all platforms:  
Navigation 3 在 Android 开发者门户中有详细的介绍。虽然部分文档使用 Android 特定的示例，但核心概念和导航原则在所有平台上都是一致的：

- [Overview of Navigation 3](https://developer.android.com/guide/navigation/navigation-3) with advice on managing state, modularizing navigation code, and animation.  
	Navigation 3 概述，包含关于管理状态、模块化导航代码和动画的建议。
- [Migration from Navigation 2 to Navigation 3](https://developer.android.com/guide/navigation/navigation-3/migration-guide). It's easier to see Navigation 3 as a new library than a new version of the existing library, so it's less of a migration and more of a rewrite. But the guide points out the general steps to take.  
	从 Navigation 2 迁移到 Navigation 3。将 Navigation 3 视为一个新库比将其视为现有库的新版本更容易，因此迁移过程更多的是重写而非简单的迁移。但指南指出了需要采取的一般步骤。

Thanks for your feedback!

Was this page helpful?