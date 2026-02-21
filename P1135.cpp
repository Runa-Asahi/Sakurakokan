#include <bits/stdc++.h>
using namespace std;
const int M = 205;
int elevator[M];
int visited[M];
int K[M];
int main(){
    int N,A,B;
    cin >> N >> A >> B;
    if(A==B){
        cout << 0 << endl;
        return 0;
    }
    for(int i=1;i<=N;i++){
        cin>>K[i];
    }
    queue<int> q;
    q.push(A);
    visited[A] = 1;
    while(!q.empty()){
        int pri = q.front();
        q.pop();
        int step = K[pri];
        int up = pri + step;
        int down = pri - step;
        if(up==B || down==B){
            cout << elevator[pri] + 1 << endl;
            return 0;
        }
        if(up<=N && visited[up]==0){
            visited[up] = 1;
            elevator[up] = elevator[pri] + 1;
            q.push(up);
        }
        if(down>=1 && visited[down]==0){
            visited[down] = 1;
            elevator[down] = elevator[pri] + 1;
            q.push(down);
        }
    }
    cout << -1 << endl;
}