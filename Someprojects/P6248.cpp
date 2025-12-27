#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int n,m;int res=0;
typedef struct hero{
    string name;
    ull v;
}hero;
typedef struct pari{
    hero hero1;
    hero hero2;
    int addnum;
}pari;
hero arr[35];
pari parr[35];
void dfs(int index,int start);
vector<int> judge;    

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i].name>>arr[i].v;
    }
    for(int i=1;i<=m;i++){
        cin>>parr[i].hero1.name>>parr[i].hero2.name>>parr[i].addnum;
    }
    dfs(1,1);
    cout<<res<<endl;
}
void dfs(int index,int start){
    int ans=0;
    if(index==7){//选好6个英雄
        for(int i=0;i<6;i++){
            ans+=arr[judge[i]].v;
        }
        for(int i=1;i<=m;i++){
            for(int j=0;j<6;j++){
                for(int k=0;k<6;k++){
                    if(j==k)continue;
                    if(arr[judge[j]].name==parr[i].hero1.name&&arr[judge[k]].name==parr[i].hero2.name){
                        ans+=parr[i].addnum;
                    }
                }
            }
        }
        if(ans>res)res=ans;
        return;
    }
    for(int i=start;i<=n;i++){//摆好n个英雄
        judge.push_back(i);
        dfs(index+1,i+1);        
        judge.pop_back();
    }
}