#include <bits/stdc++.h>
using namespace std;
string mid,pre;
void dfs(int m1,int m2,int p1,int p2){
    if(m1>m2 && p1>p2){
        return;
    }
    char root=pre[p1];
    for(int i=m1;i<=m2;i++){
        if(mid[i]==root){
            dfs(m1,i-1,p1+1,p1+i-m1);
            dfs(i+1,m2,p1+i-m1+1,p2);
            cout<<root;
            break;
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>mid>>pre;
    dfs(0,mid.size()-1,0,pre.size()-1);
}

