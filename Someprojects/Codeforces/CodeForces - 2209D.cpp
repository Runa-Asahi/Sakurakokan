#include <bits/stdc++.h>
using namespace std;
string ans;
string cr="RGB";
map<int,int> dic;
map<int,int> otherdic;
int main(){
    int t;cin>>t;
    while(t--){
        int r,g,b;cin>>r>>g>>b;
        char maxcr,firstcr,secondcr;
        dic[1]=r;dic[2]=g;dic[3]=b;
        int maxn = 1,maxcr = 'R';
        if(g>=r && g>=b) maxn = 2,maxcr = 'G';
        if(b>=r && b>=g) maxn = 3,maxcr = 'B';
        int sumn=0;
        int cnt=0;
        bool flag = true;
        for(int i=1;i<=3;i++){
            if(i==maxn)  continue;
            if(flag) firstcr = cr[i],flag = false;
            else secondcr = cr[i]; 
            otherdic[cnt++]=dic[i];
            sumn+=dic[i];
        }
        if(sumn<=maxn-2){
            for(int i=1;i<=sumn*2+1;i++){
                if(i%2!=0) ans+=maxcr;
                else if(otherdic[1]) ans+=firstcr;
                else ans+=secondcr;
            }
        }
        else if(sumn>=maxn-1 && )
    }
}