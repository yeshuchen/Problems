#include<bits/stdc++.h>
using namespace std;
int n, m, res;
int a[500005], b[500005], p[500005];
int vis[500005], minn[500005], d[500005];
inline void dfs(int x)
{
	if(vis[x]) return;
	vis[x] = res; d[res]++;
	if(a[minn[res]] > a[x])
		minn[res] = x;
	dfs(p[x]);
}
int x[400005], y[400005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	for(int i = 1; i <= n; i++)
	{
		int t;
		cin >> t;
		p[t] = i;
		if(a[i] <= b[t] && p[i] != i)
		{
			cout << -1 << '\n';
			return 0;
		}
	}
	a[0] = INT_MAX;
	for(int i = 1; i <= n; i++)
		if(!vis[i])
		{
			res++;
			dfs(i);
		}
	n = res; res = 0;
	for(int i = 1; i <= n; i++)
	{
		int begin = minn[i];
		for(int j = 1; j < d[i]; j++)
		{
			x[++res] = begin, y[res] = p[begin];
			begin = p[begin];
		}
	}
	cout << res << '\n';
	for(int i = 1; i <= res; i++)
		cout << x[i] << ' ' << y[i] << '\n';
	return 0;
}