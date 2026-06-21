#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int x,y;cin>>x>>y;
        int sum = x-y;
        if(sum==0){
            cout<<1<<'\n';
            for(int i=1;i<=x;i++){
                cout<<1<<" ";
            }
            if(y==0) cout<<'\n';
            for(int i=x+1;i<=x+y;i++){
                cout<<-1<<((i==(x+y))?"\n":" ");
            }
        }
        else{
            int t = abs(x-y);
            int cnt=0;
            for(int i=1;i<=t;i++){
                if(t%i==0) cnt++;
            }
            cout<<cnt<<'\n';
            for(int i=1;i<=x;i++){
                cout<<1<<" ";
            }
            if(y==0) cout<<'\n';
            for(int i=1;i<=y;i++){
                cout<<-1<<((i==y)?'\n':' ');
            }
        }
    }
}