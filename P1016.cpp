#include <bits/stdc++.h>
using namespace std;
stack<int> firstElement;
bool isFinal(const vector<int> &seq){
    int principle = seq[1];
    for(int i=1;i<seq.size();i++){
        if(seq[i]!=principle) return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--){
        vector<int> sequence;
        sequence.push_back(0);
        int S,C;cin>>S>>C;
        int len = S+C;
        for(int i=0;i<S;i++){
            int x;cin>>x;
            sequence.push_back(x);
        }
        while(!isFinal(sequence)){
            firstElement.push(sequence[1]);
            for(int i=2;i<sequence.size();i++){
                sequence[i-1] = sequence[i]-sequence[i-1];
            }
            if(!sequence.empty()) sequence.pop_back();
        }
        for(int i=1;i<=C;i++){
            sequence.push_back(sequence[1]);
        }
        while(!firstElement.empty()){
            sequence[0] = firstElement.top();
            firstElement.pop();
            int i=1;
            int tmp;
            for(;i<=sequence.size()-1;i++){
                tmp = sequence[i];
                sequence[i] = sequence[i-1] + sequence[i];
            }
            i--;
            if(firstElement.empty()){
                sequence.push_back(tmp+sequence[i]);
                break;
            }
            sequence.push_back(0);
            sequence.push_back(tmp+sequence[i]);
            for(int j=i+1;j>=1;j--){
                sequence[j] = sequence[j-1];
            }
            sequence[0]=0;
        }
        for(int i=S;i<len;i++){
            cout<<sequence[i];
            if(i!=len-1) cout<<" ";
        }
        cout<<"\n";
    }
}