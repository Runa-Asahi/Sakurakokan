#include <bits/stdc++.h>
using namespace std;
int a[30],b[60],dic[30];
int main(){
    int t;cin>>t;
    while(t--){
        memset(dic,0,sizeof(dic));
        int n,k;cin>>n>>k;
        for(int i=1;i<=k;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            cin>>b[i];
            dic[b[i]]++;
        }
        int cnt=0;
        for(int i=1;i<=k;i++){
            cnt+=(k+1-i)*dic[i];
        }
        cout<<cnt<<'\n';
        while(1){
            int maxnum=0,maxpos=0;
            bool flag = false;
            for(int i=1;i<=n;i++){
                if(b[i]==k+1) continue;
                flag = true;
                if(maxnum<b[i]) {
                    maxnum = b[i];
                    maxpos = i;
                }
            }
            if(!flag) break;
            b[maxpos]++;
            cout<<maxpos<<" ";
        }
        cout<<'\n';
    }
}