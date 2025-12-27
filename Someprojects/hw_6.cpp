#include <bits/stdc++.h>
using namespace std;

int res=0;
 
int ismax(vector <int> arr,int index,int n){
    if(res<arr[index]) res = arr[index];
    if(index>=n-1) return res;
    else return ismax(arr,index+1,n);
}

int main(){
    int n;
    scanf("%d",&n);
    vector<int> arr(n);
    for(int i=0;i<n;i++){  
        scanf("%d",&arr[i]);
    }
    printf("%d",ismax(arr,0,n));
    return 0;
}