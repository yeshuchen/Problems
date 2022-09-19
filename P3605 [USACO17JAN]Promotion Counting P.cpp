#include<bits/stdc++.h>
using namespace std;
const int N = 4e6 + 5;
int n, tot, cnt;
int root[N];
int v[N], temp[N], ans[N];
int ver[N], nxt[N], head[N];
struct NODE{
    int ls, rs, val;
}a[N];
inline void add(int x, int y)
{
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
inline int change(int node, int l, int r, int d)
{
    if(!node) node = ++cnt;
    if(l == r)
    {
        a[node].val = 1;
        return node;
    }
    int mid = l + r >> 1;
    if(d <= mid) a[node].ls = change(a[node].ls, l, mid, d);
    if(d > mid) a[node].rs = change(a[node].rs, mid + 1, r, d);
    a[node].val = a[a[node].ls].val + a[a[node].rs].val;
    return node;
}
inline int merge(int x, int y)
{
    if(!x || !y) return x ^ y;
    a[x].val += a[y].val;
    a[x].ls = merge(a[x].ls, a[y].ls);
    a[x].rs = merge(a[x].rs, a[y].rs);
    return x;
}
inline int ask(int node, int l, int r, int L, int R)
{
    if(L <= l && r <= R) return a[node].val;
    int mid = l + r >> 1, val = 0;
    if(L <= mid) val += ask(a[node].ls, l, mid, L, R);
    if(R > mid) val += ask(a[node].rs, mid + 1, r, L, R);
    return val;
}
inline void dfs(int x, int fa)
{
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(y == fa) continue;
        dfs(y, x);
        root[x] = merge(root[x], root[y]);
    }
    ans[x] = ask(root[x], 1, n, v[x] + 1, n);
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> v[i], temp[i] = v[i];
    sort(temp + 1, temp + n + 1);
    int tot = unique(temp + 1, temp + n + 1) - temp - 1;
    for(int i = 1; i <= tot; i++)
        v[i] = lower_bound(temp + 1, temp + tot + 1, v[i]) - temp;
    for(int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        add(x, i);
        add(i, x);
    }
    for(int i = 1; i <= n; i++)
        root[i] = change(root[i], 1, n, v[i]);
    dfs(1, 0);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
    return 0;
}