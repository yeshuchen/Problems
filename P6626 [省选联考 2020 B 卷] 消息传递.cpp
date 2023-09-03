#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
bool vis[N];
int T, n, m, rt, tot;
int sum, mx[N], sz[N];
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;	
}
inline void grt(int x, int fa)
{
	sz[x] = 1;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa || vis[y]) continue;
		grt(y, x);
		sz[x] += sz[y];
	}
	mx[x] = max(sz[x], sum - sz[x]);
	if(mx[x] <= mx[rt]) rt = x;
}
int cnt, g[N];
int bg[N], ed[N];
int dep[N], stk[N];
vector< pair<int, int> > v[N];
inline void get_dis(int x, int fa)
{
	stk[++cnt] = x; dep[x] = dep[fa] + 1;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(vis[y] || y == fa) continue;
		get_dis(y, x);
	}
	g[dep[x]]++;
}
int ans[N];
inline void solve(int x)
{
	rt = 0; grt(x, 0); x = rt; grt(x, 0);
	vis[x] = 1; dep[x] = 0;
	sum = sz[x];
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(vis[y]) continue;
		bg[y] = cnt + 1;
		get_dis(y, x);
		ed[y] = cnt;
	}
	for(int i = 0; i < v[x].size(); i++)
	{
		int p = v[x][i].second;
		ans[p] += g[v[x][i].first];
	}
	for(int i = head[x]; i; i = nxt[i])	
	{
		int y = ver[i];
		if(vis[y]) continue;
		for(int j = bg[y]; j <= ed[y]; j++) g[dep[stk[j]]]--;
		for(int j = bg[y]; j <= ed[y]; j++)
			for(int k = 0; k < v[stk[j]].size(); k++)
			{
				int p = v[stk[j]][k].second;
				if(v[stk[j]][k].first >= dep[stk[j]])
					ans[p] += g[v[stk[j]][k].first - dep[stk[j]]];
			}
		for(int j = bg[y]; j <= ed[y]; j++) g[dep[stk[j]]]++;
	}
	while(cnt) g[dep[stk[cnt--]]]--;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(vis[y]) continue;
		solve(y);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T; g[0] = 1;
	while(T--)
	{
		cin >> n >> m; tot = 0; rt = 0;
		memset(vis, 0, sizeof(int) * (n + 1));
		memset(head, 0, sizeof(head));
		memset(ans, 0, sizeof(int) * (m + 1));
		for(int i = 1; i <= n; i++) v[i].clear();
		for(int i = 1; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			add(x, y);
			add(y, x);
		}
		for(int i = 1; i <= m; i++)
		{
			int x, k;
			cin >> x >> k;
			v[x].push_back(make_pair(k, i));
		}
		mx[rt] = INT_MAX;
		sum = n; solve(1);
		for(int i = 1; i <= m; i++) cout << ans[i] << '\n';
	}
	return 0;
}