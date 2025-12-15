#include <bits/stdc++.h>
using namespace std;
vector<int> v;int n,l,r;
vector<int> temp;int cnt=0;
void dfs(int idx,int sum){
    if(idx==n+1){
        return;
    }
    if(sum>=l && sum<=r){
        cnt++;
    }
    for(int i=idx;i<n;i++){
        temp.push_back(v[i]);
        sum+=v[i];
        dfs(i+1,sum);
        temp.pop_back(); 
        sum-=v[i];
    }
}
int main(){
    cin>>n>>l>>r;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        v.push_back(a);
    }
    dfs(0,0);
    cout<<cnt<<endl;
    return 0;
}