#include <bits/stdc++.h>
using namespace std;
const int N = 5009;
int a[N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, p, m;
        cin >> n >> k >> p >> m;
        int outtime = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int cost = a[p];
        if(n==k){
            cout<<m/cost<<'\n';
            continue;
        }
        if (p <= k)
        {
            m -= cost;
            if (m < 0)
            {
                cout << outtime << '\n';
                continue;
            }
            outtime++;
            a[p] = 5001;
            sort(a + 1, a + n + 1);
            int othercost = 0;
            for (int i = 1; i <= n-k; i++)
            {
                othercost += a[i];
            }
            while (1)
            {
                m -= othercost;
                if (m < 0)
                    break;
                m -= cost;
                if (m < 0)
                    break;
                outtime++;
            }
            cout << outtime << '\n';
        }
        else
        {
            sort(a + 1, a + p);
            int othercost = 0;
            for (int i = 1; i <= p - k; i++)
            {
                othercost += a[i];
            }
            m -= othercost;
            if (m < 0)
            {
                cout << outtime << '\n';
                continue;
            }
            m -= cost;
            if (m < 0)
            {
                cout << outtime << '\n';
                continue;
            }
            outtime++;
            a[p] = 5001;
            sort(a + 1, a + 1 + n);
            othercost = 0;
            for (int i = 1; i <= n-k; i++)
            {
                othercost += a[i];
            }
            while (1)
            {
                m -= othercost;
                if (m < 0)
                    break;
                m -= cost;
                if (m < 0)
                    break;
                outtime++;
            }
            cout << outtime << '\n';
        }
    }
}