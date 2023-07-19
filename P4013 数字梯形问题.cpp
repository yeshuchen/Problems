#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, inf = 1e9;
int n, m, S, T, cnt, tot = 1;
int p[50][50], c[50][50];
struct Edge {
	int nxt, y, z, w;
} e[N];
int head[N];
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
	memset(dis, 0x3f, sizeof(int) * (T + 1));
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
	cin >> m >> n;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m + i - 1; j++)
		{
			p[i][j] = ++cnt;
			cin >> c[i][j];
		}
	}
	S = 2 * cnt + 1; T = S + 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m + i - 1; j++)
		{
			if(i < n)
			{
				add(p[i][j] + cnt, p[i + 1][j], 1, 0);
				add(p[i][j] + cnt, p[i + 1][j + 1], 1, 0);
			}
			add(p[i][j], p[i][j] + cnt, 1, -c[i][j]);
		}
	for(int i = 1; i <= m; i++)
		add(S, p[1][i], 1, 0);
	for(int i = 1; i <= n + m - 1; i++)
		add(p[n][i] + cnt, T, inf, 0);
	while(spfa()) update();
	cout << -mincost << '\n';
	mincost = 0;
	tot = 1;
	memset(head, 0, sizeof(head));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m + i - 1; j++)
		{
			if(i < n)
			{
				add(p[i][j] + cnt, p[i + 1][j], 1, 0);
				add(p[i][j] + cnt, p[i + 1][j + 1], 1, 0);
			}
			add(p[i][j], p[i][j] + cnt, inf, -c[i][j]);
		}
	for(int i = 1; i <= m; i++)
		add(S, p[1][i], 1, 0);
	for(int i = 1; i <= n + m - 1; i++)
		add(p[n][i] + cnt, T, inf, 0);
	while(spfa()) update();
	cout << -mincost << '\n';
	mincost = 0;
	tot = 1;
	memset(head, 0, sizeof(head));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m + i - 1; j++)
		{
			if(i < n)
			{
				add(p[i][j] + cnt, p[i + 1][j], inf, 0);
				add(p[i][j] + cnt, p[i + 1][j + 1], inf, 0);
			}
			add(p[i][j], p[i][j] + cnt, inf, -c[i][j]);
		}
	for(int i = 1; i <= m; i++)
		add(S, p[1][i], 1, 0);
	for(int i = 1; i <= n + m - 1; i++)
		add(p[n][i] + cnt, T, inf, 0);
	while(spfa()) update();
	cout << -mincost << '\n';
	return 0;
}