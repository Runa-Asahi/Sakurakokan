#include <stdio.h>
#include <limits.h>

// 最简洁的递归实现
int maxElement(int arr[], int n) {
    if (n == 1)  // 基线条件：只有一个元素
        return arr[0];
    
    // 递归情况：第一个元素 vs 剩余元素的最大值
    int maxRest = maxElement(arr + 1, n - 1);
    return (arr[0] > maxRest) ? arr[0] : maxRest;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("%d", maxElement(arr, n));
    return 0;
}