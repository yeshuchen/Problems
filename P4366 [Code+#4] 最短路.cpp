#include<bits/stdc++.h>
using namespace std;
const int N = 8e6 + 5;
int n, m, c, tot;
int ver[N], nxt[N], val[N], head[N];
void add(int x, int y, int z)
{
	ver[++tot] = y;
	val[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
}
int dis[N], vis[N];
void dij(int st)
{
	memset(dis, 0x3f, sizeof(dis));
	dis[st] = 0;
	priority_queue< pair<int, int> > q;
	q.push(make_pair(0, st));
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
				q.push(make_pair(-dis[y], y));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> c;
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}
	for(int i = 0; i <= n; i++)
	{
		for(int j = 1; j <= n; j <<= 1)
		{
			int y = i ^ j;
			if(y <= n) add(i, y, j * c);
		}
	}
	int st, ed;
	cin >> st >> ed;
	dij(st);
	cout << dis[ed];
	return 0;
}