#include <bits/stdc++.h>
using namespace std;
int a[105];
int dict[105];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            if(i%2==0) dict[a[i]] = 1;
            else dict[a[i]] = 0;
        }
        sort(a,a+n);
        int st = dict[a[0]];
        for(int i=1;i<n;i++){
            if(i%2!=0 && dict[a[i]]==st){
                cout<<"NO\n";
                goto end;
            }
            else if(i%2==0 && dict[a[i]]!=st){
                cout<<"NO\n";
                goto end;
            }
        }
        cout<<"YES\n";
        end:;
        memset(dict,0,sizeof(dict));
        memset(a,0,sizeof(a));
    }
}