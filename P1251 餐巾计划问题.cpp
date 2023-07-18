#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5, inf = 1e9;
int tot = 1;
struct Edge {
	int nxt, y, z, w;
} e[N];
int S, T;
int n, p, d1, c1, d2, c2;
int r[100005];
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
	memset(dis, 0x3f, sizeof(int) * (T + 1));
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
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	S = 2 * n + 1; T = S + 1;
	for(int i = 1; i <= n; i++)
		cin >> r[i];
	cin >> p >> d1 >> c1 >> d2 >> c2;
	for(int i = 1; i <= n; i++)
	{
		add(S, i, r[i], 0);
		add(S, i + n, inf, p);
		add(i + n, T, r[i], 0);
		if(i < n) add(i, i + 1, inf, 0);
		if(i <= n - d1) add(i, n + i + d1, inf, c1);
		if(i <= n - d2) add(i, n + i + d2, inf, c2);
	}
	while(spfa()) update();
	cout << mincost;
	return 0;	
}