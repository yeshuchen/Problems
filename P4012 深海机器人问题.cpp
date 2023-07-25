#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5, inf = 1e9;
int c, n, m, S, T, tot = 1;
struct Edge {
	int nxt, y, z, w;
} e[N];
int head[N];
inline int h(int x, int y) {return (x - 1) * m + y;}
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
int dis[N], vis[N], pre[N], flow[N];
inline bool spfa()
{
	queue<int> q;
	memset(dis, 0x3f, sizeof(dis));
	dis[S] = 0; flow[S] = inf; flow[T] = 0; q.push(S);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		vis[x] = 0;
		for(int i = head[x]; i; i = e[i].nxt)
		{
			int y = e[i].y, z = e[i].z, w = e[i].w;
			if(!z || dis[y] <= dis[x] + w) continue;
			dis[y] = dis[x] + w;
			pre[y] = i; flow[y] = min(z, flow[x]);
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
		int w1 = e[pre[x] ^ 1].y, w2 = x;
		mincost += flow[T] * e[pre[x]].w; 
		e[pre[x]].z -= flow[T]; e[pre[x] ^ 1].z += flow[T];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int p, q;
	cin >> p >> q >> n >> m;
	n++; m++;
	S = 2 * n * m + 1; T = S + 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j < m; j++)
		{
			int x;
			cin >> x;
			add(h(i, j), h(i, j + 1), 1, -x);
			add(h(i, j), h(i, j + 1), inf, 0);
		}
	for(int j = 1; j <= m; j++)
		for(int i = 1; i < n; i++)
		{
			int x;
			cin >> x;
			add(h(i, j), h(i + 1, j), 1, -x);
			add(h(i, j), h(i + 1, j), inf, 0);
		}
	for(int i = 1; i <= p; i++)
	{
		int k, x, y;
		cin >> k >> x >> y;
		x++; y++;
		add(S, h(x, y), k, 0);
	}
	for(int i = 1; i <= q; i++)
	{
		int k, x, y;
		cin >> k >> x >> y;
		x++; y++;
		add(h(x, y), T, k, 0);
	}
	while(spfa()) update();
	cout << -mincost;
	return 0;
}