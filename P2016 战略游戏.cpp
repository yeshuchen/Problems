#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, tot;
int f[N][2];
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
void dfs(int x, int fa)
{
    f[x][1] = 1;
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(y == fa) continue;
        dfs(y, x);
        f[x][0] += f[y][1];
        f[x][1] += min(f[y][1], f[y][0]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x, y, cnt;
        cin >> x >> cnt;
        x++;
        while(cnt--)
        {
            cin >> y;
            y++;
            add(x, y);
            add(y, x);
        }
    }
    dfs(1, 0);
    cout << min(f[1][0], f[1][1]);
    return 0;
}
/*
f[x][0]表示当前节点不放置士兵的最小数目
f[x][1]表示当前节点放置士兵的最小数目
*/