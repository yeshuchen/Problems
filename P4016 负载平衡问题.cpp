#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, inf = 1e9;
int n, sum, S, T;
int tot = 1, a[10005];
struct Edge {
	int nxt, y, z, w;
} e[N];
int head[1005];
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
int dis[N], flow[N];
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], sum += a[i];
	sum /= n;
	for(int i = 1; i <= n; i++)
		a[i] -= sum;
	S = 2 * n + 1; T = 2 * S + 1;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] > 0) add(S, i, a[i], 0);
		if(a[i] < 0) add(i, T, -a[i], 0);
		if(i > 1) add(i, i - 1, inf, 1);
		if(i < n) add(i, i + 1, inf, 1);
	}
	add(1, n, inf, 1); add(n, 1, inf, 1);
	while(spfa()) update();
 	cout << mincost;
	return 0;
}