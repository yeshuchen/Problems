#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, inf = 1e9;
int n, m, S, T, tot = 1;
map<string, int> p;
struct Edge {
	int nxt, y, z, w;
} e[N];
int head[N];
inline void addedge(int x, int y, int z, int w) {
	e[++tot] = (Edge) {head[x], y, z, w};
	head[x] = tot;
}
inline void add(int x, int y, int z, int w) {
	addedge(x, y, z, w);
	addedge(y, x, 0, -w);
}
bool vis[N];
int dis[N], pre[N], flow[N];
inline bool spfa()
{
	memset(dis, 0x3f, sizeof(int) * (T + 1));
	queue<int> q; dis[S] = 0;
	q.push(S); flow[S] = inf; flow[T] = 0;
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		vis[x] = 0;
		for(int i = head[x]; i; i = e[i].nxt)
		{
			int y = e[i].y, z = e[i].z, cost = e[i].w;
			if(!z || dis[y] <= dis[x] + cost) continue;
			dis[y] = dis[x] + cost;
			pre[y] = i; flow[y] = min(z, flow[x]);
			if(!vis[y]) q.push(y), vis[y] = 1;
		}
	}
	return flow[T];
}
int mincost, maxflow;
inline void update()
{
	maxflow += flow[T];
	for(int x = T; x != S; x = e[pre[x] ^ 1].y)
	{
		mincost += flow[T] * e[pre[x]].w;
		e[pre[x]].z -= flow[T]; e[pre[x] ^ 1].z += flow[T];
	}
}
string f[505];
inline void dfs1(int x)
{
	if(x <= n) cout << f[x] << '\n';
	if(x == n) return;
	for(int i = head[x]; i; i = e[i].nxt)
	{
		if(e[i ^ 1].z)
		{
			e[i ^ 1].z--;
			dfs1(e[i].y);
			break;
		}
	}
}
inline void dfs2(int x)
{
	if(x < n) cout << f[x] << '\n';
	for(int i = head[x]; i; i = e[i].nxt)
	{
		if(e[i].z)
		{
			e[i].z--;
			dfs2(e[i].y);
			break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		p[s] = i;
		f[i] = s;
	}
	for(int i = 1; i <= m; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int x = p[s1], y = p[s2];
		if(x > y) swap(x, y);
		add(x + n, y, inf, 0);
	}
	S = 1; T = 2 * n;
	for(int i = 1; i <= n; i++)
		add(i, i + n, 1 + (i == 1 || i == n), -1);
	while(spfa()) update();
	if(!mincost) {cout << "No Solution!"; return 0;}
	cout << -mincost - 2 << '\n';
	dfs1(1); dfs2(2 * n);
	return 0;
}