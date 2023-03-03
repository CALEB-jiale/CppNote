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

#### main 函数参数

`argc` 是 argument count 的缩写，表示传入 `main` 函数的参数个数

`argv` 是 argument vector 的缩写，表示传入 `main` 函数的参数序列或指针，并且第一个参数 `argv[0]` 一定是程序的名称，并且包含了程序所在的完整路径

#### makefile 文件

```
main: main.o tree.o
g++ -o main main.o tree.o -Wall

main.o: main.cpp
g++ -c main.cpp -Wall

tree.o: tree.cpp tree.h 
g++ -c tree.cpp -Wall

clean:
rm -rf *.o main
```

优先写最后的可执行文件，然后依次写依赖文件，最后写 `clean`

在终端通过 `make` 指令运行 `makefile` 文件

### Object

**Access to attributes and methods calls**

`.` from one object

`->` from a pointer to one object

**`.h` 文件的创建**

Including file class declaration (.h): `#include`

Preventing one class declaration from multiple inclusion: `#define`, `#ifndef`, `#endif`, ...

#### C++ files organization

Header files (« .h ») :

* Declaration : types, constants, functions, classes (attributes and signature methods)
* Files to be included when the declared entities are needed

Implementation files (« .cpp ») :

* Definition : global variables, functions contents, class methods code
* Files to be compiled to produce intermediate binaries and finally the binary executable

#### 类的创建与删除

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

<img src="https://github.com/CALEB-jiale/CppNote/blob/main/02_03/类的创建与删除.png?raw=true" alt="类的创建与删除" style="zoom:30%;" />

### POO

#### const

The programmer can tell the compiler that a method should not change the object by contract (keyword `const`)

被 `const` 修饰的方法无法修改类的属性

#### 继承

子类继承父类的所有 attributes 和 methods，除去 private 的

**Constructors / Destructors call sequence**

创建子类时，先创建父类，再创建子类（top-down）

删除子类时，先删除子类，再删除父类（bottom-up）

**Aggregation**

Aggregation: « has a » relationship (objects “inside” others)

Aggregation is not inheritance

> A forest contains trees but is not a tree

```c++
struct Forest {
  Tree* trees;
}

struct Forest {
  Tree trees[100];
}
```

前者森林可以独立于树木存在，后者不行

#### Function overloading

Same function name with different signatures

#### Function overriding

多态性：polymorphism

Same method name with same signature (within a class hierarchy)

If polymorphism is required, `virtual` must be added to the method signature

如果不加 `virtural`，将总是调用声明的类的方法，无法实现多态

在 abstract class 中，除了要用 `virtural` 修饰，还需要添加 `= 0`

#### Key words

`override`: to indicate a virtual method is redefined

`final`: no more derived classes / virtual method redefinition

#### Type casting

Cast 的类型有两种：

1. Upcast

   - Consider an object of a derived class as an object of a base class: A pine is a Tree

   - Always possible, but no further access to derived class specificities

2. Downcast

   - Consider an object of a base class as an object of a derived class: Is a Tree a Pine?
   - 由程序员决定

Cast 的方法有四种：

1. dynamic_cast
   - 常用于类层次结构中基类和子类之间指针或引用的转换。进行上行转换（把子类的指针或引用转换成基类表示）和 static_cast 一样；进行下行转换（把基类指针或引用转换成子类表示）时，有动态类型检测，是安全的。其中指针类型转型失败时，返回 NULL；引用类型转型失败时，抛出 bad_cast 异常
2. static_cast
   - 用于类层次结构中基类和子类之间指针或引用的转换。进行上行转换（把子类的指针或引用转换成基类表示）是安全的；进行下行转换（把基类指针或引用转换成子类表示）时，由于没有动态类型检查，所以是不安全的
   - 用于基本数据类型之间的转换，如把 int 转换成 char，把 int 转换成 enum，这种转换的安全性也要开发人员来保证
3. reinterpret_cast
   - 适用于任何类型指针之间的转换。该操作不会去进行动态类型或者静态类型的检测，它仅仅将值强行赋值过去。从某种意义上对编译器进行了一种欺骗，同时也带来了很强的不安全性，要慎重使用
4. const_cast
   - 去除修饰在对象上的 `const` （想去掉 `const` 时，只能用它）

## 02_10

### Copy constructor

Shallow copy mechanism 只会复制原 Object 中的一切数据，如果原 Object 中有指针，则两个 Object 的指针指向同一片内存。如果想要把指针内容也复制，就需要实现 deep copy mechanism



### Affectation operator

The equal operator behaves like the default copy mechanism. To solve this issue, we need to overload the default “=” operator.

### rvalue 与 lvalue



## 02_17

### Questions

1. 为什么重写诗不需要指明类型的不同
2. 为什么不要总是通类的

### Templates

#### Templates functions

**Goal** : Do not write similar C++ code several times, when only the entity types change

**Keywords**

1. **template** : indicates the compiler how to create functions having the same code but operating on generic object types
2. **typename** : gives a « name » to the generic type

```c++
template <typename T>
T min (T a , T b) {
  return a > b ? b : a ;
}
```

当执行一下代码：

```c++
double c = min(10.4, 23.5); 
int d = min(10, 23);
```

- two functions « min » are written down by the compiler

  ```c++
  double min_double (double, double); 
  int min_int (int, int);
  ```

- each `min` function deals with one specific type: double then int

- all checking performed when compiling, **not at runtime**

执行以下代码将会出现编译错误：

```c++
double c = min (10.4, 23);
```

Solution: tell the compiler to produce and use a specific templated function

```c++
deol’uInbfolrmeatiocn = min<double> (10.4, 23);
```

**Explicit template specialization** (partial or full) : OK

```c++
template <>
string min (string a , string b) {
  return a.length() > b.length() ? b : a ; }
```

The compiler selects the *most specific version*

```c++
min (5 , 10) ;
min (4.5 , 8.75) ;
min ("tomate" , "chou")
```

The compiler deals with overloading first, then selects the most specific template version

#### Templates classes

**Goal** : Avoid useless redundancies while authorizing specialization for **class** definition

```c++
template <typename T , int N = 2>
class Point {
  T v[N];
}

Point<double,3> P; 
Point<int,2> I;
```

```c++
void print () { }
template <typename T, typename... Types>
void print (const T& firstArg , const Types&... args) {
  cout << firstArg << endl ;
  print(args...);
}
```

### STL

#### Container

#### Algorithm

#### Iterator

```c++
Container<Shape> C ;
for (Container<Shape>::iterator it = C.begin() ; it != C.end() ; ++it) {
  std::cout << *it << std::endl ;
}
```

## 02_24

### Smart Pointers

### 简要解释

在 C++ 中，指针是一种非常有用但也很容易出错的语言特性。在程序中使用指针时，需要手动管理内存的分配和释放，这很容易导致内存泄漏和悬空指针等问题。为了避免这些问题，C++11 引入了智能指针（smart pointer）。

智能指针是一种封装了原始指针的类，它能够自动管理内存分配和释放。使用智能指针时，可以避免手动调用 `new` 和 `delete` 等操作，从而减少出错的机会。智能指针通过使用引用计数来跟踪指向一个对象的所有指针，当引用计数变为零时，智能指针会自动释放对象的内存。

C++11 中有三种类型的智能指针：

1. `unique_ptr`：只能有一个指针指向它所管理的对象，因此不能进行复制或赋值操作，但可以通过移动语义进行转移拥有权。
2. `shared_ptr`：可以有多个指针共享它所管理的对象，使用引用计数来管理内存，当引用计数为零时释放内存。
3. `weak_ptr`：是一种特殊的 `shared_ptr`，它不会增加引用计数，因此不会阻止对象的释放，但可以用来检查对象是否已经被释放。

使用智能指针可以有效地避免内存管理问题，但需要注意的是，智能指针也并非完美无缺，它们可能会引入循环引用的问题，导致内存泄漏。因此，在使用智能指针时，需要仔细考虑其生命周期和所有权的管理，以确保程序的正确性和效率。

**La durée de vie des objets créés dynamiquement**

Création : **explicite** ► allocation de mémoire sur le tas (via `new`)

Destruction : doit aussi être **explicite** (lorsque la référence sur l'objet sort de la portée) ► libération explicite de la mémoire (via `delete`)

