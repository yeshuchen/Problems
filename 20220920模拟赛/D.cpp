#include<bits/stdc++.h>
#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
const int N = 2e6 + 5, n = 4e5 + 5;
int nm, m;
int T[N], total[N];
int t[N], x[N], temp[N];
string op[N];
vector<int> g[N];
inline void change(int p, int l, int r, int d, int k)
{
    if(l == r)
    {
        T[p] += temp[d] * k;
        total[p] += k;
        return;
    }
    int mid = l + r >> 1;
    if(d <= mid) change(ls, l, mid, d, k);
    else change(rs, mid + 1, r, d, k);
    T[p] = T[ls] + T[rs];
    total[p] = total[ls] + total[rs];
}
inline int ask(int p, int l, int r, int fw)
{
    if(l == r) return T[p];
    int mid = l + r >> 1, val = 0;
    if(fw > total[ls]) val += ask(rs, mid + 1, r, fw - total[ls]) + T[ls]; 
    else val += ask(ls, l, mid, fw);
    return val;
}
signed main()
{
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> nm >> m;
    for(int i = 1; i <= m; i++)
        cin >> op[i] >> t[i] >> x[i], temp[i] = x[i];
    sort(temp + 1, temp + m + 1);
    int tot = unique(temp + 1, temp + m + 1) - temp - 1;
    for(int i = 1; i <= m; i++)
        x[i] = lower_bound(temp + 1, temp + tot + 1, x[i]) - temp;
    for(int i = 1; i <= m; i++)
    {
        if(op[i] == "BORROW")
        {
            int pos = lower_bound(g[t[i]].begin(), g[t[i]].end(), x[i]) - g[t[i]].begin();
            if(g[t[i]].empty()) g[t[i]].push_back(x[i]), change(1, 1, n, x[i], 1);
            else if(g[t[i]].size() < t[i]) g[t[i]].insert(lower_bound(g[t[i]].begin(), g[t[i]].end(), x[i]), x[i]), change(1, 1, n, x[i], 1);
            else
            {
                if(pos > g[t[i]].size() - t[i]) change(1, 1, n, g[t[i]][g[t[i]].size() - t[i]], -1), change(1, 1, n, x[i], 1);
                g[t[i]].insert(lower_bound(g[t[i]].begin(), g[t[i]].end(), x[i]), x[i]);
            }
        }
        else
        {
            int pos = lower_bound(g[t[i]].begin(), g[t[i]].end(), x[i]) - g[t[i]].begin();
            if(g[t[i]].size() <= t[i]) change(1, 1, n, x[i], -1), g[t[i]].erase(lower_bound(g[t[i]].begin(), g[t[i]].end(), x[i]));
            else
            {
                if(pos >= g[t[i]].size() - t[i]) change(1, 1, n, x[i], -1), change(1, 1, n, g[t[i]][g[t[i]].size() - t[i] - 1], 1);
                g[t[i]].erase(lower_bound(g[t[i]].begin(), g[t[i]].end(), x[i]));
            }
        }
        cout << ask(1, 1, n, nm) << '\n';
    }
    return 0;
}