#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        string s,t;
        cin >> s >> t;
        int n = s.size();
        int m = t.size();
        int cnts[26] = {0}, cntt[26] = {0};
        for(int i=0;i<n;i++) cnts[s[i]-'a']++;
        for(int i=0;i<m;i++) cntt[t[i]-'a']++;
        bool possible = true;
        for(int i=0;i<26;i++){
            if(cnts[i]>cntt[i]){
                cout<<"Impossible"<<endl;
                possible = false;
                break;
            }
        }
        if(!possible) continue;
        string ans;int p=0;
        for(int step=0;step<m;step++){
            for(int i=0;i<26;i++){
                if(cntt[i]==0) continue;
                cntt[i]--;
                ans.push_back('a'+i);
                if(i+'a'==s[p]){
                    p++;
                    cnts[i]--;
                }
                int pos=0;
                for(int j=0;j<26;j++){
                    if(cnts[j]>cntt[j]){
                        pos=1;
                        break;
                    }
                }
                if(pos) {
                    ans.pop_back();
                    cntt[i]++;
                } else{
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
}