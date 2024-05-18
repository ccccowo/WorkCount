#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <ctype.h>  
#define _CRT_SECURE_NO_WARNINGS

int main(int argc, char* argv[]) {
    // 检查参数数量  
    if (argc != 3) {
        printf("参数数量不正确");
        return 1;
    }

    // 打开文件  
    FILE* file = fopen(argv[2], "r");
    if (!file) {
        perror("文件打开错误！");
        return 1;
    }

    // 初始化计数  
    long charCount = 0;
    long wordCount = 0;
    int inWord = 0;

    // 读取并统计  
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        // 字符计数  
        charCount++;

        // 单词计数  
        if (isspace(ch) || ch == ',') {
            if (inWord) {
                wordCount++;
                inWord = 0;
            }
        }
        else if (!inWord) {
            inWord = 1;
        }
    }

    // 如果最后一个字符是单词的一部分，则增加单词计数  
    if (inWord) {
        wordCount++;
    }

    // 根据参数输出结果  
    if (strcmp(argv[1], "-c") == 0) {
        printf("字符数：%ld\n", charCount);
    }
    else if (strcmp(argv[1], "-w") == 0) {
        printf("单词数：%ld\n", wordCount);
    }
    else {
        printf("Invalid parameter: %s\n", argv[1]);
    }

    // 关闭文件  
    fclose(file);

    return 0;
}