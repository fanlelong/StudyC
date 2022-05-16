#include <stdio.h>
int mainO1(){
    // java 万物皆对象
    // C C++ 万物皆指针 函数 对象 基本类型 结构体 都是地址
    // Linux 万物皆文件

    // 指针 == 地址
    int numbler1 = 100000;

    // %p == 地址输出的点位
    printf("此number1变量的地址是：%p\n", &numbler1);

    return 0;
}

/**
 * 上面代码做一个详细分析：
 * 当执行到main方法时，main方法要进栈
 * 我们写了这么一行代码 int numbler1 = 100000;  那么 numbler1 这个就是我们定义的一个int类型的一个别名 他的值为100000
 * 这时就会有一个内存地址，假设为1000H  然后numbler1就会的指向这个内存地址1000H
 * 所以我们打印numbler1的内存地址就会是1000H
 */
