#include <bits/stdc++.h>
using namespace std;    
string mid,last;
void dfs(int m1,int m2,int l1,int l2){
    if(m1>m2 || l1>l2){
        return;
    }
    int root=0;
    for(int i=m1;i<=m2;i++){
        if(mid[i]==last[l2]){
            root = i;
            break;
        }
    }
    cout<<mid[root];
    dfs(m1,root-1,l1,l1+root-1-m1);
    dfs(root+1,m2,l1+root-m1,l2-1);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>mid>>last;
    dfs(0,mid.length()-1,0,last.length()-1);
}