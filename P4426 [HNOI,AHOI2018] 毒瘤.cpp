#include<bits/stdc++.h>
#define ri register int
using namespace std;
const int N = 2e5 + 50, mod = 998244353;
int n, m;
struct node {
	int tot;
	int ver[N], nxt[N], head[N];
	inline void add(int x, int y)
	{
		ver[++tot] = y;
		nxt[tot] = head[x];
		head[x] = tot;
	}
} E;
int ret, f[N][2], vis[N], dfn[N];
inline void bfs()
{
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int x = q.front(); q.pop(); dfn[x] = ++ret;
		for(int i = E.head[x]; i; i = E.nxt[i])
		{
			int y = E.ver[i];
			if(dfn[y]) continue;
			q.push(y);
		}
	}
}
int l[N], r[N];
int res, father[N], sz[N];
inline int find(int k) {return father[k] == k ? k : father[k] = find(father[k]);}
struct Edge {
	int x, y;
} edge[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(ri i = 1; i <= n; i++) father[i] = i, sz[i] = 1;
	for(ri i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		int fx = find(x), fy = find(y);
		if(fx == fy)
		{
			edge[++res] = {x, y};
			continue;
		}
		E.add(x, y);
		E.add(y, x);
		if(sz[fx] < sz[fy]) swap(fx, fy);
		father[fy] = fx;
		sz[fx] += sz[fy];
	}
	int ans = 0;
	bfs();
	for(ri i = 1; i <= res; i++)
	{
		edge[i].x = dfn[edge[i].x];
		edge[i].y = dfn[edge[i].y];
		if(edge[i].x > edge[i].y)
			swap(edge[i].x, edge[i].y);
	}
	for(ri i = 1; i <= n; i++)
	{
		l[dfn[i]] = INT_MAX;
		for(ri j = E.head[i]; j; j = E.nxt[j])
		{
			int y = E.ver[j];
			if(dfn[i] > dfn[y]) continue;
			l[dfn[i]] = min(l[dfn[i]], dfn[y]);
			r[dfn[i]] = max(r[dfn[i]], dfn[y]);
		}
	}
	for(ri w = 0; w < (1 << res); w++)
	{
		bool flag = 0;
		for(ri i = 1; i <= res; i++)
		{
			if(w & (1 << i - 1)) f[edge[i].y][1] = f[edge[i].x][0] = 0;
			else f[edge[i].x][1] = 0;
			if((!f[edge[i].x][0] && !f[edge[i].x][1]) || (!f[edge[i].y][0] && !f[edge[i].y][1]))
			{
				flag = 1;
				break;
			}
		}
		if(flag) continue;
		for(ri i = n; i; i--)
			for(ri j = l[i]; j <= r[i]; j++)
			{
				f[i][0] = 1ull * f[i][0] * (f[j][0] + f[j][1]) % mod;
				f[i][1] = 1ull * f[i][1] * f[j][0] % mod;
				f[j][0] = f[j][1] = 1;
			}
		ans = (1ull * ans + f[1][0] + f[1][1]) % mod;
	}
	cout << ans << '\n';
	return 0;
}