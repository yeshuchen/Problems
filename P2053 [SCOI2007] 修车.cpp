#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, inf = 2e9;
int n, m, tot = 1;
int t[505][505];
struct edge {
	int y, z, w, nxt;
} e[N];
int S, T;
int head[N];
void add(int x, int y, int z, int w)
{
	e[++tot] = {y, z, w, head[x]};
	head[x] = tot;
}
void addedge(int x, int y, int z, int w)
{
	add(x, y, z, w);
	add(y, x, 0, -w);
}
int dis[N], vis[N], pre[N], flow[N];
bool SPFA()
{
	memset(vis, 0, (T + 1) * sizeof(int));
	memset(dis, 0x3f, (T + 1) * sizeof(int));
	flow[S] = inf; flow[T] = 0; queue<int> q;
	q.push(S); dis[S] = 0;
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		vis[x] = 0;
		for(int i = head[x]; i; i = e[i].nxt)
		{
			int y = e[i].y, w = e[i].w;
			if(e[i].z && dis[y] > dis[x] + w)
			{
				flow[y] = min(flow[x], e[i].z);
				dis[y] = dis[x] + w; pre[y] = i;
				if(!vis[y]) vis[y] = 1, q.push(y);
			}
		}
	}
	return flow[T];
}
int ans;
void update()
{
	for(int i = T; i != S; i = e[pre[i] ^ 1].y)
	{
		e[pre[i]].z -= flow[T];
		e[pre[i] ^ 1].z += flow[T];
		ans += flow[T] * e[pre[i]].w;
	}
}
int main()
{
	cin >> m >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> t[i][j];
	S = (m + 1) * n + 1; T = S + 1;
	for(int i = 1; i <= n; i++)
		addedge(i, T, 1, 0);
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
		{
			addedge(S, i * n + j, 1, 0);
			for(int k = 1; k <= n; k++)
				addedge(i * n + j, k, 1, j * t[k][i]);
		}
	while(SPFA()) update();
	cout << fixed << setprecision(2) << 1.0 * ans / n;
	return 0;
}