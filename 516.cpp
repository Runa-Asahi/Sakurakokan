#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll L,R,D,U;cin>>L>>R>>D>>U;
    ll cnt=0;
    for(int i=L;i<=R;i++){
        //every line
        if(U<=abs(i) && D>=(-1)*abs(i)){
            if(i%2!=0) continue;
            cnt+=U-D+1;
            continue;
        }
        if(U<=abs(i) && D<(-1)*abs(i)){
            ll all = U-D+1;
            
            ll left = abs(D)-abs(i);ll right = all-left+1;
            if(i%2==0){
                cnt+=right;
            }
            ll firstlf = abs(i)-1;
            ll lastlf = D;
            ll delta = left;
            cnt+=delta/2;
            if(firstlf%2==0 && delta%2!=0){
                cnt+=1;
            }
            continue;
        }
        if(U>abs(i) && D<=abs(i)){
            ll all = U-D;
            ll right = abs(U)-abs(i);
            ll left = all-right;
            if(i%2==0){
                cnt+=left;
            }
            ll firstrt = abs(i);
            ll lastrt = U;
            ll delta = right;
            cnt+=delta/2;
            if(firstrt%2==0 && delta%2!=0){
                cnt+=1;
            }
            continue;
        }
        if(U>abs(i) && D<(-1)*abs(i)){
            ll delta = U-D+1;
            delta-=(2*abs(i)+1);
            cnt+=delta;
            ll lf = (-1)*abs(i)-D;
            ll rt = U-abs(i);
            if(((-1)*abs(i)-1)%2==0 && lf%2!=0){
                cnt+=1;
            }
            if((abs(i)+1)%2==0 && rt%2!=0){
                cnt+=1;
            }
            continue;
        }
        if(D>abs(i)){
            ll delta = U-D+1;
            cnt+=delta/2;
            if(D%2==0 && delta%2!=0) cnt+=1;
            continue;
        }
        if(U<=(-1)*abs(i)){
            ll delta = U-D+1;
            cnt+=delta;
            continue;
        }
    }
    cout<<cnt<<'\n';
}