
#include <stdio.h>

int mainT6() {
    // 通过指针修改值
    int i = 100;
    int *p = &i; // p存放的是i的地址
    i = 200;
    printf("i的值是：%d\n", i);
    *p = 300; // 代表取出i的地址对应的值，并修改成300
    printf("i的值是：%d\n", i);
    return 0;
}