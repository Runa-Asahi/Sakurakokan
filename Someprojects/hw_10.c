#include <stdio.h>

// 递归函数：打印正整数的各位数字
void printDigits(int n) {
    // 基本情况：如果数字小于10，直接打印并返回
    if (n < 10) {
        printf("%d ", n);
        return;
    }
    
    // 递归情况：先打印高位数字，再打印当前位
    printDigits(n / 10);  // 递归处理去掉最后一位的数字
    printf("%d ", n % 10);  // 打印最后一位数字
}

int main() {
    int num;
    scanf("%d", &num);
    
    printDigits(num);
    
    return 0;
}