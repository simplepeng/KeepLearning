## 直接插入排序

[维基百科](https://zh.wikipedia.org/wiki/插入排序)

直接插入排序的基本操作是将一个记录插入到已经排好序的有序表中，从而得到一个新的，记录数增1的有序表。

1. 将未排序数列的第一个元素看做一个有序序列，从第二个元素到最后一个元素看成未排序序列。
2. 从头至尾遍历未排序序列，将扫描到的每个元素插入`有序序列`适当的位置。

```java
private static void insertionSort(int[] arr) {
        int length = arr.length;

        // 下标从1开始，因为0下标已经被当成有序序列
        for (int i = 1; i < length; i++) {
            int current = arr[i];//当前要插入的元素
            int preIndex = i - 1;//未排序序列的index

            // 如果未排序的元素大于当前要插入的元素，继续执行循环
            // 并且preIndex的下标要不小于0
            while (preIndex >= 0 && arr[preIndex] > current) {
                arr[preIndex + 1] = arr[preIndex];// preIndex的元素后移一位
                preIndex--;// 已排序序列下标减一，继续比较
            }

            // 当preIndex下标的元素不大于current时，就插入在preIndex后面
            arr[preIndex + 1] = current;
        }
    }
```

![](../imgs/insertion_sort.gif)

同样的O(n²)时间复杂度，直接插入排序比冒泡和简单选择排序的性能要好一些。

