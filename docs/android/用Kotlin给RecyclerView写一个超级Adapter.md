# 用Kotlin给RecyclerView封装一个Adapter



## 正常RecycleView + Adapter 的写法

```java
class MainActivity : AppCompatActivity() {

    private lateinit var mRecyclerView: RecyclerView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        mRecyclerView = findViewById(R.id.recyclerView)
        mRecyclerView.layoutManager = LinearLayoutManager(this)
        val itemList = listOf(Program(1, "java"),
                Program(2, "c"),
                Program(3, "c++"),
                Program(4, "python"),
                Program(5, "go"),
                Program(6, "ruby"),
                Program(7, "kotlin"),
                Program(8, "scale"),
                Program(9, "lisp"),
                Program(10, "swift"),
                Program(11, "object-c"),
                Program(12, "html"),
                Program(13, "javascript"))
        mRecyclerView.adapter = RvAdapter(R.layout.item_rv, itemList)
    }
}
```

```java
class RvAdapter constructor(private val layoutId: Int, private val itemList: List<Program>)
    : RecyclerView.Adapter<RvAdapter.ViewHolder>() {

    override fun onCreateViewHolder(parent: ViewGroup?, viewType: Int): ViewHolder {
        val itemView = LayoutInflater.from(parent?.context)
                .inflate(layoutId, null)
        return ViewHolder(itemView)
    }

    override fun onBindViewHolder(holder: ViewHolder?, position: Int) {
        val item = itemList[holder?.adapterPosition!!]
        holder.mTvPosition.text = """${item.position} --- ${item.name}"""
    }

    override fun getItemCount() = itemList.size


    class ViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {
        var mTvPosition: TextView = itemView.findViewById(R.id.tv_position)
    }
}
```

<img src="https://ws1.sinaimg.cn/mw690/00677ch9gy1fn3s07j8d4j30u01hc75y" width="220"/>

## 用Kotlin封装一个最初始的Adapter

```java
class KtAdapter<T> constructor(private val layoutId: Int,
                               private val itemList: List<T>,
                               //定义一个继承View的lambda表达式，并且这个接受一个泛型的实体
                               private val bindHolder: View.(T) -> Unit)
    : RecyclerView.Adapter<KtAdapter.ViewHolder>() {

    override fun onCreateViewHolder(parent: ViewGroup?, viewType: Int): ViewHolder {
        val itemView = LayoutInflater.from(parent?.context)
                .inflate(layoutId, null)
        return ViewHolder(itemView)
    }

    override fun onBindViewHolder(holder: ViewHolder?, position: Int) {
        val item = itemList[holder?.adapterPosition!!]
        //使用这个lambda表达式
        holder.itemView.bindHolder(item)
    }

    override fun getItemCount() = itemList.size

    class ViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView)

}
```

```java
import kotlinx.android.synthetic.main.item_rv.view.*
...
mRecyclerView.adapter = KtAdapter(R.layout.item_rv, itemList, {
  //所以这里lambda的it就是泛型T对应的实体
    tv_position.text = "${it.position} --- ${it.name}"
})
```

## 增加Item点击事件

```java
class KtAdapter<T> constructor(private val layoutId: Int,
                               private val itemList: List<T>,
        //定义一个lambda表达式
                               private val bindHolder: View.(T) -> Unit)
    : RecyclerView.Adapter<KtAdapter.ViewHolder>() {

    private var itemClick: T.() -> Unit = {}

    constructor(layoutId: Int,
                itemList: List<T>,
                bindHolder: View.(T) -> Unit,
                itemClick: T.() -> Unit = {}) : this(layoutId, itemList, bindHolder) {
        this.itemClick = itemClick
    }

    override fun onCreateViewHolder(parent: ViewGroup?, viewType: Int): ViewHolder {
        val itemView = LayoutInflater.from(parent?.context)
                .inflate(layoutId, null)
        val holder = ViewHolder(itemView)
        return holder
    }

    override fun onBindViewHolder(holder: ViewHolder?, position: Int) {
        val item = itemList[holder?.adapterPosition!!]
        holder.itemView.bindHolder(item)
        holder.itemView.setOnClickListener {
            itemOnClick(it, position)
        }
    }

    override fun getItemCount() = itemList.size

    class ViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView)

    protected open fun itemOnClick(itemView: View, position: Int) {
        itemList[position].itemClick()
    }

}
```

```java
mRecyclerView.adapter = KtAdapter(R.layout.item_rv, itemList, {
    tv_position.text = "${it.position} --- ${it.name}"
}, {
    Toast.makeText(applicationContext, this.name, Toast.LENGTH_SHORT).show()
})
```

