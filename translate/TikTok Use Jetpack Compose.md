---
title: "TikTok reduces code size by 58% and improves app performance for new features with Jetpack Compose"
source: "https://android-developers.googleblog.com/2026/03/tiktok-reduces-code-size-by-58.html"
author:
  - "[[Android Developers Blog]]"
created: 2026-03-17
---
# TikTok 通过 Jetpack Compose 将代码大小减少 58%，并提升了新功能的 app 性能

---

[![](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEh8Z60YCSMY9q_UJiIs8kRtosnM1KKnKAebXEJ3dxmHmGOIFLcnaLDMWEYNs8v__mDZ0IU6zc5oYqcp0XFlfci4QHz22QQC3ZWQCnSjMjcMb-WJl5cR7-TK9Veca0tT__RlpTlEMdSHykoADDTmMTfbYdAUU2pMFzORNKwTQRXkhIP8vLo_aEPeb7s91kE/s16000/AANDDM_TikTokCompose_Header%20(1).png)](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEh8Z60YCSMY9q_UJiIs8kRtosnM1KKnKAebXEJ3dxmHmGOIFLcnaLDMWEYNs8v__mDZ0IU6zc5oYqcp0XFlfci4QHz22QQC3ZWQCnSjMjcMb-WJl5cR7-TK9Veca0tT__RlpTlEMdSHykoADDTmMTfbYdAUU2pMFzORNKwTQRXkhIP8vLo_aEPeb7s91kE/s1280/AANDDM_TikTokCompose_Header%20\(1\).png)

[TikTok](https://play.google.com/store/apps/details?id=com.zhiliaoapp.musically&) is a global short-video platform known for its massive user base and innovative features. The team is constantly releasing updates, experiments, and new features for their users. Faced with the challenge of maintaining velocity while managing technical debt, the TikTok Android team turned to [Jetpack Compose](https://developer.android.com/compose).  
TikTok 是一个全球性的短视频平台，以其庞大的用户群和创新功能而闻名。团队不断为用户推出更新、实验和新功能。面对在管理技术债务的同时保持开发速度的挑战，TikTok Android 团队转向了 Jetpack Compose。

The team wanted to enable faster, higher-quality iteration of product requirements. By leveraging Compose, the team sought to improve engineering efficiency by writing less code and reducing cognitive load, while also achieving better performance and stability.  
团队希望实现产品需求更快、更高质量的迭代。通过利用 Compose，团队试图通过编写更少的代码和减少认知负担来提高工程效率，同时实现更好的性能和稳定性。

Streamlining complex UI to accelerate developer productivity  
简化复杂 UI 以加速开发者生产力

TikTok pages are often more complex than they appear, containing numerous layered conditional requirements. This complexity often resulted in difficult-to-maintain, sub-optimally structured View hierarchies and excessive View nesting, which caused performance degradation due to an increased number of measure passes.  
TikTok 页面通常比看起来更复杂，包含许多层级的条件要求。这种复杂性常常导致难以维护、结构欠佳的 View 层级和过多的 View 嵌套，由于测量次数的增加而造成性能下降。

Compose offered a direct solution to this structural problem.  
Compose 为这个问题提供了一个直接的解决方案。

Furthermore, Compose’s [measurement strategy](https://developer.android.com/develop/ui/compose/performance/phases) helps reduce [double taxation](https://developer.android.com/topic/performance/rendering/optimizing-view-hierarchies#double), making measure performance easier to optimize.   
此外，Compose 的测量策略有助于减少重复测量开销，使测量性能更容易优化。

To improve developer productivity, TikTok’s central Design System team provides a component library for teams working on different app features.  The team observed that Development in Compose is simple; leveraging small composables is highly effective, while incorporating large UI blocks with conditional logic is both straightforward and has minimal overhead.  
为提高开发效率，TikTok 的核心设计系统团队为负责不同应用功能的团队提供组件库。该团队观察到，在 Compose 中进行开发非常简单；利用小型可组合组件非常有效，而整合具有条件逻辑的大型 UI 模块既直接又具有极小的开销。

  

[![](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEjA5bTNaPSetoHYdXSt87tK8sN4vcWlLcSNZgpJa_Y80EIBUGvkHpny1TMzC3UGGCc3O5-TyON2MwzFtdVvX1zXVG1b3ql8Pbc5jmLnlFvaNcv8kte8wRwGeUYOzhjtGgIo1QK9Umk8hClhZ9HUzE7PcSJNXa-ivQyLwD2IeT6YJR8nWWyoalFCl1FZNmc/s16000/AANDDM_TikTokCompose_Quote%20(1).png)](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEjA5bTNaPSetoHYdXSt87tK8sN4vcWlLcSNZgpJa_Y80EIBUGvkHpny1TMzC3UGGCc3O5-TyON2MwzFtdVvX1zXVG1b3ql8Pbc5jmLnlFvaNcv8kte8wRwGeUYOzhjtGgIo1QK9Umk8hClhZ9HUzE7PcSJNXa-ivQyLwD2IeT6YJR8nWWyoalFCl1FZNmc/s1280/AANDDM_TikTokCompose_Quote%20\(1\).png)

Building a path forward through strategic migration  
通过战略迁移建设前进之路

By strategically adopting Jetpack Compose, TikTok was able to stay on top of technical debt, while also continuing to focus on creating great experiences for their users. The ability of Compose to handle conditional logic cleanly and streamline composition allowed the team to achieve up to a 78% reduction in page loading time on new or fully rewritten pages. This improvement was 20–30% in smaller cases, and 70–80% for full rewrites and new features. They also were able to reduce their code size by 58%, when compared to the same feature built in Views. The team has further shared a couple of learnings:    
通过策略性地采用 Jetpack Compose，TikTok 能够有效管理技术债务，同时继续专注于为用户提供卓越体验。Compose 在处理条件逻辑方面的能力以及简化组合流程，使团队能够在新页面或完全重写的页面上实现高达 78%的页面加载时间减少。这一改进在小规模情况下提升了 20-30%，在完全重写和新功能中提升了 70-80%。与使用 Views 构建的相同功能相比，他们还成功将代码大小减少了 58%。团队进一步分享了一些学习心得：

TikTok team’s overall strategy was to incrementally migrate specific user journeys. This gave them an opportunity to migrate, confirm measurable benefits, then scale to more screens. They started with using Compose to simplify the overall structure in the QR code feature and saw the improvements. The team later expanded the migration to the Login and Sign-up experiences.   
TikTok 团队的整体策略是逐步迁移特定的用户旅程。这为他们提供了迁移、确认可衡量的效益，然后扩展到更多界面的机会。他们最初使用 Compose 简化二维码功能的整体结构，并看到了改进效果。后来，团队将迁移扩展到了登录和注册体验。

The team shared some additional learnings:    
团队分享了一些额外的学习心得：

While checking performance during migration, the TikTok team found that using many small [ComposeViews](https://developer.android.com/reference/kotlin/androidx/compose/ui/platform/ComposeView) to replace elements inside a single [ViewHolder](https://developer.android.com/reference/androidx/recyclerview/widget/RecyclerView.ViewHolder), caused composition overhead. They achieved better results by expanding the migration to use one single ComposeView for the entire ViewHolder.  
在迁移过程中检查性能时，TikTok 团队发现使用许多小 ComposeView 来替换 ViewHolder 内部元素会导致组合开销。他们通过将迁移扩展到使用单个 ComposeView 替换整个 ViewHolder，取得了更好的效果。

When migrating a Fragment inside ViewPager, which has custom height logic and conditional logic to hide and show ui based on experiments, the performance wasn’t impacted. In this case, migrating the ViewPager to Composable performed better than migrating the Fragment.   
当在 ViewPager 中迁移一个具有自定义高度逻辑和基于实验条件隐藏和显示 UI 的逻辑的 Fragment 时，性能并未受到影响。在这种情况下，将 ViewPager 迁移到 Composable 的表现优于迁移到Fragment 。

Jun Shen really likes that Compose "reduces the amount of code required for feature development, improves testability, and accelerates delivery". The team plans to steadily increase Compose adoption, making it their preferred framework in the long term. Jetpack Compose proved to be a powerful solution for improving both their developer experience and production metrics at scale.  
Jun Shen 非常喜欢 Compose "减少功能开发所需的代码量，提高可测试性，并加速交付"。团队计划稳步提高 Compose 的采用率，使其成为他们长期的首选框架。Jetpack Compose 被证明是一个强大的解决方案，能够提升他们的开发者体验和规模化生产指标。