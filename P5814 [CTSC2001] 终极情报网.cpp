#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-12;
const int N = 2e5 + 5, inf = 1e9;
int n, k;
int am[1005];
double as[1005];
struct Edge {
	int nxt, y, z;
	double w;
};
struct Graph {
	int tot = 1, head[605];
	Edge p[N];
	inline void addedge(int x, int y, int z, double w) {
		p[++tot] = (Edge) {head[x], y, z, w};
		head[x] = tot;
	}
	inline void add(int x, int y, int z, double w) {
		addedge(x, y, z, w);
		addedge(y, x, 0, 1.0 / w);
	}
} e;
int S, T, SS;
double dis[N];
int vis[N], pre[N], flow[N];
inline bool spfa()
{
	for(int i = 1; i <= SS; i++) dis[i] = -1e9;
	queue<int> q; dis[S] = 1;
	q.push(S); flow[S] = inf; flow[T] = 0;
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		vis[x] = 0;
		for(int i = e.head[x]; i; i = e.p[i].nxt)
		{
			int y = e.p[i].y, z = e.p[i].z;
			double cost = e.p[i].w;
			if(!z || dis[x] * cost - dis[y] < eps) continue;
			dis[y] = dis[x] * cost;
			pre[y] = i; flow[y] = min(z, flow[x]);
			if(!vis[y]) q.push(y), vis[y] = 1;
		}
	}
	return flow[T];
}
int maxflow;
double mincost = 1;
inline void update()
{
	maxflow += flow[T];
	double cost = 1;
	for(int x = T; x != S; x = e.p[pre[x] ^ 1].y)
	{
		cost = cost * e.p[pre[x]].w;
		e.p[pre[x]].z -= flow[T]; e.p[pre[x] ^ 1].z += flow[T];
	}
	for(int i = 1; i <= flow[T]; i++) mincost *= cost;
}
double sft[310];
char str[310];
inline void print()
{
	sprintf(str, "%.10lf", mincost);
	int len = 0, sml = -1;
	for(len = 0; sml < 4; len++)
		if(str[len] > '0' && str[len] <= '9' || sml != -1)
			sml++;
	if(str[len]>='5') str[len-1]++; str[len] = '\0';
	while(str[len-1] != '.' && str[len-1] > '9')
		str[len-1] = '0', str[len-2]++, len--;
	printf("%s\n", str);
}
int main() {
	cin >> n >> k; S = 2 * n + 1; T = S + 1; SS = T + 1;
	e.add(S, SS, k, 1);
	for(int i = 1; i <= n; i++) cin >> as[i];
	for(int i = 1; i <= n; i++) cin >> am[i];
	for(int i = 1; i <= n; i++)
	{
		bool f;
		cin >> f;
		if(as[i] > eps && am[i]) e.add(SS, i, am[i], as[i]);
		if(f) e.add(i, T, inf, 1.0);
	}
	int x, y;
	while(cin >> x >> y)
	{
		double s; int m;
		if(x == -1 && y == -1) break;
		cin >> s >> m;
		if(s > eps)
		{
			e.add(x, y, m, s);
			e.add(y, x, m, s);
		}
	}
	while(spfa()) update();
	if(maxflow != k) mincost = 0;
	if(mincost < eps) cout << 0;
	else print();
	return 0;
}