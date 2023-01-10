#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, TOT, cnt, res, top;
int old[N], dfn[N], low[N], vis[N], ins[N], stk[N];
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
	ver[++TOT] = y;
	nxt[TOT] = head[x];
	head[x] = TOT;
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
	while(cin >> n >> m)
	{
		int tot = 0; TOT = res = top = cnt = 0;
		memset(dfn, 0, sizeof(dfn));
		memset(low, 0, sizeof(low));
		memset(vis, 0, sizeof(vis));
		memset(ins, 0, sizeof(ins));
		memset(stk, 0, sizeof(stk));
		memset(head, 0, sizeof(head));
		for(int i = 1; i <= n; i++)
			cin >> old[i], tot += old[i];
		for(int i = 1; i <= m; i++)
		{
			int x, y;
			cin >> x >> y;
			if((old[x] * n >= tot) == (old[y] * n >= tot))
				add(x + n, y), add(y + n, x);
			add(x, y + n); add(y, x + n);
		}	
		for(int i = 1; i <= 2 * n; i++)
			if(!dfn[i])
				tarjan(i);
		for(int i = 1; i <= n; i++)
			if(ins[i] == ins[i + n])
			{
				cout << "No solution.\n";
				goto here;
			}
		for(int i = 1; i <= n; i++)
		{
			if(ins[i] < ins[i + n]) cout << "C\n";
			else
			{
				if(old[i] * n >= tot) cout << "A\n";
				else cout << "B\n";
			}	
		}
		here:;
	}
	return 0;
}