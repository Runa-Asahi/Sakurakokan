#include <stdio.h>

// 把 gcd 改为接受参数，不修改全局变量
int gcd(int a, int b){
    while(b != 0){
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

// lcm 也接受参数
void lcm(int a, int b){
    // 先计算最大公约数
    int g = gcd(a, b);
    // 使用公式：(a * b) / gcd(a, b)
    // 注意先转为 long long 防止溢出
    long long res = ((long long)a * b) / g;
    printf("%lld", res);
}

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    
    // 这里的 a 和 b 传进去，不会被修改
    printf("%d ", gcd(a, b)); 
    
    // 这里的 a 和 b 依然是原始输入的值
    lcm(a, b);
    
    return 0;
}