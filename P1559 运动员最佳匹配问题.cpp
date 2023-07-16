#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, inf = 1e9;
int tot = 1;
struct Edge {
	int nxt, y, z, w;
} e[N];
int n, m, S, T;
int head[N], dis[N], flow[N];
inline void addedge(int x, int y, int z, int w)
{
	e[++tot] = (Edge) {head[x], y, z, w};
	head[x] = tot;
}
inline void add(int x, int y, int z, int w)
{
	addedge(x, y, z, w);
	addedge(y, x, 0, -w);
}
int pre[N], vis[N];
inline bool spfa()
{
	queue<int> q;
	memset(dis, 0x3f, sizeof(dis));
	dis[S] = 0; flow[S] = inf; flow[T] = 0;
	q.push(S);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		vis[x] = 0;
		for(int i = head[x]; i; i = e[i].nxt)
		{
			int y = e[i].y, z = e[i].z, cost = e[i].w;
			if(!z || dis[y] <= dis[x] + cost) continue;
			dis[y] = dis[x] + cost;
			flow[y] = min(z, flow[x]);
			pre[y] = i;
			if(!vis[y]) q.push(y), vis[y] = 1;
		}
	}
	return flow[T];
}
int maxflow, mincost;
inline void update()
{
	maxflow += flow[T];
	for(int x = T; x != S; x = e[pre[x] ^ 1].y)
	{
		e[pre[x]].z -= flow[T]; e[pre[x] ^ 1].z += flow[T];
		mincost += flow[T] * e[pre[x]].w;
	}
}
int p[25][25], q[25][25];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> p[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> q[i][j];
	S = n * n + 1; T = n * n + 2;
	for(int i = 1; i <= n; i++)
	{
		add(S, i, 1, 0);
		add(i + n, T, 1, 0);
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			add(i, j + n, 1, -p[i][j] * q[j][i]);
	while(spfa())
		update();
	cout << -mincost;
	return 0;
}