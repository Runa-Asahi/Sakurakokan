#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,x,y,z;cin>>n>>x>>y>>z;
        int t1 = (n+x+y-1)/(x+y);
        if(t1<=z){
            cout<<t1<<'\n';
            continue;
        }
        int t2 = (n-x*z+x+y*10-1)/(x+y*10)+z;
        cout<<min(t1,t2)<<'\n';
    }
}