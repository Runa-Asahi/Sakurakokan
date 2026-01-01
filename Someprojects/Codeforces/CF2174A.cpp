#include <bits/stdc++.h>
using namespace std;
string s,t,irr;
unordered_map<char,int> mp;
int main(){
    int T; cin >> T;//number of test cases
    while(T--){
        cin >> s >> t;
        mp.clear();
        for(int i=0;i<s.size();i++) mp[s[i]]++;
        for(int i=0;i<t.size();i++){
            if(mp[t[i]]!=0){
                mp[t[i]]--;
            }else{
                irr+=t[i];
            }
        }
        if(irr.size()==0){
            cout << s << "\n";
            continue;
        }
        sort(irr.begin(),irr.end());
        for(int i=0;i<s.size();i++){
            int left = 0, right = irr.size()-1;
            while(left+1<right){
                int mid = left+(right-left)/2;
                if(irr[mid]>=s[i]){
                    right = mid;
                }
                else{
                    left = mid;
                }
            }
            if(irr[left]<s[i] && irr[right]<s[i]){
                irr.insert(irr.begin()+right,s[i]);
                continue;
            }else if(irr[left]<s[i] && irr[right]>=s[i]){
                irr.insert(irr.begin()+left,s[i]);
                continue;
            }else if(irr[left]>=s[i]){
                irr.insert(irr.begin(),s[i]);
                continue;
            }
        }
        cout<<irr<<'\n';
        irr.clear();
    }
}