## 创建

### 复制一个已创建的仓库

```shell
git clone 仓库链接
```

仓库链接可以是`https`和`ssh`的

### 创建一个新的仓库

```shell
git init
```

## 本地修改

### 显示工作路径下全部已修改的文件

```shell
git status
```

### 显示与上次提交版本文件的不同

```shell
git diff
```

### 把当前所有修改添加到下次提交中

```shell
git add .
```

### 指定某个文件的修改添加到下次提交中

```shell
git add -p <file>
```

### 提交本地的所有修改

```shell
git commit -a
```

### 提交之前已标记的变化

```shell
git commit
```

### 修改上次提交

请勿修改已发布的提交记录

```shell
git commit --amend
```

## 提交历史

### 从最新提交开始显示所有的提交记录

```shell
git log
```

### 显示指定文件的所有修改

```shell
git log -p <file>
```

### 谁，在什么时间，修改了文件的什么内容

```shell
git blame <file>
```

## 分支与标签

### 显示所有分支

```shell
git branch -av
```

### 切换当前分支

```shell
git checkout <branch>
```

### 创建新分支，基于当前分支

```shell
git branch <new-branch>
```

### 创建新的可追溯分支，基于远程分支

```shell
git checkout --track <remote/branch> <new-branch>
```

### 删除本地分支

```shell
git branch -d <branch>
```

### 给当前提交打标签

```shell
git tag <tag-name>
```

## 更新与发布

### 列出当前配置的远程端

```shell
git remote -v
```

### 显示远程端信息

```shell
git remote show <remote>
```

### 添加新的远程端

```shell
git remote add <shortname> <url>
```

### 下载远程端的所有改动到本地，不自动合并到当前

```shell
git fetch <remote>
```

### 下载远程端的所有改动到本地，自动合并到当前

```shell
git pull <remote> <branch>
```

### 将本地版本发布到远程端

```shell
git push <remote> <branch>
```

### 删除远程端分支

```shell
git branch -dr <remote/branch>
```

### 发布标签

```shell
git push --tags
```

## 合并与重置

### 将分支合并到当前

```shell
git merge <branch>
```

### 将当前版本重置到分支中

请勿重置已发布的提交

```shell
git rebase <branch>
```

### 退出重置

```shell
git rebase --abort
```

### 解决冲突后继续重置

```shell
git rebase --continue
```

### 使用配置好的合并工具去解决冲突

```shell
git mergetool
```

### 在编辑器中手动解决冲突后，标记文件为已解决冲突

```shell
git add <resolved-file>
git rm <resolved-file>
```

## 撤销

### 放弃工作目录下的所有修改

```shell
git reset --hard HEAD
```

### 放弃某个文件的所有本地修改

```shell
git checkout HEAD <file>
```

### 重置一个提交

通过创建一个截然不同的新提交

```shell
git revert <commit>
```

### 将HEAD重置到上一次提交的版本，并抛弃该版本之后的所有修改

```shell
git reset --hard <commit>
```

### 将HEAD重置到上一次提交的版本，并将之后修改标记为未添加到缓存区的修改

```shell
git reset <commit>
```

### 将HEAD重置到上一次提交的版本，并保留未提交的本地修改

```shell
git reset --keep <commit>
```



