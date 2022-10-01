#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, tot;
int f[N][20];
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
inline void dfs(int x, int fa)
{
    for(int i = 1; i <= 15; i++) f[x][i] = i;
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(y == fa) continue;
        dfs(y, x);
        for(int j = 1; j <= 15; j++)
        {
            int minn = INT_MAX;
            for(int k = 1; k <= 15; k++)
                if(j != k)
                    minn = min(minn, f[y][k]);
            f[x][j] += minn;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs(1, 0);
    int ans = INT_MAX;
    for(int i = 1; i <= 15; i++)
        ans = min(ans, f[1][i]);
    cout << ans;
    return 0;
}