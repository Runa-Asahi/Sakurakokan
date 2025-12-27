#include <bits/stdc++.h>
using namespace std;
typedef struct Student{
    string name;
    int FinalScore,ClassScore,Paper;
    bool Kb,West;
    int TotalMoney;
} Student;
int cmp(Student a,Student b){
    return a.TotalMoney > b.TotalMoney;
}
Student stu[105];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int N;cin>>N;int sumMoney = 0;
    int originalN = N;
    while(N--){
        cin>>stu[originalN - N].name>>stu[originalN - N].FinalScore>>stu[originalN - N].ClassScore;
        char a,b;cin>>a>>b;
        stu[originalN - N].Kb = (a == 'Y');
        stu[originalN - N].West = (b == 'Y');
        cin>>stu[originalN - N].Paper;
    }
    for(int i=1;i<=originalN;i++){
        stu[i].TotalMoney = 0;
        if(stu[i].FinalScore > 80 && stu[i].Paper >= 1) stu[i].TotalMoney += 8000;
        if(stu[i].FinalScore > 85 && stu[i].ClassScore > 80) stu[i].TotalMoney += 4000;
        if(stu[i].FinalScore > 90) stu[i].TotalMoney += 2000;
        if(stu[i].FinalScore > 85 && stu[i].West) stu[i].TotalMoney += 1000;
        if(stu[i].ClassScore > 80 && stu[i].Kb) stu[i].TotalMoney += 850;
        sumMoney += stu[i].TotalMoney;
    }
    stable_sort(stu+1,stu+originalN+1,cmp);
    cout<<stu[1].name<<'\n'<<stu[1].TotalMoney<<'\n';
    cout<<sumMoney<<'\n';
}