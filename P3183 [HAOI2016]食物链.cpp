#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, tot, ans;
int d[N], f[N], vis[N];
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) vis[i] = 1;
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        d[y]++;
    }
    queue<int>q;
    for(int i = 1; i <= n; i++)
        if(!d[i])
        {
            f[i] = 1, vis[i] = 0;
            q.push(i);
        }
    while(!q.empty())
    {
        int x = q.front(); q.pop();
        bool flag = 1;
        for(int i = head[x]; i; i = nxt[i])
        {
            flag = 0;
            int y = ver[i];
            d[y]--; f[y] += f[x];
            if(!d[y]) q.push(y);
        }
        ans += flag * vis[x] * f[x];
    }
    cout << ans;
    return 0;
}