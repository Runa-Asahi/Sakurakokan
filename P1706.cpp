#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
void dfs(int index,int n){
    if(index==n+1){
        for(size_t i=0;i<arr.size();i++){
            cout<<"    "<<arr[i];
        }
        return;
    }
    for(int i=1;i<=n;i++){
        bool flag=true;
        arr.push_back(i);
        for(size_t j=0;j<arr.size();j++){
            if(arr[j]==i){
                flag=false;
                break;
            }
        }
        if(!flag){
            arr.pop_back();
            continue;
        }
        dfs(index+1,n);
        arr.pop_back();
    }
}

int main(){
    int n;cin>>n;
    dfs(1,n);
}