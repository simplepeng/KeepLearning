## 简单选择排序

[百度百科](https://baike.baidu.com/item/%E7%AE%80%E5%8D%95%E9%80%89%E6%8B%A9%E6%8E%92%E5%BA%8F/9796478)

1. 从数列中选择最大或最小的那个元素，放到首位或末尾。

2. 重复上一步骤，但是这里的首位或末尾是指不包含上一步已经占坑了的首位或末尾。

```java
private static void selectionSort(int[] arr) {
    int length = arr.length;
    int minIndex = 0;

    for (int i = 0; i < length; i++) {
        minIndex = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        swap(arr, i, minIndex);
    }
}
```

内层for循环遍历一次数列找出最小或最大的那个元素，外层for控制循环次数，保证每个元素都被比较到。

从简单选择排序的过程来看，它最大的特点就是交换移动数据次数相当少，这样就节约了相应的时间。

平均时间复杂度为O(n²)，尽管与冒泡排序同为O(n²)，但简单排序的性能还是要优于冒泡算法。

![](../imgs/selection_sort.gif)

