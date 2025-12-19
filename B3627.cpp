#include <bits/stdc++.h>
using namespace std;
using ull =  unsigned long long;
const ull N = 1e5+10;
int main(){
    ull num;cin>>num;
    ull l = 0,r = 2e6;
    while(l+1<r){
        __int128 mid = l+(r-l)/2;
        if(mid*mid*mid<=(__int128)num) l = mid;
        else r = mid;
    }
    cout<<l<<endl;
}