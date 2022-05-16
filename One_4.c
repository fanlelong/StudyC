
#include <stdio.h>
void change(int i){
    i  = 200;
}
void change1(int i);
void change2(int *i);

void changeAction(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){

    //函数， 取修改一个数（指针操作）
    int i = 100;
    printf("%d\n", i); // 100
    printf("main %p\n", &i); // main 008FFEB4
    change1(i);
    printf("%d\n", i); // 100
    change2(&i);
    printf("%d\n", i); // 1400

    int a = 100;
    int b = 200;
    changeAction(&a, &b);
    printf("交换完成后的效果： %d, %d\n", a, b);
    return  0;
}

// 函数不能写在main的上面 非要写在后面，要先声明再实现
void change1(int i){ //  这个函数传过来的i c会再创建一个跟上面的i是不一样的，地址也不一样
    i  = 300; // 即使改变这个i 传进来的主i 也是不改变
    printf("change1 %p\n", &i); // change1 008FFEAC
}

void change2(int *i){  // 这个传过来的是一个指针，指针就是内存地址，可以直接修改值
    printf("change2 %p\n", i); // 008FFEB4
    *i = 1400;
}

