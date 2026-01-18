#include <bits/stdc++.h>
using namespace std;
int main(){
    int L,N;
    cin>>L>>N;
    int maxres=0,minres=0;
    for(int i=0;i<N;i++){
        int tmp=0;
        cin>>tmp;
        maxres=max(maxres,max(tmp,L-tmp+1));
        minres=max(minres,min(tmp,L-tmp+1));
    }
    cout<<minres<<" "<<maxres<<endl;
}