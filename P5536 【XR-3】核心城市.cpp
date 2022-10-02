#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int n, k, tot, res, maxn;
int f[N], dep[N], temp[N], maxdep[N];
int ver[N], nxt[N], head[N], ans[N];
inline void add(int x, int y)
{
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
inline void dfs(int x, int fa)
{
    maxdep[x] = dep[fa] + 1;
    f[x] = fa; dep[x] = dep[fa] + 1;
    if(dep[x] > dep[maxn]) maxn = x;
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(y == fa) continue;
        dfs(y, x);
        maxdep[x] = max(maxdep[x], maxdep[y]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs(1, 0); 
    int r = maxn; maxn = 0;
    dfs(r, 0);
    r = maxn;
    while(r)
    {
        temp[++res] = r;
        r = f[r];
    }
    r = temp[(res + 1) / 2];
    dfs(r, 0);
    for(int i = 1; i <= n; i++) ans[i] = maxdep[i] - dep[i];
    sort(ans + 1, ans + n + 1);
    cout << ans[n - k] + 1;
    return 0;
}