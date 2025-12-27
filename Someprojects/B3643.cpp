#include <bits/stdc++.h>
using namespace std;
int n,m; int arr[30];
void dfs(int depth,int start){
    if(depth>m){
        for(int i=1;i<=m;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=start;i<=n;i++){
        arr[depth]=i;
        dfs(depth+1,i+1);
        arr[depth]=0;
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    dfs(1,1);
    return 0;
}