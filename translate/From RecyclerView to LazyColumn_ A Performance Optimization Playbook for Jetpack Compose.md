---
title: "From RecyclerView to LazyColumn: A Performance Optimization Playbook for Jetpack Compose"
source: "https://proandroiddev.com/from-recyclerview-to-lazycolumn-a-performance-optimization-playbook-for-jetpack-compose-81aa38dca1bf"
author: Sergey Drymchenko
---
# 从 RecyclerView 到 LazyColumn：Jetpack Compose 性能优化实战手册

When our team made the jump to Jetpack Compose, one thing immediately stood out — the simplicity of handling lists. No more wrestling with complex adapters, tricky cell updates, or manual diffing; just drop your items into a LazyColumn, add keys, and voilà — instant scrolling magic! But, as you might have guessed, reality isn’t always that straightforward. In this article, I’ll share how you can strategically transfer your hard earned RecyclerView optimization expertise directly into LazyColumn, ensuring maximum performance from day one.  
当我们团队迁移到 Jetpack Compose 时，有一件事立刻显得很突出——处理列表的简洁性。不再需要与复杂的 adapter 折腾、处理棘手的单元格更新或手动 diff；只需把你的项放入 LazyColumn，添加 keys，然后瞧——即时流畅滚动的魔法！但正如你可能猜到的，现实并不总是那么简单。在本文中，我将分享如何将你在 RecyclerView 上辛苦积累的优化经验策略性地直接迁移到 LazyColumn 中，从第一天起就确保性能最大化。

So how exactly do RecyclerView’s battle -tested optimizations map onto LazyColumn’s new playing field? Let’s break it down technique by technique, examining what’s directly transferable, what’s improved, and what requires a fresh approach to achieve optimal Compose performance.  
那么，RecyclerView 那些久经考验的优化策略到底如何映射到 LazyColumn 这个新阵地？让我们逐项拆解，检查哪些可以直接迁移、哪些已被改进、以及哪些需要采用新的方法来实现最佳的 Compose 性能。

## Identity & Content Checks: From DiffUtil to Compose Keys and Immutable Models  身份与内容检查：从 DiffUtil 到 Compose 的 key 与不可变模型

In RecyclerView, optimizing the calculation of differences between lists relies heavily on three essential methods:  
在 RecyclerView 中，优化列表差异计算在很大程度上依赖于三个基本方法：

- `areItemsTheSame(oldItem, newItem)` – Checks if two items represent the same logical entity.  
	`areItemsTheSame(oldItem, newItem)` – 检查两个条目是否代表相同的逻辑实体。
- `areContentsTheSame(oldItem, newItem)` – Determines if the item's content has changed, prompting a UI refresh if necessary.  
	`areContentsTheSame(oldItem, newItem)` – 判断条目的内容是否发生变化，如有必要则触发 UI 刷新。
- `detectMoves` – An advanced optimization that speeds up diff calculations, especially beneficial when you know your dataset involves item movements.  
	`detectMoves` – 一种高级优化，加快差异计算速度，尤其在你知道数据集中包含项移动时特别有用。

Jetpack Compose handles these same concepts elegantly. To inform Compose how to efficiently track individual items, you provide a stable key for each one:
Jetpack Compose 以优雅的方式处理了这些相同的概念。为了让 Compose 能够高效地追踪每个独立项，你需要为每一项提供一个稳定的标识键: 

This `key` ensures that Compose can track the identity of items across recompositions - just like `areItemsTheSame`. 
这个 `key` 确保 Compose 能在重组过程中跟踪项的身份 —— 就像 `areItemsTheSame` 一样。

Handling content updates (`areContentsTheSame`) is a bit different in Compose, as it leverages internal recomposition strategies. A good rule of thumb here is to always prefer immutable UI models - achieved easily by using the `@Immutable` annotation or defining data classes with val fields exclusively. Furthermore, starting from Compose compiler 2.x (bundled with Kotlin 2.0.20), Strong Skipping mode is enabled by default, providing automatic optimization and removing the need for manual handling of immutable collections.  
在 Compose 中处理内容更新（ `areContentsTheSame` ）有些不同，因为它利用了内部的重组策略。一个好的经验法则是始终优先使用不可变的 UI 模型 —— 通过使用 `@Immutable` 注解或仅用 val 字段定义数据类可以轻松实现。此外，从随 Kotlin 2.0.20 捆绑的 Compose 编译器 2.x 开始，已默认启用 Strong Skipping 模式，提供自动优化，消除了对不可变集合手动处理的需求。

## Asynchronous Text Layout: From PrecomputedText to TextMeasurer  异步文本布局：从 PrecomputedText 到 TextMeasurer

RecyclerView veterans relied on PrecomputedText to shift expensive text-layout work onto a background thread before the view holder ever appeared on the screen. Jetpack Compose tackles this same challenge effectively through built-in paragraph caching and the TextMeasurer API. Let’s map these familiar techniques onto Compose’s new terrain step by step  
RecyclerView 的老手们依赖 PrecomputedText 将昂贵的文本布局工作转移到后台线程，在视图持有者出现在屏幕之前就完成。Jetpack Compose 通过内置的段落缓存和 TextMeasurer API 有效地应对了同样的挑战。让我们一步步将这些熟悉的技术映射到 Compose 的新领域。

### 1\. Paragraph caching (built-in optimization)  1. 段落缓存（内置优化）

Every time you emit a Text composable, Compose caches a fully- laid -out [Paragraph](https://developer.android.com/reference/kotlin/androidx/compose/ui/text/Paragraph?ref=hackernoon.com) within the current composition. As long as the text content, styling, density, and locale remain unchanged, Compose reuses this cached paragraph, avoiding unnecessary layout computations. This effectively reduces overhead for most intra-viewport updates and provides immediate performance gains without additional effort.  
每次你发出一个 Text 可组合项时，Compose 会在当前组合中缓存一个已完全布局的 Paragraph。只要文本内容、样式、像素密度和区域设置保持不变，Compose 就会重用这个缓存的段落，从而避免不必要的布局计算。这有效地减少了大多数视口内更新的开销，并在无需额外努力的情况下带来即时的性能提升。

### 2\. When it is time for big guns: Using TextMeasurer  2. 到需要大招的时候：使用 TextMeasurer

For heavyweight or complex text scenarios (e.g., long paragraphs, variable fonts, or custom canvas drawing) where even occasional on-scroll layout recalculations are unacceptable, leverage the `TextMeasurer API` \- think of it as the Compose counterpart to `PrecomputedText.create()`.  
对于重量级或复杂的文本场景（例如长段落、可变字体或自定义画布绘制），在这些情况下即使偶尔在滚动时重新计算布局也不可接受，应当使用 `TextMeasurer API` —— 可以把它视为 Compose 中对应于 `PrecomputedText.create()` 的工具。

Benefits of using TextMeasurer:  
使用 TextMeasurer 的好处：

- **Precise Layout Control**: Pre-measuring text off-screen provides exact item heights before composable placement, preventing layout shifts during scrolling.  
	精确的布局控制：在屏幕外预先测量文本可以在可组合项放置之前提供精确的项高度，防止在滚动过程中发生布局位移。
- **Dynamic Overflow Detection**: Access properties like `layoutResult.hasVisualOverflow` to conditionally render UI elements such as "Read more" indicators.  
	动态溢出检测：访问诸如 `layoutResult.hasVisualOverflow` 的属性以有条件地呈现 UI 元素，例如“阅读更多”指示器。
- **Enhanced Scroll Performance**: By knowing exact item dimensions beforehand, `LazyColumn` calculates scroll positions more efficiently, ensuring smoother scrolling.  
	增强的滚动性能：通过事先知道精确的项尺寸， `LazyColumn` 能更高效地计算滚动位置，从而确保更流畅的滚动。

However, introducing `TextMeasurer` increases complexity. You must:  
然而，引入 `TextMeasurer` 会增加复杂性。您必须：

- Manage recomposition carefully, especially during configuration changes (e.g., font scale, screen orientation), requiring items to be re-measured appropriately.  
	谨慎管理重组，尤其是在配置更改（例如字体缩放、屏幕方向）期间，要求对项进行适当的重新测量。
- Implement caching to avoid redundant measurements of identical content, preserving performance.  
	实现缓存以避免对相同内容进行重复测量，从而保持性能。

TextMeasurer is particularly useful for:  
TextMeasurer 对以下情况特别有用：

- Lists with variable-length text content  
	包含可变长度文本内容的列表
- Chat applications or message lists  
	聊天应用或消息列表
- Article or comment feeds 文章或评论提要
- Any scenario where text length significantly varies between items  
	任何文本长度在各项之间显著变化的场景

## Importance of contentType  contentType 的重要性

In RecyclerView, developers utilize view types (`getItemViewType()`) to efficiently handle multiple item layouts within a single list. Jetpack Compose introduces the equivalent optimization through the `contentType` parameter in `LazyColumn`.  
在 RecyclerView 中，开发者使用视图类型 ( `getItemViewType()` ) 来在单个列表中高效处理多种项布局。Jetpack Compose 在 `LazyColumn` 的 `contentType` 参数中引入了等效的优化。

Here’s a way of how you’d express the RecyclerView view types in Jetpack Compose:  
下面是在 Jetpack Compose 中表达 RecyclerView 视图类型的一种方式：

**Why it matters 为什么这很重要**

While Compose allows omission of the `contentType` parameter, leaving it out negatively impacts performance, particularly for lists with mixed item types. Compose maintains a limited composition cache per `contentType`, enabling it to efficiently reuse existing compositions for items of the same visual structure without expensive rebuilds. Without specifying distinct contentTypes, all items default to a single type, rapidly exhausting Compose’s internal cache. This forces frequent recompositions as users scroll, significantly increasing CPU load and potentially introducing noticeable scrolling lag.  
虽然 Compose 允许省略 `contentType` 参数，但省略会对性能产生负面影响，尤其是在包含混合项类型的列表中。Compose 为每个 `contentType` 保留有限的组合缓存，使其能够高效地重用具有相同视觉结构的现有组合，避免代价高昂的重建。如果不指定不同的 contentTypes，所有项将默认为单一类型，从而迅速耗尽 Compose 的内部缓存。这会导致用户滚动时频繁重新组合，显著增加 CPU 负载，并可能引入明显的滚动卡顿。

For optimal performance in lists with heterogeneous content, always specify the appropriate `contentType` to match your data structure.  
对于具有异构内容的列表，为了获得最佳性能，请始终指定与您的数据结构相匹配的适当 `contentType` 。

### Nested List Prefetching: From initialPrefetchItemCount to nestedPrefetchItemCount  嵌套列表预取：从 initialPrefetchItemCount 到 nestedPrefetchItemCount

When developing apps with nested scrolling lists — such as vertical feeds containing horizontal carousels — optimizing prefetching is crucial for maintaining a smooth user experience. In traditional RecyclerView setups, we rely on `setInitialPrefetchItemCount` to preload off-screen items. Jetpack Compose provides a direct analogue through the experimental `LazyListPrefetchStrategy` API, specifically its `nestedPrefetchItemCount` parameter.  
在开发包含嵌套滚动列表的应用时——例如包含水平走马灯的垂直信息流——优化预取对于维持流畅的用户体验至关重要。在传统的 RecyclerView 方案中，我们依赖 `setInitialPrefetchItemCount` 来预加载屏幕外的项。Jetpack Compose 通过实验性的 `LazyListPrefetchStrategy` API 提供了直接对应的功能，特别是它的 `nestedPrefetchItemCount` 参数。

Here’s how you implement prefetching in a nested Compose list scenario:  
下面是如何在嵌套的 Compose 列表场景中实现预取：

Common pitfall here (at least, the one that I saw with my own eyes) — sometimes developers set `LazyListPrefetchStrategy` to parent list and not to the nested ones, which, obviously, gains no effect. Always ensure you apply `nestedPrefetchItemCount` to the nested, inner scrolling list state to achieve the intended optimization.  
这里常见的一个错误（至少是我亲眼见过的）——有时开发者将 `LazyListPrefetchStrategy` 设置在父列表上，而不是设置在嵌套列表上，这显然不会起作用。务必将 `nestedPrefetchItemCount` 应用于嵌套的、内部的滚动列表状态，以达到预期的优化效果。

Be mindful that aggressive prefetch settings can significantly inflate Compose’s composition cache. On memory-constrained devices, overly large prefetch counts can push your app toward OOM crashes. Always profile memory usage carefully after adjusting your prefetch budgets — especially if targeting low-end hardware.  
请注意，激进的预取设置会显著增加 Compose 的组合缓存。在内存受限的设备上，过大的预取数量可能会将你的应用推向 OOM 崩溃。每次调整预取预算后都要仔细分析内存使用情况——尤其是在以低端硬件为目标时。

## Bonus part — animating your lists  附加部分 — 列表动画

And finally, let’s talk about animations. Compose 1.7 made adding smooth item animations surprisingly straightforward especially compared to custom RecyclerView ItemAnimators. Instead of manually orchestrating animations, simply use `Modifier.animateItem()` with concise specs for fades and movements:  
最后，我们来谈谈动画。Compose 1.7 使得为项目添加流畅动画变得出奇地简单，尤其是相比自定义 RecyclerView ItemAnimators。你无需手动编排动画，只需使用 `Modifier.animateItem()` 并配以简明的淡入淡出和位移规范：

```c
Modifier.animateItem(
    fadeInSpec = tween(200),
    fadeOutSpec = tween(120),
    placementSpec = spring(stiffness = Spring.StiffnessMediumLow)
)
```

This reduces complexity, enabling you to easily deliver polished and engaging UIs.  
这样可以降低复杂性，使你更容易交付精致且吸引人的用户界面。

## Conclusion 结论

Jetpack Compose transforms Android UI development, simplifying many complexities that have challenged RecyclerView users. However, maximizing Compose’s potential still demands strategic insight and careful application of optimization techniques. By leveraging keys for identity checks, using immutable models to optimize recompositions, mastering the TextMeasurer API for efficient text handling, and applying correct prefetch strategies for nested lists, your performance skills from RecyclerView will significantly enhance your Compose applications. Embrace these methods, and you’ll ensure your UI remains fluid, responsive, and delightful for users — proving once again that foundational performance strategies never go out of style, they simply evolve.  
Jetpack Compose 改变了 Android UI 开发，简化了许多曾让 RecyclerView 用户头疼的复杂问题。然而，要充分发挥 Compose 的潜力，仍然需要有策略的见解和对优化技术的谨慎应用。通过利用 keys 进行身份检查、使用不可变模型来优化重组、掌握 TextMeasurer API 以高效处理文本，以及为嵌套列表应用正确的预取策略，你在 RecyclerView 时积累的性能技能将显著提升你在 Compose 中的应用表现。采纳这些方法，你将确保你的 UI 保持流畅、响应迅速并让用户愉悦——再次证明基础的性能策略不会过时，它们只是不断演进。
