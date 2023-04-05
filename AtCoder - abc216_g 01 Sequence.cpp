#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, tot;
int ver[N], val[N], nxt[N], head[N];
inline void add(int x, int y, int z)
{
	ver[++tot] = y;
	val[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
}
int dis[N], vis[N];
inline void dij()
{
	for(int i = 1; i <= n; i++) dis[i] = INT_MAX;
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
	q.push(make_pair(0, 0));
	while(!q.empty())
	{
		int x = q.top().second; q.pop();
		if(vis[x]) continue;
		vis[x] = 1;
		for(int i = head[x]; i; i = nxt[i])
		{
			int y = ver[i], z = val[i];
			if(dis[x] + z < dis[y])
			{
				dis[y] = dis[x] + z;
				q.push(make_pair(dis[y], y));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i < n; i++)
		add(i, i + 1, 1), add(i + 1, i, 0);
	add(0, 1, 1);
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x - 1, y, y - x + 1 - z);
	}
	dij();
	for(int i = 1; i <= n; i++)
		cout << (dis[i] == dis[i - 1]) << ' ';
	return 0;
}