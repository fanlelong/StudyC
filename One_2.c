#include <stdio.h>

int main() {
    // 先定义一个别名为num_int的int类型 并 赋值为100
    int num_int = 100;

    // 再定义一个别名为num_dou的double类型 并赋值为200;
    double num_dou = 200;
    // 打印
    printf("num_int的值是：%d\n", num_int);
    printf("num_dou的值是：%lf\n", num_dou);

    // 取出num_int的地址
    int *num_int_p = &num_int;

    // 打印地址num_int_p对应的值
    printf("num_int的值是：%d\n", *num_int_p);
}

/**
 *  int * num_int_p = &num_int; 这行代码理解
 *  int* 代表定义一个指针 他存放的永远是一个 内存地址
 *  num_int_p是指针的一个别名也叫变量
 *
 *  &num_int 取num_int的地址
 *
 *  *num_int_p 取出num_int存放内存地址 所对应的值
 */
