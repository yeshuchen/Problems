#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n, tot;
int ver[N], val[N], nxt[N], head[N];
inline void add(int x, int y, int z)
{
    ver[++tot] = y;
    val[tot] = z;
    nxt[tot] = head[x];
    head[x] = tot;
}
int cnt, sum[N], t[N][2];
inline void dfs(int x, int fa)
{
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i], z = val[i];
        if(y == fa) continue;
        sum[y] = sum[x] ^ z;
        dfs(y, x);
    }
}
inline void insert(int x)
{
    int num = sum[x], pos = 0;
    for(int i = 30; i >= 0; i--)
    {
        bool f = num & (1 << i);
        if(!t[pos][f]) t[pos][f] = ++cnt;
        pos = t[pos][f];
    }
}
inline int query(int x)
{
    int num = sum[x], pos = 0, res = 0;
    for(int i = 30; i >= 0; i--)
    {
        bool f = num & (1 << i);
        if(t[pos][!f]) res += (1 << i), pos = t[pos][!f];
        else pos = t[pos][f];
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++)
        insert(i);
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, query(i));
    cout << ans;
    return 0;
}