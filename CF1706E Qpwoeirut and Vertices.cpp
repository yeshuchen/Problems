#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int T, n, m, q, res;
struct node{
    int x, y, z;
}a[N];
int dep[N], fath[N][19];
int f[N], d[N], ls[N], rs[N], ans[N][19];
inline int find(int k){return f[k] == k ? k : f[k] = find(f[k]);}
void dfs(int x, int fa)
{
    dep[x] = dep[fa] + 1;
    fath[x][0] = fa;
    for(int i = 1; i <= 18; i++)
        fath[x][i] = fath[fath[x][i - 1]][i - 1];
    if(x <= n) return;
    dfs(ls[x], x);
    dfs(rs[x], x);
}
inline int lca(int x, int y)
{
    if(dep[x] < dep[y]) swap(x, y);
    int tmp = dep[x] - dep[y];
    for(int i = 18; i >= 0; i--)
        if(tmp & (1 << i))
            x = fath[x][i];
    if(x == y) return d[x];
    for(int i = 18; i >= 0; i--)
        if(fath[x][i] != fath[y][i])
            x = fath[x][i], y = fath[y][i];
    return d[fath[x][0]];
}
inline int query(int l, int r)
{
    if(l == r) return ans[l][0];
    int k = log2(r - l + 1);
    return max(ans[l][k], ans[r - (1 << k) + 1][k]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> q;
        int cnt = n;
        res = 0;
        for(int i = 1; i <= n; i++)
            f[i] = i;
        for(int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            a[i].x = x, a[i].y = y, a[i].z = i;
        }
        for(int i = 1; i <= m; i++)
        {
            int fx = find(a[i].x), fy = find(a[i].y);
            if(fx == fy) continue;
            cnt++;
            ls[cnt] = fx, rs[cnt] = fy;
            f[fx] = f[fy] = f[cnt] = cnt;
            d[cnt] = a[i].z;
        }
        dfs(cnt, 0);
        for(int i = 1; i < n; i++)
            ans[i][0] = lca(i, i + 1);
        for(int j = 1; j <= 18; j++)
            for(int i = 1; i <= n; i++)
                ans[i][j] = max(ans[i][j - 1], ans[i + (1 << j - 1)][j - 1]);
        while(q--)
        {
            int x, y;
            cin >> x >> y;
            if(x == y)
            {
                cout << 0 << ' ';
                continue;
            }
            cout << query(x, y - 1) << ' ';
        }
        cout << '\n';
    }
    return 0;
}