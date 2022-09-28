#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int n, m, q, tot;
int ans[N][N];
int vis[N];
int ver[N * N], nxt[N * N], head[N * N];
inline void add(int x, int y)
{
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
inline void bfs(int zd)
{
    queue<int> q;
    q.push(zd);
    while(!q.empty())
    {
        int x = q.front(); q.pop();
        vis[x] = 1;
        for(int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i];
            ans[zd][y] = 1;
            if(vis[y]) continue;
            q.push(y);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        {
            int p;
            cin >> p;
            add(j, p);
        }
    for(int i = 1; i <= n; i++)
    {
        memset(vis, 0, sizeof(vis));
        bfs(i);
    }
    for(int i = 1; i <= q; i++)
    {
        int a, b;
        cin >> a >> b;
        if(ans[a][b]) cout << "DA\n";
        else cout << "NE\n";
    }
    return 0;
}