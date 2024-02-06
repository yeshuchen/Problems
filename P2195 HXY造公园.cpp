#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n, m, k;
int f[N], s[N];
int find(int k) {return f[k] == k ? k : f[k] = find(f[k]);}
void merge(int x, int y)
{
	x = find(x); y = find(y);
	if(x == y) return;
	f[y] = x;
	s[x] = max({(s[x] + 1) / 2 + (s[y] + 1) / 2 + 1, s[x], s[y]});
}
int vis[N];
vector<int> g[N];
int dfs(int x, int fa)
{
	int mx1 = 0, mx2 = 0;
	vis[x] = 1; f[x] = fa;
	for(int y : g[x])
	{
		if(vis[y]) continue;
		int v = dfs(y, fa) + 1;
		if(v >= mx1) mx2 = mx1, mx1 = v;
		else if(v >= mx2) mx2 = v;
	}
	s[fa] = max(s[fa], mx1 + mx2);
	return mx1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i = 1; i <= n; i++)
		if(!vis[i]) dfs(i, i);
	for(int i = 1; i <= k; i++)
	{
		int op, x, y;
		cin >> op >> x;
		if(op == 2) cin >> y, merge(x, y);
		else cout << s[find(x)] << '\n';
	}
	return 0;
}