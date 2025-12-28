#include <bits/stdc++.h>
using namespace std;int n,r;
int arr[25];
void dfs(int depth,int i){
    if(depth==r){
        for(int m=0;m<r;m++) cout<<setw(3)<<arr[m];
        cout<<'\n';
        return;
    }
    for(int j=i+1;j<=n;j++){
        arr[depth]=j;
        dfs(depth+1,j);
        arr[depth]=0;
    }
    return;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>r;
    dfs(0,0);
    return 0;
}