#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> t;

int main(){
    int N;cin>>N;
    for(int i=1;i<=N;i++){
        int x;
        while(cin>>x&&x!=0){
            t[i].push_back(x);
        }
    }
    
}