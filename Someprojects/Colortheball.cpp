#include <bits/stdc++.h>
using namespace std;
struct Interval {
    int l, r;
    char c;
    bool operator<(const Interval& other) const {
        return l < other.l;
    }
};

auto split(int pos, set<Interval> &s) {
    auto it = s.lower_bound({pos,0,0});
    if(it!=s.end() && it->l==pos) return it;
    --it;
    int l = it->l,r = it->r;
    char c = it->c;
    s.erase(it);
    s.insert({l,pos-1,c});
    return s.insert({pos,r,c}).first;
}

void assign(int l,int r,char c,set<Interval> &s){
    auto itr = split(r+1,s);
    auto itl = split(l,s);
    s.erase(itl,itr);
    s.insert({l,r,c});
}
int main() {
    int N;
    while (cin >> N) {
        set<Interval> s;
        s.insert({1, INT_MAX, 'b'});
        for (int i = 0; i < N; i++) {
            int a, b;
            char c;
            cin >> a >> b >> c;
            assign(a, b, c, s);
        }
        pair<int,int> cnt={0,0};
        pair<int,int> ans={-1,-1};
        for (auto &interval : s) {
            char color = interval.c;
            if(color=='w') {
                if(cnt.first==0){
                    cnt.first = interval.l;
                    cnt.second = interval.r;
                }else{
                    cnt.second = interval.r;
                }
                int c = cnt.second - cnt.first + 1;
                int a = ans.second - ans.first + 1;
                if(c>a){
                    ans.first = cnt.first;
                    ans.second = cnt.second;
                }
            }
            else {
                cnt={0,0};
            }
        }
        cout << ans.first << " " << ans.second << "\n";
    }
}