#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 5;
int n, k, tot;
int f[50005][505], t[505];
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
void dfs1(int x, int fa)
{
    f[x][0] = 1;
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(y == fa) continue;
        dfs1(y, x);
        for(int l = 1; l <= k; l++)
            f[x][l] += f[y][l - 1];
    }
    int sum = 0;
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(y == fa) continue;
        for(int p = 0; p < k - 1; p++)
        {
            if(!f[y][p]) break;
            if(f[x][k - p - 1] < f[y][k - p - 2]) continue;
            sum += f[y][p] * (f[x][k - p - 1] - f[y][k - p - 2]);
        }
    }
    f[x][k] += sum / 2;
}
int ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs1(1, 0);
    for(int i = 1; i <= n; i++)
        ans += f[i][k];
    cout << ans;
    return 0;
}
/*
f[i][k]表示当前节点出发长度为k的路径条数
对于每个点，只有两种可能
一，它是路径端点
二，它是路径中的点
所以只要照着这个思路dp就行了
*/