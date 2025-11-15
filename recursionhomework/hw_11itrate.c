#include <stdio.h>
#define N 105

// 递归函数计算字符串长度
int stringLength(char *str) {
    if (*str == '\0') {
        return 0;
    } else {
        return 1 + stringLength(str + 1);
    }
}

int main() {
    char arr[N];
    int i = 0;
    
    // 读取字符串，包括空格
    char tmp;
    while ((tmp = getchar()) != '\n' && i < N - 1) {
        arr[i] = tmp;
        i++;
    }
    arr[i] = '\0';  // 添加字符串结束符
    
    // 使用递归函数计算长度
    int cnt = stringLength(arr);
    printf("%d", cnt);
    
    return 0;
}