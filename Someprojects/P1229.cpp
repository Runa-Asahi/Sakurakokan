#include <bits/stdc++.h>
using namespace std;
int cnt=1;
int main(){
    string pre,last;
    cin>>pre>>last;
    for(int i=0;i<pre.length()-1;i++){
        for(int j=1;j<last.length();j++){
            if(pre[i]==last[j] && pre[i+1]==last[j-1]) cnt*=2;
        }
    }
    cout<<cnt<<'\n';
}