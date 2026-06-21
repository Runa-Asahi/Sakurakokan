#include <bits/stdc++.h>
using namespace std;
const int N = 50;
int v[N],f[N];
int V,n;
int main(){
    cin>>V;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
   f[n+1]=0;
    for(int i=n;i>=1;i--){
        int tmp = f[i+1];
        int atmp = f[i+1]+v[i];
        if(tmp>V) tmp=0;
        else if(atmp>V) atmp=0;
        f[i]=max(tmp,atmp);
    }
    cout<<V-f[1]<<'\n';
}