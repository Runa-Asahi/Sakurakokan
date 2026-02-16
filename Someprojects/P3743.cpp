#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
struct node{
    double a,b;
};
vector<node> D;//0-based
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    double n,p;
    double asum=0;
    cin>>n>>p;
    for(int i=1;i<=n;i++){
        double a,b;
        cin>>a>>b;
        D.push_back({a,b});
            asum+=a;
    }
    if(asum<=p){
        cout<<-1<<endl;
        return 0;
    }
    double left=0,right=1e10;
    for(int i=0; i<100; i++){
        double mid=(left+right)/2;//mid is time 
        //mid up -> sum up -> left up
        double sum=0;
        for(int i=0;i<n;i++){
            if(D[i].b-D[i].a*mid>=0) continue;
            else sum+=D[i].a*mid-D[i].b;
        }
        if(sum>p*mid) right=mid;
        else left=mid;
    }
    cout<<fixed<<setprecision(10)<<left<<endl;
}