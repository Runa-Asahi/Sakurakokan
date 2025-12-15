#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,k;int res=0;
    cin>>a>>b>>k;
    res = a&b;
    cout<<res<<endl;
    res = a|b;
    cout<<res<<endl;
    res = a^b;
    cout<<res<<endl;
    res = ~a;
    cout<<res<<endl;
    res = a<<k;
    cout<<res<<endl;
    res = a>>k;
    cout<<res<<endl;
    return 0;
}