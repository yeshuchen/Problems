#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int n, m, tot, res;
int size[N], dfn[N], low[N], ans[N];
int ver[N], nxt[N], head[N], vis[N];
inline void add(int x, int y)
{
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
void dfs(int x, int fa)
{
    size[x] = 1;
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(y == fa || size[y]) continue;
        dfs(y, x);
        size[x] += size[y];
    }
}
inline void tarjan(int x, int fa, int isroot)
{
    int son = 0, sum = 0;
    dfn[x] = low[x] = ++res;
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(!dfn[y])
        {
            son++;
            tarjan(y, x, 0);
            low[x] = min(low[x], low[y]);
            if(dfn[x] <= low[y])
            {
                ans[x] += size[y] * (n - size[y]);
                sum += size[y];
                vis[x] = 1;
            }
        }
        else if(y != fa) low[x] = min(low[x], dfn[y]);
    }
    if(isroot && son > 1 || vis[x]) ans[x] += (n - sum - 1) * (sum + 1) + (n - 1);
    else ans[x] = 2 * (n - 1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs(1, 0);
    tarjan(1, 0, 1);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
    return 0;
}