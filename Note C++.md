# Note C++

[toc]

## 02_03

### 编译指令

```
g++ -c main.cpp
g++ -o main main.o
./main
```

`-c` 后会编译（Compile）生成 `main.o` 文件，`main.cpp` 是编写的代码文件

`-o` 后会链接（Link）生成 `main` 文件，`main` 是生成的文件的名称，`main.o` 是编译生成的文件

最后通过 `./main` 运行 `main` 文件

分布编译的目的是：防止在有多个文件需要编译时，只修改了一个文件，结果要编译所有文件。

#### g++ 指令参数

1. `-w` 的意思是关闭编译时的警告，也就是编译后不显示任何 warning，因为有时在编译之后编译器会显示一些例如数据转换之类的警告，这些警告是我们平时可以忽略的
2. `-Wall` 选项意思是编译后显示所有警告
3. `-W` 选项类似 `-Wall`，会显示警告，但是只显示编译器认为会出现错误的警告，在编译一些项目的时候可以 `-W` 和 `-Wall` 选项一起使用
4. `-O3` 开启编译优化，等级为三

### main 函数参数

`argc` 是 argument count 的缩写，表示传入 `main` 函数的参数个数

`argv` 是 argument vector 的缩写，表示传入 `main` 函数的参数序列或指针，并且第一个参数 `argv[0]` 一定是程序的名称，并且包含了程序所在的完整路径

## Object

**Access to attributes and methods calls**

`.` from one object

`->` from a pointer to one object

Stack 上的内存会有系统自动分配和回收，Heap 上的内存需要手动分配和回收，否则会发生内存泄漏（memory leak）

```c++
#include "Tree.h"

int main (int argc , char* argv[]) {
  // We want to create 2 trees
  Tree a1 ; // on the stack 
  Tree* a2 = new Tree ; // in the heap
  // Ask them to draw themselves 
  a1.draw() ;
  a2->draw() ;
  // We need to explicitly request the destruction 
  // omfenttheImhageeap&-Tarlalitoecmaetnetdetlr’Ienefortmhaotuiognh the pointer a2
  delete a2 ; 
}
```

The compiler is only responsible for the lifetime of the variables you declare i.e. `Tree a1` and pointer to `Tree a2` (not the tree itself), according to their scopes.