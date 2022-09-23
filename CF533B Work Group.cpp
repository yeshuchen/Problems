#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, tot;
int f[N][2], p[N];
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
void dfs(int x, int fa)
{
    f[x][1] = -114514;
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(y == fa) continue;
        dfs(y, x);
        int u = f[x][0], v = f[x][1];
        f[x][0] = max(f[y][0] + u, f[y][1] + v);
        f[x][1] = max(f[y][0] + v, f[y][1] + u);
    }
    f[x][1] = max(f[x][1], f[x][0] + p[x]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x >> p[i];
        if(x < 0) continue;
        add(x, i);
        add(i, x);
    }
    dfs(1, 0);
    cout << f[1][1];
    return 0;
}