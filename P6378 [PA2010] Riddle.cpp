#include<bits/stdc++.h>
using namespace std;
const int N = 5e6 + 5;
int n, m, k, tot;
int ver[N << 2], nxt[N << 2], head[N << 2];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int top, res, cnt;
int a[N], pre[N][2];
int dfn[N], low[N], stk[N], vis[N], ins[N];
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
	if(low[x] == dfn[x])
	{
		cnt++;
		while(stk[top + 1] != x)
		{
			ins[stk[top]] = cnt;
			vis[stk[top--]] = 0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x + n, y);
		add(y + n, x);
	}
	int CNT = 2 * n;
	for(int i = 1; i <= k; i++)
	{
		int total;
		cin >> total;
		for(int j = 1; j <= total; j++)
		{
			cin >> a[j];
			pre[a[j]][0] = ++CNT;
			pre[a[j]][1] = ++CNT;
			add(a[j], pre[a[j]][0]);
			add(pre[a[j]][1], a[j] + n);
		}
		for(int j = 2; j <= total; j++)
		{
			int x = a[j - 1], y = a[j];
			add(pre[x][0], pre[y][0]);
			add(pre[y][1], pre[x][1]);
			add(pre[x][0], y + n);
			add(y, pre[x][1]);
		}
	}
	for(int i = 1; i <= CNT; i++)
		if(!dfn[i])
			tarjan(i);
	for(int i = 1; i <= n; i++)
		if(ins[i] == ins[i + n])
		{
			cout << "NIE";
			return 0;
		}
	cout << "TAK";
	return 0;
}