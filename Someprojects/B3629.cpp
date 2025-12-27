#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;int remainingsticks=0;
    for(int res=1;res<=n;res++){
        int eatensticks = res;
        int  remainingsticks = res;
        while(remainingsticks>=3){
            int tmp = remainingsticks/3;
            eatensticks+=tmp;
            remainingsticks-=tmp*3;
            remainingsticks+=tmp;
        }
        if(eatensticks>=n){
            cout<<res<<'\n';
            break;
        }
    }
}