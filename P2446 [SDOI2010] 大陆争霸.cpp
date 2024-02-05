#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int n, m, tot;
int ver[N], nxt[N], val[N], head[N];
void add(int x, int y, int z)
{
	ver[++tot] = y;
	val[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
}
vector<int> g[N];
int deg[N], dis[N], vis[N];
void dij()
{
	priority_queue< pair<int, int> > q;
	q.push(make_pair(0, 1));
	for(int i = 2; i <= n; i++) dis[i] = LLONG_MAX;
	while(!q.empty())
	{
		int x = q.top().second; q.pop();
		// cout << x << ' ';
		if(vis[x]) continue;
		vis[x] = 1;
		for(int i = head[x]; i; i = nxt[i])
		{
			int y = ver[i], z = val[i];
			if(dis[y] > dis[x] + z)
			{
				dis[y] = dis[x] + z;
				if(!deg[y]) q.push(make_pair(-dis[y], y));
			}
		}
		for(int y : g[x])
		{
			deg[y]--;
			dis[y] = max(dis[y], dis[x]);
			if(!deg[y]) q.push(make_pair(-dis[y], y));
		}
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{	
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> deg[i];
		for(int j = 1, y; j <= deg[i]; j++)
			cin >> y, g[y].push_back(i);
	}
	dij();
	cout << dis[n];
	return 0;
}