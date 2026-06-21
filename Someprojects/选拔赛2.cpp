#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+9;        
int a[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--){
        memset(a,0,sizeof(a));
        int n,m;cin>>n>>m;
        for(int i=1;i<=m;i++){
            int x;cin>>x;
            if(a[x]==0) a[x]=1;
            else{
                cout<<"the lights are already on!"<<'\n';
                continue;
            }
            int tmp=x;int cnt=1;
            while(1){
                tmp+=x;
                if(tmp>n) break;
                if(a[tmp]==0){
                    a[tmp]=1;
                    cnt++;
                }
            }
            cout<<cnt<<'\n';
        }
        
    }
}