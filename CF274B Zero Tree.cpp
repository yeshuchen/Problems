#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, tot;
int a[N], f[N], ad[N], del[N];
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
inline void dfs(int x, int fa)
{
    int maxn = 0, minn = 0;
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(y == fa) continue;
        dfs(y, x);
        maxn = max(maxn, ad[y]);
        minn = max(minn, del[y]);
    }
    del[x] = minn, ad[x] = maxn;
    if(a[x] + maxn - minn > 0) del[x] += abs(a[x] + maxn - minn);
    else ad[x] += abs(a[x] + maxn - minn);
    f[x] = maxn + minn + abs(a[x] + maxn - minn);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    dfs(1, 0);
    cout << f[1];
    return 0;
}
/*
f[i]表示以i为根的子树，按照题意进行操作的最小次数
同时记录将当前子树全改为0
加了多少次，减了多少次
所有子树的增加次数和减少次数取最大值即可
然后再统计一下对于根节点的影响，更新次数
不要忘记开long long
*/