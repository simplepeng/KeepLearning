## 冒泡排序

冒泡排序是一种交换排序，它的基本思想是：两两比较相邻记录的元素，如果反序则交换，直到没有反序为止。

```java
public static void bubbleSort(int[] arr) {
        int len = arr.length;
        // 循环次数为数组容量
        for (int i = 0; i < len; i++) {
            // 循环len-i次，因为完成一次循环，最大的元素就会被移动至末尾
            for (int j = 0; j < len - i; j++) {
                // 比较当前位置和下一位谁大
                if (j < len - 1 && arr[j] > arr[j + 1]) {
                    // 交互位置
                    swap(arr, j, j + 1);
                }
            }
        }
}
```

双层for循环，内层循环用来交互位置，外层循环用来控制循环次数。

每次循环后，最大的那个元素就会移动至末尾，所以内存循环次数可以为数组length减去外层循环的当前index。

![](../imgs/bubble_sort.gif)