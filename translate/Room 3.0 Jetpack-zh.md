## Room 3.0 KMP Alpha-01

Room 持久化库提供了对 SQLite 的抽象层，以实现更稳健的数据库访问，同时充分利用 SQLite 的全部功能。

| Latest Update | Stable Release | Release Candidate | Beta Release | Alpha Release |
| --- | --- | --- | --- | --- |
| March 11, 2026 2026 年 3 月 11 日 | \- | \- | \- | [3.0.0-alpha01](https://developer.android.com/jetpack/androidx/releases/room3#3.0.0-alpha01) |

## 声明依赖项

要添加对 Room3 的依赖，您必须将 Google Maven 仓库添加到您的项目中。有关更多信息，请参阅 Google 的 Maven 仓库。

在您的应用或模块的 `build.gradle` 文件中添加您需要的工件依赖：

```kotlin
dependencies {
    val room_version = ""

    implementation("androidx.room3:room3-runtime:$room_version")
    ksp("androidx.room3:room3-compiler:$room_version")
}
```

有关使用 KSP 插件的说明，请参阅 [KSP 快速入门文档](https://kotlinlang.org/docs/ksp-quickstart.html)。

关于依赖项的更多信息，请参阅[添加构建依赖项](https://developer.android.com/studio/build/dependencies)。

### 使用 Room Gradle 插件

您可以使用 Room Gradle 插件来配置 Room 编译器的选项。该插件配置项目，使得生成的模式（编译任务的输出，用于自动迁移）能够正确配置，以实现可重复生成和可缓存的构建。

要添加插件，在您的顶层 Gradle 构建文件中，定义插件及其版本。

```kotlin
plugins {
    id 'androidx.room3' version "$room_version" apply false
}
```
在模块级别的 Gradle 构建文件中，应用该插件并使用 `room3` 扩展。

```kotlin
plugins {
    id 'androidx.room3'
}

room3 {
    schemaDirectory "$projectDir/schemas"
}
```
在使用 Room Gradle 插件时，必须设置 `schemaDirectory` 。这将配置 Room 编译器以及各种编译任务及其后端（kotlinc、KSP），使其将模式文件输出到配置的文件夹中，例如 `schemas/flavorOneDebug/com.package.MyDatabase/1.json` 。这些文件应提交到仓库中，用于验证和自动迁移。

### Version 3.0.0-alpha01

2026 年 3 月 11 日

`androidx.room3:room3-*:3.0.0-alpha01` 已发布。

Room 3.0（包 `androidx.room3` ）是 Room 2.x 包（ `androidx.room` ）的主要版本更新，专注于 Kotlin Multiplatform (KMP)。

核心注解 API 与主要组件保持不变：

- 一个扩展了 `androidx.room3.RoomDatabase` 并使用 `@Database` 注解的抽象类是 Room 的注解处理器的入口点。
- 数据库声明包含一个或多个描述数据库架构的数据类，并使用 `@Entity` 注解。
- 数据库操作在 `@Dao` 声明中定义，这些声明包含查询函数，其 SQL 语句通过 `@Query` 注解定义。
- 在运行时，可以通过一个 `RoomDatabase.Builder` 来获取数据库实现，该 `RoomDatabase.Builder` 也用于配置数据库。

在[《使用 Room 本地数据库保存数据》](https://developer.android.com/training/data-storage/room)指南中的大部分文档对于 Room 3.0 仍然适用。

Room 2.x 与之前的主要不兼容差异如下：

- 新包， `androidx.room3` 。
- SupportSQLite APIs 不再受支持，除非您正在使用 `androidx.room3:room3-sqlite-wrapper` 。
- 所有数据库操作现在都是基于协程的 API。
- 仅 Kotlin 代码生成。
- 需要 Kotlin 符号处理（KSP）。

与 2.x 版本相比，Room 3.0 除了带来破坏性变更外，还引入了新的功能：

- JS 和 WasmJS 支持
- 自定义 DAO 返回类型

**New Package 新包**

为了防止与现有的 Room 2.x 实现存在兼容性问题，以及为了具有对 Room 的传递依赖关系的库（例如 WorkManager），Room 3.0 位于一个新的包中，这意味着它也有一个新的 maven group 和 artifact ids。例如， `androidx.room:room-runtime` 变成了 `androidx.room3:room3-runtime` ，而像 `androidx.room.RoomDatabase` 这样的类现在将位于 `androidx.room3.RoomDatabase` 。

**不支持 SQLite API**

Room 3.0 完全由 SQLiteDriver API 支持，不再引用 `SupportSQLite` 类型（如 `SupportSQLiteDatabase` ）或 Android 类型（如 `Cursor` ）。这是 Room 3.0 与 2.x 之间最显著的变化，因为镜像 `SupportSQLiteDatabase` 的 `RoomDatabase` API 以及获取 `SupportSQLiteOpenHelper` 的 API 已被移除。现在需要使用 `SQLiteDriver` 来构建 `RoomDatabase` 。

例如，直接数据库操作的 API 被驱动程序等效项替换：

```kotlin
// Room 2.x
roomDatabase.runInTransaction { ... }

// Room 3.x
roomDatabase.withWriteTransaction { ... }
```
```kotlin
// Room 2.x
roomDatabase.query("SELECT * FROM Song").use { cursor -> ... }

// Room 3.x
roomDatabase.useReaderConnection { connection ->
  connection.usePrepared("SELECT * FROM Song") { stmt -> ... }
}
```

作为参数包含 `SupportSQLiteDatabase` 的回调 API 已被替换为参数包含 `SQLiteConnection` 的等效 API。这些包括迁移回调函数如 `Migration.onMigrate()` 和 `AutoMigrationSpec.onPostMigrate()` ，以及数据库回调如 `RoomDatabase.Callback.onCreate()` 、 `RoomDatabase.Callback.onOpen()` 等。

如果 Room 在 KMP 项目中使用，那么迁移到 3.0 会更容易，因为它主要涉及更新导入引用，否则从 Room 在仅 Android 到 KMP 的迁移策略相同，参见 [Room KMP 迁移指南](https://developer.android.com/kotlin/multiplatform/room#migrate)。

**SupportSQLite 包装器**

Room 3.x 保留了在 2.x 中创建的 SupportSQLite 包装器，以简化迁移，现在位于新的组件 `androidx.room3:room3-sqlite-wrapper` 中。兼容性 API 允许您将 `RoomDatabase` 转换为 `SupportSQLiteDatabase` 。 `roomDatabase.openHelper.writableDatabase` 的调用可以替换为 `roomDatabase.getSupportWrapper()` 。

**Kotlin 和协程优先**

为了更好地发展库，Room 3.0 仅生成 Kotlin 代码，并且仅是一个 Kotlin 符号处理器（KSP）。与 Room 2.x 相比，Room 3.0 不再生成 Java 代码，也无法通过 KAPT 或 JavaAP 配置注解处理器。请注意，KSP 能够处理 Java 源代码，Room 编译器将为数据库、实体或 DAO 生成代码，前提是它们的源声明是 Java。建议使用多模块项目，将 Room 的使用集中在其中，以便可以应用 Kotlin Gradle 插件和 KSP，而不会影响其余的代码库。

Room 3.0 也需要使用协程，更具体地说，DAO 函数必须是挂起函数，除非它们返回的是响应式类型，例如 `Flow` 或自定义的 DAO 返回类型。用于执行数据库操作的 Room API 也是挂起函数，例如 `RoomDatabase.useReaderConnection` 和 `RoomDatabase.useWriterConnection` 。

与 Room 2.x 不同，不再可能使用 `RoomDatabase` 配置 `Executor` ，相反，可以通过数据库的构建器提供 `CoroutineContext` 以及一个 dispatcher。

 Room 3.0 中的 API 是 `Flow` 基于的， `InvalidationTracker.Observer` 已被移除，其相关 API `addObserver` 和 `removeObserver` 也一并移除。数据库操作的响应机制是通过在 `InvalidationTracker` 中通过 `createFlow()` API 创建的 Coroutine Flows 来实现的。

示例用法：

```kotlin
fun getArtistTours(from: Date, to: Date): Flow<Map<Artist, TourState>> {
    return db.invalidationTracker.createFlow("Artist").map { _ ->
        val artists = artistsDao.getAllArtists()
        val tours = tourService.fetchStates(artists.map { it.id })
        associateTours(artists, tours, from, to)
    }
}
```

**Web 支持**

Room 3.0 版本增加了 JavaScript 和 WasmJs 作为 KMP 目标。结合 `SQLiteDriver` 接口（ `androidx.sqlite:sqlite` ）的发布，这些接口同样支持 JavaScript 和 WasmJs，以及位于新组件 `androidx.sqlite:sqlite-web` 中的新驱动 `WebWorkerSQLiteDriver` ，使得 Room 可以在面向所有主要 KMP 平台的标准代码中使用。

由于 Web 平台的异步特性，Room API 中接受 `SQLiteStatement` 作为参数的 API 现在变成了挂起函数。这些函数的例子包括 `Migration.onMigrate()` 、 `RoomDatabase.Callback.onCreate()` 、 `PooledConnection.usePrepared()` 等。在驱动 API 中，异步 API 在所有平台上都很常见，而同步 API 则常见于非 Web 目标。因此，不针对 Web 的项目可以继续在公共代码中使用同步 API（ `SQLiteDriver.open()` 、 `SQLiteConnection.prepare()` 和 `SQLiteStatement.step()` ）。同时，仅针对 Web 的项目必须使用异步 API（ `SQLiteDriver.openAsync()` 、 `SQLiteConnection.prepareAsync()` 和 `SQLiteStatement.stepAsync()` ）。

为了方便起见， `androidx.sqlite` 包还添加了与所提及的 API 同步名称的挂起扩展函数（增加了 `SQLiteConnection.executeSQL` ），当项目同时针对 Web 和非 Web 平台时，推荐使用这些 API，因为这些 API 是 expect/actual 声明，会根据平台调用正确的版本。这些是 Room 运行时使用的 API，并使所有支持平台在通用代码中启用驱动程序。

示例用法：

```kotlin
import androidx.sqlite.executeSQL
import androidx.sqlite.step

roomDatabase.useWriterConnection { connection ->
    val deletedSongs = connection.usePrepared(
        "SELECT count(*) FROM Song"
    ) { stmt ->
        stmt.step()
        stmt.getLong(0)
    }
    connection.executeSQL("DELETE FROM Song")
    deletedSongs
}
```

 是一个与 Web Worker 通信的 `SQLiteDriver` 实现，用于在主线程之外执行数据库操作，并支持将数据库存储在原点私有文件系统（OPFS）中。要实例化驱动程序，需要实现一个简单的通信协议的 Worker，该协议在 WebWorkerSQLiteDriver KDoc 中描述。

目前 `WebWorkerSQLiteDriver` 不自带实现通信协议的默认工作线程，但作为示例，androidx 代码库中包含一个可用于您项目的工作线程实现。它使用 SQLite 的 WASM，并将数据库存储在 OPFS 中。示例工作线程被发布为一个本地 NPM 包，得益于 Kotlin 对 NPM 依赖的支持，可以创建一个小型 KMP 模块来提供该工作线程。

查看以下 [GitHub 项目](https://github.com/danysantiago/room-web-demo/) ，演示了在 Room 中使用本地 Web Worker。

一旦在项目中设置好工作线程，那么为 Web 配置 Room 与其他平台类似：

```kotlin
fun createDatabase(): MusicDatabase {
    return Room.databaseBuilder<MusicDatabase>("music.db")
        .setDriver(WebWorkerSQLiteDriver(createWorker()))
        .build()
}

fun createWorker() =
    Worker(js("""new URL("sqlite-web-worker/worker.js", import.meta.url)"""))
```

Web 驱动程序的某个未来版本可能会在 NPM 上发布一个默认的工作者，从而简化 Web 设置。

**自定义 DAO 返回类型**

各种 DAO 返回类型集成，如 RxJava 和 Paging，已转换为使用 Room 3.0 中的新 API——DAO 返回类型转换器。DAO 返回类型转换器函数（ `@DaoReturnTypeConverter` ）能够将 DAO 函数的结果转换为注解函数定义的自定义类型。这些函数使参与 Room 生成的代码成为可能，该代码将查询结果转换为数据对象。包含 DAO 返回类型转换器的类必须通过在 `@Database` 或 `@Dao` 声明中的 `@DaoReturnTypeConverters` 注解进行注册。

例如，若要使 DAO 查询返回 `PagingSource` ，则必须注册位于 `androidx.room3:room3-paging` 的转换类：

```kotlin
@Dao
@DaoReturnTypeConverters(PagingSourceDaoReturnTypeConverter::class)
interface MusicDao {
    @Query("SELECT * FROM Song)
    fun getSongsPaginated(): PagingSource<Int, Song>
}
```

现有的集成已迁移至 DAO 返回类型转换器：

| Return Type | Converter class | Artifact |
| --- | --- | --- |
| PagingSource | PagingSourceDaoReturnTypeConverter | androidx.room3:room3-paging |
| Observable, Flowable, Completable, Single, Maybe | RxDaoReturnTypeConverters | androidx.room3:room3-rxjava3 |
| ListenableFuture | GuavaDaoReturnTypeConverter | androidx.room3:room3-guava |
| LiveData | LiveDataDaoReturnTypeConverter | androidx.room3:room3-livedata |

与列类型转换器类似，DAO 返回类型转换器也可以由应用程序定义。例如，应用程序可以声明一个 `@DaoReturnTypeConverter` 用于网络类型 `kotlin.js.Promise` 。

```kotlin
object PromiseDaoReturnTypeConverter {
    @DaoReturnTypeConverter([OperationType.READ, OperationType.WRITE])
    fun <T> convert(
        db: RoomDatabase,
        executeAndConvert: suspend () -> T
    ): Promise<T> {
        return db.getCoroutineScope().promise { executeAndConvert() }
    }
}
```

上述转换器随后允许 DAO 查询函数返回 `Promise`:

```kotlin
@Dao
@DaoReturnTypeConverters(PromiseDaoReturnTypeConverter::class)
interface MusicDao {
    @Query("SELECT * FROM Song")
    fun getAllSongs(): Promise<List<Song>>
}
```

一个 `@DaoReturnTypeConverter` 函数在参数的数量和类型上有一些建议。可能的参数有：

- `db: RoomDatabase`: (可选) 提供对 `RoomDatabase` 实例的访问，这在进行额外的数据库操作或访问协程作用域时可能很有用。
- `tableNames: Array<String>`: (可选) 包含查询访问的表，与 Room 的 `InvalidationTracker.createFlow()` API 结合使用时，可用于支持可观察/响应式类型。
- `rawQuery: RoomRawQuery`: （可选）在运行时包含一个查询实例，允许进行如 `LIMIT` / `OFFSET` 策略之类的转换，这些策略由 `PagingSourceDaoReturnTypeConverter` 实现。
- `executeAndConvert: suspend () -> T`: (必需) Room 生成的函数，用于执行查询并将其结果解析为数据对象。

有关创建 DAO 返回类型转换器的要求，请参阅 [`@DaoReturnTypeConverter` API 的 KDoc 文档](https://cs.android.com/androidx/platform/frameworks/support/+/androidx-main:room3/room3-common/src/commonMain/kotlin/androidx/room3/DaoReturnTypeConverter.kt). 。