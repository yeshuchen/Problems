#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int size[N];
int n, tot, ans, maxn;
int f[N], dep[N], ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
int dfs1(int x, int fa)
{
    dep[x] = dep[fa] + 1;
    size[x] = 1;
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(y == fa) continue;
        dfs1(y, x);
        size[x] += size[y];
    }
}
void dfs(int x, int fa)
{
    f[x] = f[fa] + n - 2 * size[x];
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(y == fa) continue;
        dfs(y, x);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs1(1, 0);
    int maxn = -n;
    for(int i = 1; i <= n; i++) maxn += dep[i];
    f[1] = maxn;
    for(int i = head[1]; i; i = nxt[i])
    {
        int y = ver[i];
        dfs(y, 1);
    }
    maxn = INT_MAX;
    int pos = 1;
    for(int i = 1; i <= n; i++)
        if(maxn > f[i])
            pos = i, maxn = f[i];
    cout << pos << ' ' << maxn << '\n';
    return 0;
}