#include <bits/stdc++.h>
using namespace std;
unordered_set <int> st;
vector<int> a;
int main(){
    int t;cin>>t;
    while(t--){
        st.clear();
        a.clear();
        int n;cin>>n;
        bool flag = false;
        for(int i=1;i<=n;i++){
            int x;cin>>x;
            if(flag) continue;
            a.push_back(x);
            if(st.find(x)!=st.end()){
                cout<<-1<<'\n';
                flag = true;
            }
            st.insert(x);
        }
        if(flag) continue;
        sort(a.begin(),a.end(),greater<int>());
        for(int i=0;i<n;i++){
            cout<<a[i]<<' ';
        }
        cout<<'\n';
    }
}