#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int T, n, m;
struct edge {
	int x, y, z, nxt;
} e[N];
int deg[N];
struct Graph 
{
	edge e[N];
	int tot, cnt, res, top;
	int head[N], stk[N], vis[N], dfn[N], low[N], id[N];
	void init()
	{
		tot = cnt = res = top = 0;
		memset(head, 0, (n + 1) * sizeof(int));
		memset(stk, 0, (n + 5) * sizeof(int));
		memset(dfn, 0, (n + 1) * sizeof(int));
	}
	void add(int x, int y, int z = 0)
	{
		e[++tot] = {x, y, z, head[x]};
		head[x] = tot;
	}
	void tarjan(int x)
	{
		vis[x] = 1;
		stk[++top] = x;
		dfn[x] = low[x] = ++res;
		for(int i = head[x]; i; i = e[i].nxt)
		{
			int y = e[i].y;
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
				id[stk[top]] = cnt;
				vis[stk[top]] = 0;
				top--;
			}
		}
	}
} E;
bool check(int w)
{
	E.init();
	for(int i = 1; i <= n; i++) deg[i] = 0;
	for(int i = 1; i <= m; i++)
	{
		E.add(e[i].x, e[i].y);
		if(e[i].z <= w) E.add(e[i].y, e[i].x);
	}
	for(int i = 1; i <= n; i++)
		if(!E.dfn[i]) E.tarjan(i);
	for(int i = 1; i <= n; i++)
	{
		for(int j = E.head[i]; j; j = E.e[j].nxt)
		{
			int y = E.e[j].y;
			if(E.id[i] == E.id[y]) continue;
			deg[E.id[y]]++;
		}
	}
	int res = 0;
	for(int i = 1; i <= E.cnt; i++)
		res += !deg[i];
	return res == 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int l = 0, r = 0, ans = -1;
		cin >> n >> m;
		for(int i = 1; i <= m; i++)
		{
			cin >> e[i].x >> e[i].y >> e[i].z;
			r = max(r, e[i].z);
		}
		while(l <= r)
		{
			int mid = l + r >> 1;
			if(check(mid)) r = (ans = mid) - 1;
			else l = mid + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}