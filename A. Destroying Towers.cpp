#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            a.push_back(x);
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(a[j]>a[i]) a[j]=a[i];
            }
        }
        int sumn=0;
        for(int i=0;i<n;i++){
            sumn+=a[i];
        }
        cout<<sumn<<'\n';
    }
}