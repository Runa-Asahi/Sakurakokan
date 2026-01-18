#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
ull gcd(ull a, ull b){
    for( ull i=1;i<=a;i++){
        ull c = a%b;
        if(c==0) return b;
        a = b;
        b = c;
    }
    return 1;
}
int main(){
    cout<<gcd(8,12)<<"\n";
    cout<<gcd(100,75)<<"\n";
    cout<<gcd(17,13)<<"\n";
}