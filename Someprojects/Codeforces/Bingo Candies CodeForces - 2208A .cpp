#include <bits/stdc++.h>
using namespace std;
int dic[10005];
int main(){
    int t;cin>>t;
    while(t--){
        memset(dic,0,sizeof(dic));
        int n;cin>>n;
        bool flag = false;
        for(int i=1;i<=n*n;i++){
            int x;cin>>x;
            dic[x]++;
            if(dic[x]>n*n-n){
                flag = true;
            }
        }
        if(n==1) {
            cout<<"NO"<<'\n';
            continue;
        }
        if(flag) cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';
    }
}
