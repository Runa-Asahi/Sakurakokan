#include <bits/stdc++.h>
using namespace std;
vector<int> A,B;
int main(){
    int N,K;cin>>N>>K;
    int ptr=0;
    for(int i=1;i<=N;i++){
        int x;cin>>x;
        A.push_back(x%K);
        B.push_back(x%K+K);
    }
    sort(B.begin(),B.end(),greater<int> ());
    for(int i=N-1;i>=0;i--){
        ptr = max(ptr,B[i]);
        B[i] = ptr;
    }
    sort(A.begin(),A.end(),greater<int> ());
    int ans=A[0]-A[N-1];
    for(int i=0;i<N-1;i++){
        ans = min(ans,B[i+1]-A[i]);
    }
    cout<<ans<<'\n';
}