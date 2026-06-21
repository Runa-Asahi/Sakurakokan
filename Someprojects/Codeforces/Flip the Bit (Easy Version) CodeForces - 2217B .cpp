#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+9;
int a[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--){
        memset(a,-1,sizeof(a));
        int p=0;
        int n,k;cin>>n>>k;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        cin>>p;
        int fin = a[p];
        int cnt=0;
        if(p==1){
            for(int j=p+1;j<=n;j++){
                if(a[j]!=fin){
                    for(int k=j+1;k<=n;k++){
                        if(a[k]==a[j]){
                            j=k;
                        }else break;
                    }
                    cnt+=2;
                }
            }
            cout<<cnt<<'\n';
            continue;
        }
       
        if(p==n){
           for(int j=n;j>=1;j--){
                if(a[j]!=fin){
                    for(int k=j-1;k>=1;k--){
                        if(a[k]==a[j]){
                            j=k;
                        }else break;
                    }
                    cnt+=2;
                }
            } 
            cout<<cnt<<'\n';
            continue;
        }
        int i=p+1;
        int j=p-1;
        while(true){
            bool flagi=false,flagj=false;
            for(;i<=n;i++){
                if(a[i]!=fin){
                    for(int k=i+1;k<=n;k++){
                        if(a[k]==a[i]){
                            i=k;
                        }else break;
                    }
                    flagi = true;
                    i++;
                    break;
                }
            }
            
            for(;j>=1;j--){
                if(a[j]!=fin){
                    for(int k=j-1;k>=0;k--){
                        if(a[k]==a[j]){
                            j=k;
                        }else break;
                    }
                    flagj = true;
                    j--;
                    break;
                }
            }
            
            if(flagi || flagj) cnt+=2;
            else{
                break;
            }
        }
        cout<<cnt<<'\n';
    }
}