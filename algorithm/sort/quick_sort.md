## 快速排序

[维基百科](https://zh.wikipedia.org/wiki/快速排序)

快速排序的核心思想就是：`分治和递归`。

```java
/**
 * 入口函数（递归方法），算法的调用从这里开始。
 */
public void quickSort(int[] arr, int startIndex, int endIndex) {
    if (startIndex >= endIndex) {
        return;
    }
 
    // 核心算法部分：分别介绍 双边指针（交换法），双边指针（挖坑法），单边指针
    int pivotIndex = doublePointerSwap(arr, startIndex, endIndex);
    // int pivotIndex = doublePointerHole(arr, startIndex, endIndex);
    // int pivotIndex = singlePointer(arr, startIndex, endIndex);
 
    // 用分界值下标区分出左右区间，进行递归调用
    quickSort(arr, startIndex, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, endIndex);
}
 
/**
 * 双边指针（交换法）
 * 思路：
 * 记录分界值 pivot，创建左右指针（记录下标）。
 * （分界值选择方式有：首元素，随机选取，三数取中法）
 *
 * 首先从右向左找出比pivot小的数据，
 * 然后从左向右找出比pivot大的数据，
 * 左右指针数据交换，进入下次循环。
 *
 * 结束循环后将当前指针数据与分界值互换，
 * 返回当前指针下标（即分界值下标）
 */
private int doublePointerSwap(int[] arr, int startIndex, int endIndex) {
    int pivot = arr[startIndex];
    int leftPoint = startIndex;
    int rightPoint = endIndex;
 
    while (leftPoint < rightPoint) {
        // 从右向左找出比pivot小的数据
        while (leftPoint < rightPoint
                && arr[rightPoint] > pivot) {
            rightPoint--;
        }
        // 从左向右找出比pivot大的数据
        while (leftPoint < rightPoint
                && arr[leftPoint] <= pivot) {
            leftPoint++;
        }
        // 没有过界则交换
        if (leftPoint < rightPoint) {
            int temp = arr[leftPoint];
            arr[leftPoint] = arr[rightPoint];
            arr[rightPoint] = temp;
        }
    }
    // 最终将分界值与当前指针数据交换
    arr[startIndex] = arr[rightPoint];
    arr[rightPoint] = pivot;
    // 返回分界值所在下标
    return rightPoint;
}
 
/**
 * 双边指针（挖坑法）
 * 思路：
 * 创建左右指针。
 * 记录左指针数据为分界值 pivot，
 * 此时左指针视为"坑"，里面的数据可以被覆盖。
 *
 * 首先从右向左找出比pivot小的数据，
 * 找到后立即放入左边坑中，当前位置变为新的"坑"，
 * 然后从左向右找出比pivot大的数据，
 * 找到后立即放入右边坑中，当前位置变为新的"坑"，
 *
 * 结束循环后将最开始存储的分界值放入当前的"坑"中，
 * 返回当前"坑"下标（即分界值下标）
 */
private int doublePointerHole(int[] arr, int startIndex, int endIndex) {
    int pivot = arr[startIndex];
    int leftPoint = startIndex;
    int rightPoint = endIndex;
 
    while (leftPoint < rightPoint) {
        // 从右向左找出比pivot小的数据，
        while (leftPoint < rightPoint
                && arr[rightPoint] > pivot) {
            rightPoint--;
        }
        // 找到后立即放入左边坑中，当前位置变为新的"坑"
        if (leftPoint < rightPoint) {
            arr[leftPoint] = arr[rightPoint];
            leftPoint++;
        }
        // 从左向右找出比pivot大的数据
        while (leftPoint < rightPoint
                && arr[leftPoint] <= pivot) {
            leftPoint++;
        }
        // 找到后立即放入右边坑中，当前位置变为新的"坑"
        if (leftPoint < rightPoint) {
            arr[rightPoint] = arr[leftPoint];
            rightPoint--;
        }
    }
    // 将最开始存储的分界值放入当前的"坑"中
    arr[rightPoint] = pivot;
    return rightPoint;
}
 
/**
 * 单边指针
 * 思路：
 * 记录首元素为分界值 pivot, 创建标记 mark 指针。
 * 循环遍历与分界值对比。
 * 比分界值小，则 mark++ 后与之互换。
 * 结束循环后，将首元素分界值与当前mark互换。
 * 返回 mark 下标为分界值下标。
 */
private int singlePointer(int[] arr, int startIndex, int endIndex) {
    int pivot = arr[startIndex];
    int markPoint = startIndex;
 
    for (int i = startIndex + 1; i <= endIndex; i++) {
        // 如果比分界值小，则 mark++ 后互换。
        if (arr[i] < pivot) {
            markPoint++;
            int temp = arr[markPoint];
            arr[markPoint] = arr[i];
            arr[i] = temp;
        }
    }
    // 将首元素分界值与当前mark互换
    arr[startIndex] = arr[markPoint];
    arr[markPoint] = pivot;
    return markPoint;
}
```

1. 从数组或队列中选出一个元素，称之为`基准(pivot)`。
2. 开始排序，比基准小的就放到基准的前面，比基准大得就放在基准的后面，相同的可以放在任意一边。一次分区完成后，基准就位于数列的中间。所以这个也称之为`分区(partition)`操作。
3. `递归的`把小于基准和大于基准的子数列排序，也就是进行上一步的操作。

![](../imgs/quick_sort.gif)

[百度百科](https://baike.baidu.com/item/%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F%E7%AE%97%E6%B3%95/369842?fromtitle=%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F&fromid=2084344)

## 时间复杂度分析

* 在最优的情况下，`分区操作(partition)`每次都划分得很均匀，时间复杂度为`O(nlogn)`
* 在最坏情况下，待排序的数据为`正序`或`反序`，其时间复杂度为`O(n²）`
* 平均的情况，时间复杂度为O(nlogn)`

## 快速排序的优化

1. 优化选取枢轴(pivot)
    * 随机选取枢轴法
    * 三数取中法(median-of-three)
    * 九数取中法(median-of-nine)
2. 优化不必要的交换
3. 优化数组元素小的排序方案
4. 优化递归操作(尾递归)

在现实中，待排序的序列极有可能是基本有序的，此时，总是`固定选取`某个数作为`枢轴`，就变成了极为不合理的方法。

于是就有人提出了`随机枢轴法`：随机获得一个low与high之间的数rnd，让它的关键字L.r[rnd]与L.r[low]交换。

`三数取中法`：即取三个关键字先进行排序，将中间数作为枢轴，一般是取左端，右端和中间的三个数，也可以是随机抽取。

`九数取中法`：先从数组中分三次取样，每次取三个数，三个样品各取出中数，然后从这三个中数当中再取出一个中数作为枢轴。

如果数组非常小，其实快速排序反而不如直接插入排序来得更好(直接插入排序是简单排序中性能最好的)。

