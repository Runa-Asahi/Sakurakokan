#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int rest=INT_MAX;
        int n,k;cin>>n>>k;
        string s;cin>>s;
        int cntl=0,cntr=0;
        for(auto c:s){
            if(c=='(') cntl++;
            else cntr++;
        }
        vector<int> ans;
        for(int i=0;i<=k;i++){
            vector<int> res(s.size(),0);
            int left = i;
            int right = k-i;
            for(int j=0;j<s.size();j++){
                if(left==0) break;
                if(s[j]=='('){
                    left--;
                    res[j]=1;
                }
            }
            for(int j=s.size()-1;j>=0;j--){
                if(right==0) break;
                if(s[j]==')'){
                    right--;
                    res[j]=1;
                }
            }
            stack<int> stk; 
            int cnt=0;
            for(int j=0;j<s.size();j++){
                if(res[j]) continue;
                if(s[j]=='('){
                    stk.push(j);
                }
                else if(s[j]==')'&&!stk.empty()){
                    stk.pop();
                    cnt++;
                }
            }
            if(cnt<rest){
                rest = cnt;
                ans=move(res);
            }
        }
        for(auto c:ans) cout<<c;
        cout<<'\n';
    }
}