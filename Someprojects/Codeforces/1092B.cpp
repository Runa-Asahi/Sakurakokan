#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll num;ll numm;
int main(){
    int t;cin>>t;
    while(t--){
        ll cnt=0;
        ll ct,ch,cu;cin>>ct>>ch>>cu;
        ll yct=ct;ll rnum=0;
        ct -= cu;
        if(ct<=0){
            cnt+=(ct+cu)*4;
            cu-=yct;
            ct=0;
            goto end;
        }else{
            cnt+=cu*4;
            cu=0;
        }


        num = ct/2;
        rnum = num;
        num -= ch;
        if(num<=0){
            cnt+=(num+ch)*7;
            ch-=rnum;
            ct = ct%2;
            goto label;
        }else{
            cnt+=ch*7;
            ch=0;
        }
        ct = ct%2+num*2;
        label:;
        if(ct>=2){
            cnt+=ct*2+1;
            ct=0;
        }
        if(ct==1 && ch>=1){
            cnt+=5;
            ch-=1;
            ct=0;
        }
end:;
        cnt+=ct*3;
        cnt+=ch*3;
        cnt+=cu*3;
        cout<<cnt<<'\n';
    }
}