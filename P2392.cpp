#include <bits/stdc++.h>
using namespace std;
int s1,s2,s3,s4;int minn;
int A[25],B[25],C[25],D[25];
int lt,rt;
void dfs(int ch,int id){
    if(id == 1){
        if(ch>s1){
            minn = min(minn,max(lt,rt));
            return;
        }
        lt+=A[ch];
        dfs(ch+1,id);
        lt-=A[ch];
        rt+=A[ch];
        dfs(ch+1,id);
        rt-=A[ch];
    }
    else if(id == 2){
        if(ch>s2){
            minn = min(minn,max(lt,rt));
            return;
        }
        lt+=B[ch];
        dfs(ch+1,id);
        lt-=B[ch];
        rt+=B[ch];
        dfs(ch+1,id);
        rt-=B[ch];
    }
    else if(id == 3){
        if(ch>s3){
            minn = min(minn,max(lt,rt));
            return;
        }
        lt+=C[ch];
        dfs(ch+1,id);
        lt-=C[ch];
        rt+=C[ch];
        dfs(ch+1,id);
        rt-=C[ch];
    }
    else if(id == 4){
        if(ch>s4){
            minn = min(minn,max(lt,rt));
            return;
        }
        lt+=D[ch];
        dfs(ch+1,id);
        lt-=D[ch];
        rt+=D[ch];
        dfs(ch+1,id);
        rt-=D[ch];
    }
}
int main(){
    cin>>s1>>s2>>s3>>s4;
    for(int i=1;i<=s1;i++){
        cin>>A[i];
    }
    for(int i=1;i<=s2;i++){
        cin>>B[i];
    }
    for(int i=1;i<=s3;i++){
        cin>>C[i];
    }
    for(int i=1;i<=s4;i++){
        cin>>D[i];
    }
    int res = 0;
    minn = INT_MAX;
    dfs(1,1);
    res += minn;
    minn = INT_MAX;
    dfs(1,2);
    res += minn;
    minn = INT_MAX;
    dfs(1,3);
    res += minn;
    minn = INT_MAX;
    dfs(1,4);
    res += minn;
    cout<<res<<'\n';
}

