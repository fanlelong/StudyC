// todo 加解密
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