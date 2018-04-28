# 优化嵌套的RecyclerView

RecyclerView是ListView的更高级版本，它重用相同的视图以防止额外创建视图以提供平滑的滚动体验。RecyclerView通过保持视图池来实现这一点，该视图池包含不再可见并且可以回收的视图。

有时我们需要嵌套RecyclerView来创建一些布局。考虑在垂直方向RecyclerView内部有水平RecyclerView的情况。

![](http://p6uvwa6u4.bkt.clouddn.com/img/1_GaK-wOYjrrVSA_vKOof-Aw.jpeg)

在上图可以看到一个可以水平滚动的垂直RecyclerView，这是通过在另一个recyclerView中放置recyclerView来实现的。

当用户向侧面滑动时，内部RecyclerView可以回收视图并为您提供平滑滚动。但是，当用户垂直滚动时，情况并非如此。内部RecyclerView的每个视图都会再次inflate，这是因为每个嵌套的RecyclerView都有一个自己的视图池。

我们可以通过为所有内部RecyclerView设置单个视图池来解决此问题。

```java

```

允许你可以给RecyclerVIew设置自定义的视图池，代码看起来像这样：

```java
public OuterRecyclerViewAdapter(List<Item> items) {
    //Constructor stuff
    viewPool = new RecyclerView.RecycledViewPool();
}
@Override
public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
    //Create viewHolder etc
    holder.innerRecyclerView.setRecycledViewPool(viewPool);
    
}
```

所以，现在所有的内部RecyclerView都有相同的视图池，它可以使用彼此的视图。这使得视图创建更少，滚动性能更好。

[原文链接](https://medium.com/@mgn524/optimizing-nested-recyclerview-a9b7830a4ba7)

