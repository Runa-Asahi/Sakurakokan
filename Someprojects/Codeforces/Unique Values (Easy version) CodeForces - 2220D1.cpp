#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int left=1,right=2*n+1;
        while(left+1<right){
            int mid = left+(right-left)/2;
            cout<<"? ";
            for(int i=left;i<=mid;i++){
                cout<<i<<(i==mid)?"\n":" ";
            }
            fflush(stdout);
            int ans1=0,ans2=0;
            cin>>ans1;
            cout<<"?";
            for(int i=mid+1;i<=right;i++){
                cout<<i<<(i==right)?"\n":" ";
            }
            fflush(stdout);
            cin>>ans2;
            if(ans1>ans2){
                right = mid;
            }else{
                left = mid+1;
            }
            if(left==right){
                
            }
        }
    }
}
