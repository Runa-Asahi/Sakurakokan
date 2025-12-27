#include <bits/stdc++.h>
using namespace std;
int res[100],length;//全局变量res
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;int lenres=1;
    for(int i=1;i<=n;i++){//从1到n的总的加和
        int ans[100];int len=1;
        memset(ans,0,sizeof(ans));
        ans[1]=1; // 初始化阶乘为1
        for(int j=1;j<=i;j++){//高精度阶乘的累乘(对于每个j进行高精×低精)
            int carry=0;//进位
            for(int k=1;k<=len;k++){//1次乘法
                int tmp = ans[k]*j+carry;
                ans[k] = tmp%10;
                carry = tmp/10;
            }
            while(carry>0){
                ans[++len] = carry%10;
                carry /= 10;
            }
            // 移除这个循环 - 阶乘中不应该有末尾0
            // while(len>1 && ans[len]==0) len--;
        }
        length = max(len,lenres);
        int carry=0;
        for(int k=1;k<=length;k++){ // 改为k，避免与外部i冲突
            int tmp = ans[k]+res[k]+carry;
            res[k] = tmp%10;
            carry = tmp/10;
        }
        while(carry>0){
            res[++length] = carry%10;
            carry /= 10; 
        }
        // 移除这一行 - 这是错误的
        // length *= 2;
        // 添加正确的长度更新
        lenres = length;
    }
    for(int i=length;i>=1;i--){
        cout<<res[i];
    }
    return 0;
}