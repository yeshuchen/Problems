#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, t, tot;
int f[N], ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
inline void dfs(int x, int fa)
{
    f[x] = 0;
    vector<int> g;
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(y == fa) continue;
        dfs(y, x);
        g.push_back(f[y]);
    }
    if(g.empty())
    {
        f[x] = 1;
        return;
    }
    sort(g.begin(), g.end());
    int cnt = ceil(g.size() * t * 1.0 / 100);
    for(int i = 0; i < cnt; i++)
        f[x] += g[i];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while(cin >> n >> t)
    {
        if(!n && !t) break;
        for(int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            add(x, i);
            add(i, x);
        }
        dfs(0, 0);
        cout << f[0] << '\n';
        for(int i = 0; i <= n; i++) head[i] = 0; 
    }
    return 0;
}