#include <bits/stdc++.h>
using namespace std;
int n;
int mem[30][30];
int dfs(int stknum,int numbers){
    if(numbers==0){
        return 1;
    }
    int cnt=0;
    if(mem[stknum+1][numbers-1]) cnt+=mem[stknum+1][numbers-1];
    else {
        int tmp = dfs(stknum+1,numbers-1);
        cnt += tmp;
        mem[stknum+1][numbers-1]=tmp;
    }
    if(stknum>0) {
        if(mem[stknum-1][numbers]) cnt+=mem[stknum-1][numbers];
        else{
            int tmp = dfs(stknum-1,numbers);
            cnt += tmp;
            mem[stknum-1][numbers]=tmp;
        }
    }
    return cnt;
}
int main(){
    cin>>n;
    int cnt=dfs(0,n);
    cout<<cnt<<'\n';
}