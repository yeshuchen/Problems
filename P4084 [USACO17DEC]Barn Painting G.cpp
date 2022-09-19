#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;
int n, k;
int tot, f[N][4], vis[N];
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
void dfs(int x, int fa)
{
    if(vis[x]) f[x][vis[x]] = 1;
    else f[x][1] = f[x][2] = f[x][3] = 1; 
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(y == fa) continue;
        dfs(y, x);
        f[x][1] *= (f[y][2] + f[y][3]);
        f[x][2] *= (f[y][1] + f[y][3]);
        f[x][3] *= (f[y][1] + f[y][2]);
        f[x][1] %= mod; f[x][2] %= mod; f[x][3] %= mod;
    }
}
signed main()
{
    cin >> n >> k;
    for(int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    for(int i = 1; i <= k; i++)
    {
        int x, y;
        cin >> x >> y;
        vis[x] = y;
    }
    dfs(1, 0);
    cout << (f[1][1] + f[1][2] + f[1][3]) % mod;
    return 0;
}
//f[i][1/2/3]表示当前节点染第1/2/3种颜色的方案数