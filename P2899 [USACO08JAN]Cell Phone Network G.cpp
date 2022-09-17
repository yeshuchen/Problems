#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, tot;
int f[N][5];
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
void dfs(int x, int fa)
{
    f[x][1] = 1;
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(y == fa) continue;
        dfs(y, x);
        f[x][0] += min(f[y][1], f[y][2]);
        f[x][1] += min(min(f[y][0], f[y][1]), f[y][2]);
    }
    f[x][2] = INT_MAX;
    for(int i = head[x]; i; i = nxt[i])
    {
        int y = ver[i];
        if(y == fa) continue;
        int temp = f[y][1];
        for(int j = head[x]; j; j = nxt[j])
        {
            int y2 = ver[j];
            if(y2 == y || y2 == fa) continue;
            temp += min(f[y2][1], f[y2][2]);
        }
        f[x][2] = min(f[x][2], temp);
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
        add(x, y);
        add(y, x);
    }
    dfs(1, 0);
    cout << min(f[1][1], f[1][2]);
    return 0;
}
/*
f[i][0]表示这个节点父亲被选
f[i][1]表示这个节点本身被选
f[i][2]表示这个节点儿子被选
*/