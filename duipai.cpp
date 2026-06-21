#include <bits/stdc++.h>
using namespace std;
int main(){
    int L,R,D,U;cin>>L>>R>>D>>U;
    int cnt=0;
    for(int i=L;i<=R;i++){
        for(int j=D;j<=U;j++){
            int x = max(abs(i),abs(j));
            if(x%2==0) cnt++;
        }
    }
    cout<<cnt<<'\n';
}