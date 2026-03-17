# TikTok 通过 Jetpack Compose 将代码大小减少 58%，并提升了新功能的 app 性能

[![](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEh8Z60YCSMY9q_UJiIs8kRtosnM1KKnKAebXEJ3dxmHmGOIFLcnaLDMWEYNs8v__mDZ0IU6zc5oYqcp0XFlfci4QHz22QQC3ZWQCnSjMjcMb-WJl5cR7-TK9Veca0tT__RlpTlEMdSHykoADDTmMTfbYdAUU2pMFzORNKwTQRXkhIP8vLo_aEPeb7s91kE/s16000/AANDDM_TikTokCompose_Header%20(1).png)](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEh8Z60YCSMY9q_UJiIs8kRtosnM1KKnKAebXEJ3dxmHmGOIFLcnaLDMWEYNs8v__mDZ0IU6zc5oYqcp0XFlfci4QHz22QQC3ZWQCnSjMjcMb-WJl5cR7-TK9Veca0tT__RlpTlEMdSHykoADDTmMTfbYdAUU2pMFzORNKwTQRXkhIP8vLo_aEPeb7s91kE/s1280/AANDDM_TikTokCompose_Header%20\(1\).png)

TikTok 是一个全球性的短视频平台，以其庞大的用户群和创新功能而闻名。团队不断为用户推出更新、实验和新功能。面对在管理技术债务的同时保持开发速度的挑战，TikTok Android 团队转向了 Jetpack Compose。

团队希望实现产品需求更快、更高质量的迭代。通过利用 Compose，团队试图通过编写更少的代码和减少认知负担来提高工程效率，同时实现更好的性能和稳定性。

## 简化复杂 UI 以加速开发者生产力

TikTok 页面通常比看起来更复杂，包含许多层级的条件要求。这种复杂性常常导致难以维护、结构欠佳的 View 层级和过多的 View 嵌套，由于测量次数的增加而造成性能下降。

Compose 为这个问题提供了一个直接的解决方案。

此外，Compose 的测量策略有助于减少重复测量开销，使测量性能更容易优化。

为提高开发效率，TikTok 的核心设计系统团队为负责不同应用功能的团队提供组件库。该团队观察到，在 Compose 中进行开发非常简单；利用小型可组合组件非常有效，而整合具有条件逻辑的大型 UI 模块既直接又具有极小的开销。

[![](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEjA5bTNaPSetoHYdXSt87tK8sN4vcWlLcSNZgpJa_Y80EIBUGvkHpny1TMzC3UGGCc3O5-TyON2MwzFtdVvX1zXVG1b3ql8Pbc5jmLnlFvaNcv8kte8wRwGeUYOzhjtGgIo1QK9Umk8hClhZ9HUzE7PcSJNXa-ivQyLwD2IeT6YJR8nWWyoalFCl1FZNmc/s16000/AANDDM_TikTokCompose_Quote%20(1).png)](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEjA5bTNaPSetoHYdXSt87tK8sN4vcWlLcSNZgpJa_Y80EIBUGvkHpny1TMzC3UGGCc3O5-TyON2MwzFtdVvX1zXVG1b3ql8Pbc5jmLnlFvaNcv8kte8wRwGeUYOzhjtGgIo1QK9Umk8hClhZ9HUzE7PcSJNXa-ivQyLwD2IeT6YJR8nWWyoalFCl1FZNmc/s1280/AANDDM_TikTokCompose_Quote%20\(1\).png)

## 通过战略迁移建设前进之路

通过策略性地采用 Jetpack Compose，TikTok 能够有效管理技术债务，同时继续专注于为用户提供卓越体验。Compose 在处理条件逻辑方面的能力以及简化组合流程，使团队能够在新页面或完全重写的页面上实现高达 78%的页面加载时间减少。这一改进在小规模情况下提升了 20-30%，在完全重写和新功能中提升了 70-80%。与使用 Views 构建的相同功能相比，他们还成功将代码大小减少了 58%。团队进一步分享了一些学习心得：

TikTok 团队的整体策略是逐步迁移特定的用户旅程。这为他们提供了迁移、确认可衡量的效益，然后扩展到更多界面的机会。他们最初使用 Compose 简化二维码功能的整体结构，并看到了改进效果。后来，团队将迁移扩展到了登录和注册体验。

## 团队分享了一些额外的学习心得：

在迁移过程中检查性能时，TikTok 团队发现使用许多小 ComposeView 来替换 ViewHolder 内部元素会导致组合开销。他们通过将迁移扩展到使用单个 ComposeView 替换整个 ViewHolder，取得了更好的效果。

当在 ViewPager 中迁移一个具有自定义高度逻辑和基于实验条件隐藏和显示 UI 的逻辑的 Fragment 时，性能并未受到影响。在这种情况下，将 ViewPager 迁移到 Composable 的表现优于迁移到Fragment 。

Jun Shen 非常喜欢 Compose "减少功能开发所需的代码量，提高可测试性，并加速交付"。团队计划稳步提高 Compose 的采用率，使其成为他们长期的首选框架。Jetpack Compose 被证明是一个强大的解决方案，能够提升他们的开发者体验和规模化生产指标。