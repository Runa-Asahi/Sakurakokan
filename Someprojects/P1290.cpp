#include <bits/stdc++.h>
using namespace std;
void solve(int M,int N,string per,string anoper){
    if(M<N){
        int tmp = M;
        M = N;
        N = tmp;
    }
    if(M/N>=2 && M%N!=0){
        cout<<per<<" wins"<<'\n';
    }
    else if(M%N==0) cout<<per<<" wins"<<'\n';
    else if(M/N==1 && M%N!=0){
        M = M-N;
        solve(M,N,anoper,per);
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int C;cin>>C;
    for(int i=1;i<=C;i++){
        int M,N;
        cin>>M>>N;
        solve(M,N,"Stan","Ollie");
    }
}
