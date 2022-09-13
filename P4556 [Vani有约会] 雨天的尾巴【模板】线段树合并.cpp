#include<bits/stdc++.h>
using namespace std;
const int N = 6e6 + 5;
struct que{
    int x, y, z;
}q[N];
struct tree{
    int ls, rs, maxn, maxv;
}t[N];
int n, m, mz, res;
int tot, head[N], nxt[N], ver[N];
int f[N], size[N], dep[N], son[N];
int ans[N], top[N], root[N];
inline void add(int x, int y)
{
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
int dfs1(int x, int fa)
{
    f[x] = fa; size[x] = 1; dep[x] = dep[fa] + 1;
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(y == fa)continue;
        size[x] += dfs1(y, x);
        if(size[y] > size[son[x]])
            son[x] = y;
    }
    return size[x];
}
void dfs2(int x, int t)
{
    top[x] = t;
    if(son[x])dfs2(son[x], t);
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(y == son[x] || y == f[x])continue;
        dfs2(y, y);
    }
}
int lca(int x, int y)
{
    while(top[x] != top[y])
    {
        if(dep[top[x]] < dep[top[y]])swap(x, y);
        x = f[top[x]];
    }
    return dep[x] < dep[y] ? x : y;
}
int change(int node, int l, int r, int d, int k)
{
    if(!node) node = ++res;
    if(l == r)
    {
        t[node].maxv += k;
        t[node].maxn = l;
        return node;
    }
    int mid = l + r >> 1;
    if(d <= mid) t[node].ls = change(t[node].ls, l, mid, d, k);
    else t[node].rs = change(t[node].rs, mid + 1, r, d, k);
    t[node].maxv = max(t[t[node].ls].maxv, t[t[node].rs].maxv);
    if(t[t[node].ls].maxv >= t[t[node].rs].maxv)
        t[node].maxn = t[t[node].ls].maxn;
    else t[node].maxn = t[t[node].rs].maxn;
    return node;
}
int merge(int x, int y)
{
    if(!x || !y) return x ^ y;
    t[x].ls = merge(t[x].ls, t[y].ls);
    t[x].rs = merge(t[x].rs, t[y].rs);
    if(!t[x].ls && !t[x].rs)
        t[x].maxv += t[y].maxv;
    else
    {
        t[x].maxv = max(t[t[x].ls].maxv, t[t[x].rs].maxv);
        if(t[t[x].ls].maxv >= t[t[x].rs].maxv)
            t[x].maxn = t[t[x].ls].maxn;
        else t[x].maxn = t[t[x].rs].maxn;
    }
    return x;
}
void mer(int x)
{
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(y == f[x])continue;
        mer(y);
        root[x] = merge(root[x], root[y]);
    }
    if(t[root[x]].maxv)ans[x] = t[root[x]].maxn;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs1(1, 0);dfs2(1, 1);
    for(int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        q[i] = (que){x, y, z};
        mz = max(mz, z);
    }
    for(int i = 1; i <= m; i++)
    {
        int x = q[i].x, y = q[i].y, z = q[i].z;
        int l = lca(x, y);
        root[x] = change(root[x], 1, mz, z, 1);
        root[y] = change(root[y], 1, mz, z, 1);
        root[l] = change(root[l], 1, mz, z, -1);
        if(f[l]) root[f[l]] = change(root[f[l]], 1, mz, z, -1);
    }
    mer(1);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
    return 0;
}