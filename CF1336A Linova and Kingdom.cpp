#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int n, m, tot;
int sz[N];
int id[N], dep[N], vis[N];
int ver[N], nxt[N], head[N];
void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
void dfs(int x, int fa)
{
	dep[x] = dep[fa] + 1; sz[x] = 1;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		dfs(y, x); sz[x] += sz[y];
	}
}
int ans;
void dfs2(int x, int num)
{
	if(vis[x]) ans += num;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(dep[y] == dep[x] + 1)
			dfs2(y, num + (vis[x] == 0));
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i < n; i++)
	{
		id[i] = i;
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
	}
	id[n] = n;
	dfs(1, 0);
	sort(id + 1, id + n + 1, [](int x, int y) {return dep[x] - sz[x] > dep[y] - sz[y];});
	for(int i = 1; i <= m; i++)
		vis[id[i]] = 1;
	dfs2(1, 0);
	cout << ans;
	return 0;
}