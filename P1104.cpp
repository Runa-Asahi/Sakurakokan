#include <bits/stdc++.h>
using namespace std;
typedef struct Student{
    string name;
    int year,month,day;
    int id;
}Student;
Student stu[105];
bool cmp(Student a,Student b)
{
    if(a.year!=b.year) return a.year<b.year;
    else{
        if(a.month!=b.month){
            return a.month<b.month;
        }else{
            if(a.day!=b.day){
                return a.day<b.day;
            }
        }
    }
    return a.id>b.id;
}
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin>>stu[i].name>>stu[i].year>>stu[i].month>>stu[i].day;
        stu[i].id = i;
    }
    sort(stu,stu+n,cmp);
    for(int i=0;i<n;i++){
        cout<<stu[i].name<<'\n';
    }
}