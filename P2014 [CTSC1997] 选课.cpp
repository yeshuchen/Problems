#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, tot;
int a[N], f[305][305];
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
void dfs(int x, int fa)
{
    f[x][1] = a[x];
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(y == fa) continue;
        dfs(y, x);
        for(int j = m; j >= 1; j--)
            for(int k = 1; k + j <= m; k++)
                f[x][j + k] = max(f[x][j + k], f[x][j] + f[y][k]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    m++;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x >> a[i];
        add(x, i);
        add(i, x);
    }
    dfs(0, 0);
    cout << f[0][m];
    return 0;
}