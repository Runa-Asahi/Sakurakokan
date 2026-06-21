#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        vector<int> a,b;
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            int x;cin>>x;
            a.push_back(x);
        }       
        for(int i=1;i<=n;i++){
            int x;cin>>x;
            b.push_back(x);
        }
        b.erase(unique(b.begin(),b.end()),b.end());
        int posj=0;
        for(int i=0;i<b.size();i++){
            int flag = false;
            for(int j=posj;j<a.size();j++){
                if(b[i]==a[j]) {
                    flag =true;
                    posj = j;
                    break;
                }
            }
            if(!flag){
                cout<<"NO"<<'\n';
                goto end;
            } 
        }
        cout<<"YES"<<'\n';
        end:;
    }
}