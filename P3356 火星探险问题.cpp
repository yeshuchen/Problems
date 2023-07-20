#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5, inf = 1e9;
int c, n, m, S, T, tot = 1;
struct Edge {
	int nxt, y, z, w, type, rev;
} e[N];
int head[N];
inline int h(int x, int y, int p) {return (x + p * n - 1) * m + y;}
inline void addedge(int x, int y, int z, int w, int tp, int re)
{
	e[++tot] = (Edge) {head[x], y, z, w, tp, re};
	head[x] = tot;
}
inline void add(int x, int y, int z, int w, int re)
{
	addedge(x, y, z, w, 1, re);
	addedge(y, x, 0, -w, 0, re);
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
int di[4] = {1, 0}, dj[4] = {0, 1};
inline void dfs(int x, int car)
{
	if(x == T) return;
	for(int i = head[x]; i; i = e[i].nxt)
	{
		int y = e[i].y, z = e[i].z;
		if(!e[i].type) continue;
		if(e[i ^ 1].z)
		{
			e[i ^ 1].z--;
			if(~e[i].rev)
				cout << car << ' ' << e[i].rev << '\n';
			dfs(e[i].y, car);
			break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c >> n >> m;
	swap(n, m); S = 1; T = h(n, m, 1);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			int x;
			cin >> x;
			if(x == 1) continue;
			if(x == 0) add(h(i, j, 0), h(i, j, 1), c, 0, -1);
			if(x == 2)
			{
				add(h(i, j, 0), h(i, j, 1), c - 1, 0, -1);
				add(h(i, j, 0), h(i, j, 1), 1, -1, -1);
			}
		}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			for(int d = 0; d < 2; d++)
			{
				int ni = i + di[d], nj = j + dj[d];
				if(ni > n || nj > m) continue;
				add(h(i, j, 1), h(ni, nj, 0), c, 0, d);
			}
		}
	while(spfa()) update();
	for(int i = 1; i <= c; i++)
		dfs(h(1, 1, 0), i);
	return 0;
}