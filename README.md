# StudyC
## 第一天知识点1 初步认识C
### 文件后缀的意义
*   .h  .hpp （是声明文件， 也是头文件）
*   .c  .cpp （是实现）

### 如何导入头文件
* \# include <stdio.h>   <>代表导入系统的资源  "" 代表寻找自己的头文件

### 函数主入口 只能有一个main函数
```c
int main  () {

    getchar(); // 这行代码的作用是不让程序退出。
}
```
### 打印
打印需要点位符，int-->d == 整形, double -->lf  long==整形  s==short   c == char  s == string
```c
int main  () {
    int i = 100;
    double d = 200;
    long l = 200;
    float f = 200;
    short s = 100;
    char c = 'd';

    printf("i的值是： %d\n", i);
    printf("d的值是： %lf\n", d); // lf  ==  long float
    printf("f的值是： %f\n", f);
    printf("l的值是： %d\n", l);
    printf("c的值是： %c\n", c);
    printf("str的值是： %s\n", str);
    getchar(); // 这行代码的作用是不让程序退出。
}

```

### 获取字节数
 获取字节数的api为 sizeof
 ```c
    printf("int 数据类型所占的字节数： %d\n", sizeof (int )); //4
    printf("double 数据类型所占的字节数： %d\n", sizeof (double )); // 8
    printf("char 数据类型所占的字节数： %d\n", sizeof (char )); // 1
```

### 指针
在C里面万物皆指针 指针==地址
假如定义一个int类型变量
```c
    int numbler1 = 10000;

```
如何定义指针
定义一个指针用的符号为  *

```c
    int numbler1 = 10000;
    // 定义一个地址类型用符号* 
    int * numbler1_p = &numbler1;  // &获取地址的符号
    printf("此number1变量的地址是：%p\n", &numbler1);
```

想要获取numbler1的地址怎么使用
```c
    int numbler1 = 10000;
    int * numbler1_p = &numbler1;  // &获取地址的符号
    printf("此number1变量的地址是：%p\n", &numbler1);
```

获取地址的值
```c
    int num_int = 100;
    int *num_int_p = &num_int;
   printf("num_int的值是：%d\n", *num_int_p);
```

C里面可以直接通过指针修改值
 ```c
// 通过指针修改值
int i = 100;
int *p = &i; // p存放的是i的地址
*p = 300; // 代表取出i的地址对应的值，并修改成300
printf("i的值是：%d\n", i);

```
