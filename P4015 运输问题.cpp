#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, inf = 1e9;
int n, m, c[105][105];
struct Edge {
	int nxt, y, z, w;
};
struct Graph {
	int tot = 1, head[305];
	Edge p[N];
	inline void addedge(int x, int y, int z, int w) {
		p[++tot] = (Edge) {head[x], y, z, w};
		head[x] = tot;
	}
	inline void add(int x, int y, int z, int w) {
		addedge(x, y, z, w);
		addedge(y, x, 0, -w);
	}
} e, E;
int S, T;
int dis[N], vis[N], pre[N], flow[N];
inline bool spfa()
{
	memset(dis, 0x3f, sizeof(dis));
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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m; S = n + m + 1; T = S + 1;
	for(int i = 1, x; i <= n; i++) {
		cin >> x; 
		e.add(S, i, x, 0);
		E.add(S, i, x, 0);
	}
	for(int i = 1, x; i <= m; i++) {
		cin >> x;
		e.add(i + n, T, x, 0);
		E.add(i + n, T, x, 0);
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> c[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			e.add(i, j + n, inf, c[i][j]);
			E.add(i, j + n, inf, -c[i][j]);
		}
	while(spfa()) update();
	cout << mincost << '\n';
	e = E; mincost = 0;
	while(spfa()) update();
	cout << -mincost;
	return 0;
}