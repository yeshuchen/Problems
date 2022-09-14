#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, tot;
char a[N];
int top[N];
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
void dfs(int x, int fa)
{
    if(a[x] == a[fa]) top[x] = top[fa];
    else top[x] = x;
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(y == fa) continue;
        dfs(y, x);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs(1, 0);
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        char ch;
        cin >> x >> y >> ch;
        if(top[x] == top[y] && a[x] != ch) cout << 0;
        else cout << 1;
    }
    return 0;
}