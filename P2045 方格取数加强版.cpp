#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, inf = 1e9;
int n, c[105][105];
struct Edge {
	int nxt, y, z, w;
};
struct Graph {
	int tot = 1, head[20005];
	Edge p[N];
	inline void addedge(int x, int y, int z, int w) {
		p[++tot] = (Edge) {head[x], y, z, w};
		head[x] = tot;
	}
	inline void add(int x, int y, int z, int w) {
		addedge(x, y, z, w);
		addedge(y, x, 0, -w);
	}
} e;
int S, T, k;
int dis[N], vis[N], pre[N], flow[N];
inline bool spfa()
{
	memset(dis, 0x3f, sizeof(int) * (T + 1));
	queue<int> q; dis[S] = 0;
	q.push(S); flow[S] = inf; flow[T] = 0;
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		vis[x] = 0;
		for(int i = e.head[x]; i; i = e.p[i].nxt)
		{
			int y = e.p[i].y, z = e.p[i].z, cost = e.p[i].w;
			if(!z || dis[y] <= dis[x] + cost) continue;
			dis[y] = dis[x] + cost;
			pre[y] = i; flow[y] = min(z, flow[x]);
			if(!vis[y]) q.push(y), vis[y] = 1;
		}
	}
	return flow[T];
}
int mincost;
inline void update()
{
	for(int x = T; x != S; x = e.p[pre[x] ^ 1].y)
	{
		mincost += flow[T] * e.p[pre[x]].w;
		e.p[pre[x]].z -= flow[T]; e.p[pre[x] ^ 1].z += flow[T];
	}
}
inline int h(int x, int y, int p) {return (x + p - 1) * n + y;}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k; S = 2 * n * n + 1; T = S + 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> c[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			if(i > 1) e.add(h(i - 1, j, n), h(i, j, 0), inf, 0);
			if(j > 1) e.add(h(i, j - 1, n), h(i, j, 0), inf, 0);
			e.add(h(i, j, 0), h(i, j, n), 1, -c[i][j]);
			e.add(h(i, j, 0), h(i, j, n), inf, 0);
		}
	e.add(S, h(1, 1, 0), k, 0);
	e.add(h(n, n, n), T, k, 0);
	while(spfa()) update();
	cout << -mincost << '\n';
	return 0;
}