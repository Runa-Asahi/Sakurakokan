#include <bits/stdc++.h>
using namespace std;
int sortnum(vector<int> &aa){
    int cnt=0;
    for(int i=0;i<aa.size()-1;i++){
        for(int j=i+1;j<aa.size();j++){
            if(aa[j]<aa[i]) cnt++;
        }
    }
    return cnt;
}
int main(){
    int t;cin>>t;
    while(t--){
        unordered_set<int> vis;
        vector<int> a;
        vector<int> b;
        int n;cin>>n;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            a.push_back(x);
        }
        vector<int> aa = a;
        sort(a.begin(),a.end());
        bool flag = false;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            if(x<a[i]) flag = true;
            b.push_back(x);
        }
        if(flag){
            cout<<-1<<'\n';
        }else{
            for(int i=0;i<n;i++){
                aa[i] = *lower_bound(b.begin(),b.end(),aa[i]);
                while(vis.find(aa[i]) != vis.end()) aa[i]=
                *(lower_bound(b.begin(),b.end(),aa[i])+1);
                vis.insert(aa[i]);
                //b[t];
                //a[t]=b[t];
            }   
            /*for(int i=0;i<n;i++){
                cout<<aa[i]<<" ";
            }*/            
             cout<<sortnum(aa)<<'\n';
        }
    }
}