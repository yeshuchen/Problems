#include<bits/stdc++.h>
using namespace std;
const int N = 3e6 + 5;
int n, m, tot, cnt, res, top;
int dfn[N], low[N], vis[N], ins[N], stk[N];
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
inline void tarjan(int x)
{
	dfn[x] = low[x] = ++res;
	stk[++top] = x; vis[x] = 1;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(!dfn[y])
		{
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
		else if(vis[y]) low[x] = min(low[x], dfn[y]);
	}
	if(dfn[x] == low[x])
	{
		cnt++;
		while(stk[top + 1] != x)
		{
			ins[stk[top]] = cnt;
			vis[stk[top]] = 0;
			top--;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int p = 1; p <= m; p++)
	{
		int i, a, j, b;
		cin >> i >> a >> j >> b;
		add(i + a * n, j + (b ^ 1) * n);
		add(j + b * n, i + (a ^ 1) * n);
	}
	for(int i = 1; i <= 2 * n; i++)
		if(!dfn[i])
			tarjan(i);
	for(int i = 1; i <= n; i++)
		if(ins[i] == ins[i + n])
		{
			cout << "IMPOSSIBLE";
			return 0;
		}
	cout << "POSSIBLE\n";
	for(int i = 1; i <= n; i++)
		cout << (ins[i] < ins[i + n]) << ' ';
	return 0;
}