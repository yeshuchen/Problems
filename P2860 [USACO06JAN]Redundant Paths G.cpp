#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m;
struct Edge
{
    int tot;
    int ver[N], nxt[N], head[N];
    inline void add(int x, int y)
    {
        ver[++tot] = y;
        nxt[tot] = head[x];
        head[x] = tot;
    }
}E;
int cnt, top, res;
int stk[N], dfn[N], low[N], ins[N];
inline void tarjan(int x, int fa)
{
	stk[++top] = x;
	dfn[x] = low[x] = ++res;
	for(int i = E.head[x]; i; i = E.nxt[i])
	{
		int y = E.ver[i];
		if(!dfn[y])
		{
			tarjan(y, x);
			low[x] = min(low[x], low[y]);
			if(low[y] > dfn[x])
			{
				cnt++;
				while(stk[top + 1] != y)
					ins[stk[top--]] = cnt;
			}
		}
		else if(y != fa) low[x] = min(low[x], dfn[y]);
	}
}
int d[N], vis[N];
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        E.add(x, y);
        E.add(y, x);
    }
    tarjan(1, 0);
    cnt++;
    while(top)
        ins[stk[top--]] = cnt;
    for(int x = 1; x <= n; x++)
	{
		for(int i = E.head[x]; i; i = E.nxt[i])
		{
			int y = E.ver[i];
			if(vis[y]) continue;
			vis[y] = 1;
			if(ins[y] != ins[x]) d[ins[x]]++, d[ins[y]]++;
		}
		for(int i = E.head[x]; i; i = E.nxt[i])
			vis[E.ver[i]] = 0;
	}
	int ans = 0;
	for(int i = 1; i <= cnt; i++)
		ans += (d[i] == 2);
	cout << (ans + 1) / 2;
}