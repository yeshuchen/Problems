#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int n, s, tot;
int f[N], dp[N];
int ver[N], val[N], nxt[N], head[N];
inline void add(int x, int y, int z)
{
    ver[++tot] = y;
    val[tot] = z;
    nxt[tot] = head[x];
    head[x] = tot;
}
inline void dfs(int x, int fa)
{
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i], z = val[i];
        if(y == fa) continue;
        dfs(y, x);
        dp[x] = max(dp[y] + z, dp[x]);
        f[x] += f[y];
    }
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i], z = val[i];
        if(y == fa) continue;
        f[x] += dp[x] - (dp[y] + z);
    }
}
signed main()
{
    cin >> n >> s;
    for(int i = 1; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    dfs(s, 0);
    cout << f[s];
    return 0;
}
/*
dp[x]表示以x为根的子树中任何一个点到点x的距离
f[x]表示以x为根的子树中最少使用道具的次数
*/