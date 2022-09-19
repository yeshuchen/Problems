#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int n, tot;
int f[N];
int ver[N], val[N], nxt[N], head[N];
struct node{
    int st, ed;
}a[N];
inline void add(int x, int y, int z)
{
    ver[++tot] = y;
    val[tot] = z;
    nxt[tot] = head[x];
    head[x] = tot;
}
inline void dfs1(int x, int fa)
{
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i], z = val[i];
        if(y == fa) continue;
        dfs1(y, x);
        f[x] += f[y];
        if(a[z].st == y) f[x]++;
    }
}
inline void dfs2(int x, int fa, int rank)
{
    int z = val[rank];
    if(a[z].st == fa) f[x] = f[fa] + 1;
    else f[x] = f[fa] - 1;
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(y == fa) continue;
        dfs2(y, x, i);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y, i);
        add(y, x, i);
        a[i].st = x, a[i].ed = y;
    }
    dfs1(1, 0);
    for(int i = head[1]; i; i = nxt[i])
        dfs2(ver[i], 1, i);
    int minn = 1;
    for(int i = 1; i <= n; i++)
        if(f[minn] > f[i])
            minn = i;
    cout << f[minn] << '\n';
    for(int i = 1; i <= n; i++)
        if(f[minn] == f[i])
            cout << i << ' ';
    return 0;
}