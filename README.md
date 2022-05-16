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
### 函数
定义一个函数
```c
void change(int i){}

```
注意点： 定义一个函数要写在main函数上面
错误写法,如下，把change函数写在了main下面
```c
int main () {
    int i = 100;    
    change(i);
}
void change(int i){
    
}

```
正确写法1：
```c
void change(int i){
    
}
int main () {
    int i = 100;    
    change(i);
}

```

正确写法2：
```c
// 先声明
void change(int i);
int main () {
    int i = 100;    
    change(i);
}

// 再实现
void change(int i){
    
}
```
如果通过函数修改值

下面代码是改变不了i的值 
```c
void change(int i);
int main () {
    int i = 100;
    printf("change前： %p\n", &i); // 008FFEB4
    change(i);
    printf("change后： %p\n", &i); // 008FFEB4
}

void change(int i){ // 在这里会创建一个新的i 所以函数里i的地址和传进来i的地址是不一样的
    i = 100;
    printf("change1 %p\n", &i); // 008FFEAC 这个i和main函数的i是没有半毛钱关系的
}
```

下面代码是可以改
```c
void change(int *i);
int main () {
    int i = 100;
    printf("change前： %p\n", &i); 
    change(&i);
    printf("change后： %p\n", &i);
}

void change(int *i){ 
    *i = 1400; // 取出地址的值，然后赋于1400
    printf("change1 %p\n", &i);
}
```

C里面二个值交换
```c
void changeAction(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 100;
    int b = 200;
    changeAction(&a, &b);
    printf("交换完成后的效果： %d, %d\n", a, b);
    return 0;
}

```

### 多级指针
多级指针
```c
// todo 指针存放的是内存地址，但是指针也有内存地址
int main() {
    int num = 999;
    // 定义一个一级指针
    int * num_p = &num;
    
    // 定义一个二级指针
    int * num_p_p = &num_p;
    
    //定义三级指针： 
    int *** num_p_p_p = &num_p_p;
    printf("num_p的地址是：  %p, num_p_p的地址是： %p\n", num_p, num_p_p);
    // 获取多级指针的指
    printf("num_p_p的值是： %d\n", **num_p_p);
    printf("num_p的地址是：  %p, num_p_p的地址是： %p\n", num_p, num_p_p);
    return 0;
}

```
### 数组
```c
//  定义一个数组
int arr[] = {1,2,3,4}; // []一定要在变量的后面
```
* 遍历数组
```c
int i = 0;
for (i = 0; i < 4; ++i) {
    printf("%d\n", arr[i]);
}

```

* 数组的特殊性

数组本身就是一个地址，所以上面的 arr 和 &arr相等

数组的第一个值的地址也是指向数组本身， &arr[0]  == &arr ==arr

*  指针挪动
```c
int arr[] = {1,2,3,4}; // []一定要在变量的后面
// 打印第一个值 直接取数组的值就可以 *arr
printf("打印数组的值： %d\n", *arr); //输出： 打印数组的值： 1 证实就是第一个

// 打印第二个，可以用到指针挪动法来打印
int *arrP = arr;
arrP++; // 指针挪动，+1代表移动到下一个地方
printf("打印数组的值arrP【2】： %d\n", *arrP); // 打印数组的值arrP【2】： 2 

// 也可以连续挪动二个位置 比如从第二个挪动到第四个
arrP+=2;

// 再挪动到第一个
arrp-=3;

// 指针是没有索引越界这一说法

```

* 数组内存分配

跟Java一 样C里面内存也是连续分配的

## 函数指针
函数本身就是指针，当我们定义了一个函数的时候他就有个内存地址，所以函数也可以当做参数传递

函数指针在Java中类似接口回调
```c
#include <stdio.h>

// 先定义下面二个方法
void add (int num1, int num2) {
    printf("num1+num2 = %d\n", num1 + num2);
}

void mins (int num1, int num2) {
    printf("num1-num2 = %d\n", num1 - num2);
}
// 再定义一个特殊的方法
void opreate(void (*method) (int,int), int num1, int num2){
    // void (*method) 声明一个函数指针，可以传一个匹配的函数过来  void 返回值;  (*method) 函数名;  (int, int) 二个参数 method可以自由命名
    method(num1, num2); // 执行传进来的方法， 并把num1,和num2当做参数给传进去。
}
int main () {
    // 函数的指针在Java中类似接口回调
    // 函数本身就是一个指针
    opreate(add,10,20);
    //上面一行代码，是把方法add传进来了，刚刚好add方法方法参数也是二个Int， 然后到opreate方法里执行了method也就是add函数，并100，200传入到add方法中，也就执行了add方法
    //  输出结果： num1+num2 = 30

    // 上面说了函数也指针，数组也是一样，那是不是他也有数组一样的特性也就是 add 和&add是不是一样的，答案是肯定的
    printf("&add %p, add %p\n", &add , add); // &add 00F81168, add 00F81168  一样
}

```

函数当作参数的规范

```c
#include <stdio.h>

void callBackMethod(char *fileName, int curdrent, int total) {
    printf("%s图片压缩的进度是： %d/%d\n", fileName, curdrent, total);
}
/**
 * 压缩方法
 * 定义函数指针： 返回值（*名称）(int , double)
 * @param fileName
 */
void compress(char *fileName, void(*callBackP)(char *, int, int)) {
    callBackP(fileName, 5, 100); // 回调给外部，压缩的进度情况
}

int mian () {
	// 规范是先定义一个函数指针出来如下 ,要不能在方法里 操作了原方法地址可能就会出问题
	void (*call) (char *, int , int);
	//然后将call 赋于地址
	call = callBackMethod;
	// 调用压缩方法
	compress("derry.png", call);
}

```
## C里面内存开辟
### 静态开辟

```c
// Java布尔类型定义为boolean, 而C中只有0和1， 非0即true， 0就是false
int arr[5];// 静态开辟
// 下面为数组赋值
for (int i = 0; i < 5; ++i) {
    arr[i] = i;
    printf("%d, %p \n", *(arr + i), arr + i);
}
```
静态开辟内存也要注意， 不是随便开辟多大都可以，假如下面

```c
int arr[10*1024*1024]; // 这是开辟了一个40M内存，因为在栈里开辟所以会直接崩溃，栈溢出
// 因为在栈区，占用内存的大小的最大值为2M,当然有些平台会不一样，但是都不会很大

```
### 动态开辟
动态开辟内存方法malloc，是在堆区开辟的。

```c
// 动态开辟内存方法malloc，是在堆区开辟的。
int * arr = malloc(1*1024*1024); // 开辟1M的堆内存，
// 堆里开辟的内存使用后一定要释放，这跟Java是不一样的
free(arr); // 释放内存 执行完后 arr就变成了悬空指针
arr=NULL; // 释放之后 需要指向NULL，
int *p; // 这是一个野指针，是没有地址的。
```

如果动态开辟了一块 内存，这时候想要加内存，这个时候realloc就派上了用场

一般情况下，新的数组指向的和之前的地址是一样的，但是也有少数情况下会返回新的地址，如果返回新地地址的话，旧的地址也会跟着变。

如果返回的为NULL ，则表示开辟新的大小失败，
```c
int num = 10;
int arr  = malloc(sizeof(int)  * num);
// 假如这时候想要再加10个
int newAddNum = 10;
// void *realloc (void * 前面 开辟的指针， size_t总大小)
int *arr2 = realloc(arr, sizeof(int) * (num + newAddNum));
// 一般情况下，新的数组指向的和之前的地址是一样的，但是也有少数情况下会返回新的地址，如果返回新地地址的话，旧的地址也会跟着变。
// 如果返回的arr2为NULL ，则表示开辟新的大小失败，
// 业务做完都得做堆内存释放,但是不能重复释放， 所以得做处理
if (arr2){
	free(arr2);
	arr2 = NULL;
	arr = NULL;
} else {
	free(arr);
	arr = NULL;
}

```


## C里面字符串
### 写法
* 方式一： char str[] = {'H', 'e', 'l', 'l', 'o', '\0'}; // 加上'\0'的作用是打印有个结尾
* 方式二： char *str2 = "Hello"; // 这名话会隐式加了\0, 所以这个不需要在后面加\0
### 获取字符串长度
* 方式一
```c
int getLen1(char *string) {
    int count = 0;
    while (*string) { // *string !='\0' 判断的是\0而不是0  就是一直遍历下去  *string取string的值
        string++; // 指针挪动
        count++;
    }
    return count;
}
char string[] = {'a', 'b', 'c', 'd', 'e', 'f', '0', '\0'};
int len = getLen1(string);

```
* 方式二

```c
char string2[] = {'a', 'b', 'c', 'd', 'e', 'f', '0', '\0'};
int len2 = sizeof string2 / sizeof(char);
```

### 字符串转换
```c
char *num = "1";
// 将num转为int类型
int c_int = atoi(num);
```

### 字符串比较

```c
char * test1 = "Lucy";
char * test2 = "lucy";
// 使用系统API
int result_2 = strcmp(test1, test2); // 它是区分大小写
// result_2如果返回0 则代表相等，

int result_3 = strcmpi(test1, test2); // 它是不区分大小写

```


### 字符串查找及获取位置

```c
char *text = "name-is-Lucy";
char * subtext = 'i';
char * pop = strstr(text, subtext);
if (pop) { // 非null 就查找到了
    printf("查找到了，pop的值是：%s\n", pop); // 会把找到的后面一截全部打印出来  查找到了，pop的值是：is-Lucy
}

// 获取位置
int index = pop - text; // pop =  is-Lucy,  text = name-is-Lucy 直接指针减法就可以
```
### 字符串拼接

```c
// 字符串拼接得定义一个容器
char destination[25];// 25容器大小 这个是写死的。
// 定义几个字符串
char *blank = "--到--", *CPP = "C++", *Java = "java";
// 使用api strcpy
strcpy(destination, CPP);//先copy到数组里，
strcat(destination, blank); // 然后再拼接
strcat(destination, Java); // 然后再拼接
printf("拼接后的结果： %s\n", destination);

```
### 大小写转换

```c
void lower(char *dest, char *name) {
    printf("name： %p\n", &name);
    char *temp = name;
    while (*temp) {
        *dest = tolower(*temp);
        temp++; // 挪动指针
        dest++;// 存储的也要挪动，目是的挪动一个储存一个
    }
    *dest = '\0'; // 避免打印系统值
    printf("name： %p\n", &name);
}

char *name = "Hello World";
// 先定义结果
char dest[20];
lower(dest, name);
printf("小写转换后的结果是： %s\n", dest);
printf("name： %p\n", &name);
```
### 字符串的截取

```c
void subString(char *result, char *str, int start, int end) {
    char *temp = str + start;
    int i = start;
    for (; i < end; i++) {
        *result = *(temp+i);
        result++;
    }
    *result = '\0';
}

char *string = "My-name-is-Hanmeimei";
char *result[30];
subString(result, string, 2, 6); // 截取第二到第六个字符
printf("截取后的值为: %s\n", result);
```


## 结构体
结构体相当于Java里的对象， 关键字为struct
### 定义结构体
* 方式一
```c
struct Dog {
    // 下面相当于Java里的成员变量
    char name[10]; // 这种定义需要用到strcpy方法
    int age;
    char sex;
};

```
* 方式二
```c
struct Person {
    char * name; // 这个可以直接赋值
    int age;
    char sex;
};

```
使用

```c
struct Dog {
    // 下面相当于Java里的成员变量
    char name[10]; // 这种定义需要用到copy方法
    int age;
    char sex;
};

struct Person {
    char * name; // 这个可以直接赋值
    int age;
    char sex;
};

int main () {
    struct Dog dog;   // 这样写完，成员是没有初始化，成员默认值为系统值 这跟Java是不一样的
    // 方式一写法的赋值
    strcpy(dog.name, "暗战风云");
    dog.age = 3;
    dog.sex = 'G';
    
    // 方式二写法的赋值
    ppp0.name = "Printf";
    ppp0.age = 22;
    ppp0.sex = 'M';
    return 0;
}

```

### 结构体嵌套结构体，相当于Java类嵌套类

```c
struct Study {
    char *studyContent;  // 学习内容
};

struct Student {
    char name[10];
    int age;
    char sex;
    struct Study study;
    struct Play {
        char *playContent;
    } wan;
};

int main () {
	// 创建赋值
	struct Student student =
	            {"李元霸", 88, 'G',
	             {"学习C"},
	             {"王者荣耀"}
	            };
	
	    printf("name :%s, age: %d, sex:%c, study:%s, wan:%s\n", student.name, student.age, student.sex,
	           student.study.studyContent, student.wan.playContent);
	}
    return 0;
```

结构体获取成员变量是用  . 这个符号获取里面成员变量

### 结构体指针
结构体指针获取结构体里的成员变量用的符号为  ->
```c
// 定义一个结构体
struct Cat {
    char name[10];
    int age;
};

int main () {
    // 静态开辟 栈区开辟
    // 创建一个结构体
    struct Cat cat = {"xiao hua mao", 2};
    
    // 定义结构体指针
    // 有些平台可以这样写  Cat * catp = &cat;
    // 但是Clion一定要加struct关键字
    struct Cat * cat_p = &cat; 
    
    
    
    // 动态开辟 堆区开辟
    // VS写法 ： Cat * cat2 = (Cat *)malloc(sizeof(Cat);
    // Clion写法
    struct Cat *cat2 = malloc(sizeof(struct Cat));// 差别是Clion需要加struct
    // 赋值
    strcpy(cat2->name, "小花猫堆区");
    cat2->age = 15;
    printf("Cat2 name: %s, age: %d\n", cat2->name, cat2->age);
    // 堆区记得释放
    free(cat2);
    cat2 = NULL;
    return 0;
    
}
```

### 结构体数组
定义结构体数据跟常规数组一样
```c
struct Cat3 {
    char name[10];
    int age;
};

int main () {
	    // 栈区， 静态开辟
    struct Cat3 cat[10] = {
            {"1111", 1},
            {"222",  2},
            {"333",  3},
            {"444",  4},
	
	// 为数组的第9个赋值
	//    cat[9 ] =   {"9999", 1}  VS写法,  下面是clion写法
	struct Cat3 cat9 = {"9999", 9};
	cat[9] = cat9;
	// 还有一种写法
	*(cat + 9) = cat9; //  cat[9] = cat9; ===*(cat + 9) = cat9; 二个一样
	printf("Cat9 name: %s, age: %d\n", cat9.name, cat9.age);

	// 动态开辟 堆区
	struct Cat3 *cat2 = malloc(sizeof(struct Cat3) * 10);
	// 赋值  指针默认指向首元素地址
    strcpy(cat2->name, "小花猫");
    cat2->age = 123;
    printf("小花猫 name: %s, age: %d\n", cat2->name, cat2->age);
    free(cat2);
    cat2 = NULL;
	return 0;
}
```

### 适配多平台的结构体别名  关键字typedef

```c
// 首先定义一个结构体
struct Worker_ {
    char name[10];
    int age;
    char sex;
};

```
给上面结构体定义一个别名 Worker_
```c
typedef struct Worker_ Worker_;
```

定义一个结构体指针别名 Worker
```c
typedef struct Worker_  * Worker;
```

使用
```c
int main ()  {
    // 首先没有定义别名时是这样创建的 
    struct Worker_ *worker = malloc(sizeof(struct Worker_));
    // 所以使用别名玩法
    Worker_ *worker2 = malloc(sizeof(Worker_));
    Worker worker1 = malloc(sizeof(Worker));
    return 0;
}
```

高级写法

```c
// 系统写法
typedef struct {
    int version;
} DAO;

int main () {
	DAO *dao = malloc(sizeof(DAO));
}
```
## C里面文件的基本操作
### 打开文件 fopen
fopen (参数1： 文件路径， 参数2： 模式（读r, 写w，rb作为二进制读，wb作为二进制文件写）)

### 读取文件数据
```c
int main () {
    // 文件路径
    char *fileNamePath  =  "D:\\Temp\\DerrFile.txt";
    
    // 调用打开文件api
    FILE *file = fopen(fileNamePath, "r");
    // 判断文件是否被打开，因为读取的这个文件可能不存在
    if (!file) {
        printf("文件打开失败，路径%s的文件有问题", fileNamePath);
        exit(0); // 退出程序
    }
    // 开始读取文件内容
    // 首先需要定义一个缓存区域也叫容器
    char buffer[10];
    // 读取文件API fgets(buffer, 10, file) 第一个参数，缓冲区， 第二个参数：读取的长度： 第三个参数： 文件的指针
    while (fgets(buffer, 10, file))
        printf("%s", buffer);
    }
    
    // 使用完记得关闭文件
    // 关闭文件 JAVA关闭流 
    // todo 最好是fopen之后就写fclose然后在中间写代码
    fclose(file);
}

```

### 写入数据到文件

```c
char *fileNamePath = "D:\\Temp\\DerrFileW.txt";
// 如果模式是w 会自动生成文件 0kb
FILE *file = fopen(fileNamePath, "w");
if (!file) {
    printf("文件打开失败，路径%s的文件有问题", fileNamePath);
    exit(0); // 退出程序
}
fputs("Derry Success run...", file);
// 关闭文件 JAVA关闭流
fclose(file);

```

### 文件的复制

```c
// 源文件
char *fileNamePath = "D:\\Temp\\DerrFileW.txt";
// 复制的目标
char *fileNameStrCopy = "D:\\Temp\\DerrFileW2.txt";

// 复制文件需要用到二进制读  rb
FILE *file1 = fopen(fileNamePath, "rb");
// 需要向fileNameStrCopy写入数据所以为wb
FILE *fileCopy = fopen(fileNameStrCopy, "wb");
// 逻辑处理
if (!file1 || !fileCopy) {
    printf("文件打开失败，路径%s的文件有问题", fileNamePath);
    exit(0); // 退出程序
}
// 定义一个Buff
int buffer[512]; // 512*4 = 2048字节
int len; // 每次读取的长度
// fread: (参数1： 容器buff; 参数2：每次偏移多少 ；参数3： 容器大小)
// sizeof(buffer) / sizeof (int)=== 512
while ((len = fread(buffer, sizeof(int), sizeof(buffer) / sizeof(int), file1)) != 0) {
    fwrite(buffer, sizeof(int), len, fileCopy);
}
```

### 文件大小的获取

```c
char *fileNameStr = "D:\\Temp\\DerrFileW.txt";
FILE *file = fopen(fileNameStr, "rb");

// 没有专门的获取文件大小的API
// 方法 读取头指针 头指针挪动位置 挪动到最后，就可以求得文件大小`
fseek(file, 0, SEEK_END); // file 就有了更丰富的值，给你的 file指针赋值，挪动的记录信息
// 读取 刚刚给file赋值的记录信息
long file_size = ftell(file);
printf("%s文件的字节大小是：%ld\n", fileNameStr, file_size);
fclose(file);
```

## 文件加解密
### 加密思路
加密 === 破坏文件
方式一： 全部加密， 对每一个字节都处理
方式二： 部分加密，把某一部分内容拿出来处理
如何破坏呢，可以最简单的思路，就是把取出来的数据异或某一个值。

### 解密思路
解密 === 将破坏过的文件还在原
在加密思路中异或的值再异或一次

###简单加密代码实现

```c
 char *fileNameStr = "D:\\Temp\\IMG.png"; // 来源
 char *fileNameStrEncode = "D:\\Temp\\IMG_encode.png"; // 加密后的目标文件
 FILE *file = fopen(fileNameStr, "rb");
 FILE *fileEncode = fopen(fileNameStrEncode, "wb");
 if (!file || !fileEncode) {
     printf("文件打开失败，路径%s的文件有问题", fileNameStr);
     exit(0); // 退出程序
 }

// 加密
int c; // 接收读取的值   fgetc(file) 这个函数的返回值EOF = end of file
while ((c = fgetc(file))!= EOF) {
	// 开始加密流程并这写入数据
	fputc(c ^ 5, fileEncode);  //写入到fileEncode里
}
fclose(file);
fclose(fileEncode);

// 解密
char *fileName1 = "D:\\Temp\\IMG_encode.png"; // 来源
char *fileNameStrDecode = "D:\\Temp\\IMG_Decode.png"; // 解密后的目标文件
FILE *file1 = fopen(fileName1, "rb");
FILE *fileDecode = fopen(fileNameStrDecode, "wb");
if (!file1 || !fileDecode) {
    printf("文件打开失败，路径%s的文件有问题", fileNameStr);
    exit(0); // 退出程序
}
int c1;
while ((c1 = fgetc(file1)) != EOF) {
    // 开始做解密操作
    fputc(c1 ^ 5, fileDecode);  //写入到fileEncode里
}
fclose(file1);
fclose(fileDecode);

```

###  复杂一点的加密代码实现

```c
#include <stdio.h>
#include <stdlib.h>
#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

int main() {
    char *fileNameStr = "D:\\Temp\\IMG.png"; // 来源
    char *fileNameStrEncode = "D:\\Temp\\IMG_encode.png"; // 加密后的目标文件
    FILE *file = fopen(fileNameStr, "rb");
    FILE *fileEncode = fopen(fileNameStrEncode, "wb");
    if (!file || !fileEncode) {
        printf("文件打开失败，路径%s的文件有问题", fileNameStr);
        exit(0); // 退出程序
    }

    // 密钥
    char *password = "123456";

    // todo 加密
    int c;// 接收读取的值   fgetc(file) 这个函数的返回值EOF = end of file
    int index = 0;
    int pass_len = strlen(password);
    while ((c = fgetc(file)) != EOF) {
        // 开始做加密操作
        char item = password[index % pass_len];
        index++;
        printf("item%c\n", item);
        fputc(c ^ item, fileEncode);  //写入到fileEncode里
    }

    fclose(file);
    fclose(fileEncode);

    char *fileName1 = "D:\\Temp\\IMG_encode.png"; // 来源
    char *fileNameStrDecode = "D:\\Temp\\IMG_Decode.png"; // 解密后的目标文件

    FILE *file1 = fopen(fileName1, "rb");
    FILE *fileDecode = fopen(fileNameStrDecode, "wb");
    if (!file1 || !fileDecode) {
        printf("文件打开失败，路径%s的文件有问题", fileNameStr);
        exit(0); // 退出程序
    }


    int c1;
    index = 0;
    while ((c1 = fgetc(file1)) != EOF) {
        // 开始做解密操作
        char item = password[index % pass_len];
        index++;
        fputc(c1 ^ item, fileDecode);  //写入到fileEncode里
    }

    fclose(file1);
    fclose(fileDecode);
    return 0;
}

```
