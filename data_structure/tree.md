# 树-Tree

[维基百科](https://zh.wikipedia.org/wiki/树_(数据结构))

`树`是n(n>=0)个结点的有限集。

n=0时称为`空树`。

树的定义大多数使用的是`递归`方法。

结点的层次(Level)从根开始定义起，根为第一层，根的孩子为第二层。

树结点的最大层次称为树的`深度(Depth)`或`高度`。

如果把树中结点的各子树看成从左至右是有次序的，不能互换的，则称该树为`有序树`，否则为`无序树`。

`森林(Forest)`是`m(m>=0)`棵互不相交的树的集合。

## 对比线性表和树的结构

* 线性表
  * 第一个元素：无前驱
  * 最后一个元素：无后继
  * 中间元素：一个前驱，一个后继
* 树结构
  * 根结点：无双亲，唯一
  * 叶结点：无孩子，可以多个
  * 中间结点：一个双亲，多个孩子

## 二叉树

[维基百科](https://zh.wikipedia.org/wiki/二叉树)

`二叉树(Binary Tree)`是n(n>=0)个结点的有限集合，该集合或者为空集(空二叉树)，或者由一个根节点和两棵互不相交的`左子树`和`右子树`的二叉树组成。

二叉树的特点：

* 每个结点最多两棵子树
* 左子树和右子树是有顺序的
* 即使树中某结点只有一颗子树，也要区分它是左子树还是右子树

## 特殊二叉树

* 斜树
* 满二叉树
* 完全二叉树

所有的结点都只有左子树的二叉树叫`左斜树`。所有结点都是只有右子树的二叉树叫`右斜树`。这两者统称为`斜树`。

斜树有很明显的特点，就是每一层都只有一个结点，结点的个数与二叉树的深度相同。

在一个二叉树中，如果所有分支结点都存在左子树和右子树，并且所有叶子都在**同一层上**，这样的二叉树称为`满二叉树`。

对一棵具有n个结点的二叉树按层序编号，如果编号为i(1<=i<=n)的结点与同样深度的满二叉树中编号为i的结点在二叉树中位置完全相同，则这棵树称为`完全二叉树`。

## 建立二叉树

## 遍历二叉树

* 前序遍历
* 中序遍历
* 后序遍历
* 层序遍历

前序遍历：先根后左再右，先访问根结点，然后前序遍历左子树，再前序遍历右子树。若树为空，则空操作返回。

中序遍历：先左后跟再右，先中序遍历根结点的左子树，然后访问根结点，最后中序遍历右子树。若树为空，则空操作返回。

后序遍历：先左后右再根，从左到右先叶子后结点的方式遍历访问左右子树，最后访问根结点。若树为空，则空操作返回。

层序遍历：从树的第一层，也就是根结点开始访问，从上而下逐层遍历，在同一层中，按从左到右的顺序对结点逐个访问。若树为空，则空操作返回。

* 已知前序遍历序列和中序遍历序列，可以唯一确定一棵二叉树。
* 已知后序遍历序列和中序遍历序列，可以唯一确定一棵二叉树。
* 但是已知前序和后序遍历，是不能确定一棵二叉树的。

## 线索二叉树

在一个结点上有指向前驱和后继的指针，这种指针称为`线索`，加上线索的二叉链表称为`线索链表`，相应的二叉树就称为`线索二叉树(Thread Binary Tree)`。

线索二叉树等于是把一棵二叉树转变成了双向链表，这样对我们插入删除结点，查找某个结点都带来了方便。所以我们对二叉树以某种次序遍历使其变为线索二叉树的过程称为`线索化`。

线索化的过程就是在遍历的过程中修改空指针的过程。

如果所用的二叉树需经常遍历或查找结点时需要某种遍历序列中的前驱和后继，那么采用线索二叉链表的存储结构就是非常不错的选择。

## 树，森林与二叉树的转换

## 哈夫曼树

[维基百科](https://zh.wikipedia.org/wiki/霍夫曼编码)

`哈夫曼树`也称之为`最优二叉树`。与之对应的算法就是`哈夫曼编码`。

## 平衡二叉搜索树

[维基百科](https://zh.wikipedia.org/wiki/平衡二元搜尋樹)

* AVL树
* 红黑树
* Treap(树堆)
* 节点大小平衡树

## 红黑树

[维基百科](https://zh.wikipedia.org/wiki/红黑树)



