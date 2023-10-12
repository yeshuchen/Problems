#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5, mod = 1000000007;
int n, m, ans;
int pos[N];
int a[N], mn[N], vis[N];
map<int, int> mp[N], p[N];
inline void separate(int id, int v)
{
	vector<int> g;
	while(v > 1)
	{
		g.push_back(mn[v]);
		v /= mn[v];
	}
	// for(int i : g) cout << i << ' ';
	// cout << '\n';
	int last = 0;
	for(int x : g)
	{
		if(x == last) {last = x; continue;}	
		mp[x][p[id][x]]--;
		last = x;
	}
	for(int x : g)
		p[id][x]++;
	last = 0;
	for(int i = 0; i < g.size(); i++)
	{
		int x = g[i];
		if(x == last) {last = x; continue;}
		mp[x][p[id][x]]++;
		last = x;
		while(!mp[x][pos[x]]) pos[x]++, ans = ans * x % mod;
	}
	// for(int i = 1; i <= 10; i++) cout << mp[i][pos[i]] << ' ' << ' ';
	// cout << '\n';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 2; i <= 200000; i++)
	{
		if(vis[i]) continue;
		for(int j = i; j <= 200000; j += i)
		{
			vis[j] = 1;
			if(!mn[j]) mn[j] = i;
		}
	}
	for(int i = 1; i <= 200000; i++) mp[i][0] = n;
	ans = 1;
	for(int i = 1; i <= n; i++)
		cin >> a[i], separate(i, a[i]);
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		separate(x, y);
		cout << ans << '\n';
	}
	return 0;
}