#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m;
bool vis[N];
int f[N], d[N];
vector<int> g[N];
inline int find(int k) {return f[k] == k ? k : f[k] = find(f[k]);}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		d[y]++;
		g[x].push_back(y);
		int fx = find(x), fy = find(y);
		if(fx != fy) f[fx] = fy;
	}
	int ans = n;
	for(int i = 1; i <= n; i++)
	{
		f[i] = find(i);
		ans -= (!vis[f[i]]);
		vis[f[i]] = 1;
	}
	queue<int> q;
	for(int i = 1; i <= n; i++)
		if(!d[i])
			q.push(i);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for(int i = 0; i < g[x].size(); i++)
		{
			int y = g[x][i];
			d[y]--;
			if(!d[y]) q.push(y);
		}
	}
	for(int i = 1; i <= n; i++)
		if(d[i])
		{
			ans += vis[f[i]];
			vis[f[i]] = 0;
		}
	cout << ans;
	return 0;
}