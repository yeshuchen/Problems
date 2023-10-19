#include<bits/stdc++.h>
#define mk(x, y) make_pair(x, y)
using namespace std;
int n, m;
int ans[1000005];
int a[1000005], f[1000005], tmp[1000005];
vector< pair<int, int> > v[1000005];
int find(int k) {return f[k] == k ? k : f[k] = find(f[k]);}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i], f[i] = i;
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		x = find(x); y = find(y);
		if(x == y) continue;
		f[y] = x;
	}
	for(int i = 1; i <= n; i++)
	{
		f[i] = find(i);
		v[f[i]].push_back(mk(a[i], i));
	}
	for(int i = 1; i <= n; i++)
	{
		int res = 0;
		for(auto x : v[i])
			tmp[++res] = x.second;
		sort(v[i].begin(), v[i].end());
		for(int j = 1; j <= res; j++)
			ans[tmp[j]] = v[i][v[i].size() - j].first;
	}
	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
}