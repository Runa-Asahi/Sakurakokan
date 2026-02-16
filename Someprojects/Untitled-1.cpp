#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+9;
int a[N];
bool vis[N];
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        set<int> st;
        set<int> st1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                for(int j=i;j<=n;j*=2){
                    vis[j] = true;
                    st.insert(j);
                    st1.insert(a[j]);
                }
                for(auto it:st){
                    if(st1.find(it)==st1.end()){
                        cout<<"NO"<<'\n';
                        goto end;
                    }
                }
                st.clear();
                st1.clear();
            }
        }
        cout<<"YES"<<'\n';
        end:
        for(int i=1;i<=n;i++){
            vis[i] = false;
        }
    }
}