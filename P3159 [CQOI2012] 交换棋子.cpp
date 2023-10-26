#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5, inf = 2e9;
int n, m, tot = 1;
struct edge {
	int y, z, w, nxt;
} e[N];
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1}, dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int S, T;
int head[N];
void add(int x, int y, int z, int w)
{
	e[++tot] = {y, z, w, head[x]};
	head[x] = tot;
}
void addedge(int x, int y, int z, int w)
{
	// cout << x << '-' << y << '\n';
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
int ans, maxflow;
char c1[25][25], c2[25][25];
void update()
{
	maxflow += flow[T];
	for(int i = T; i != S; i = e[pre[i] ^ 1].y)
	{
		e[pre[i]].z -= flow[T];
		e[pre[i] ^ 1].z += flow[T];
		ans += flow[T] * e[pre[i]].w;
	}
}
int get(int x, int y, int id) {return (x - 1) * m + y + id * n * m;}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	S = 2 * n * m + 1;
	T = S + 1;
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> c1[i][j], cnt += (c1[i][j] == '1');
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> c2[i][j], cnt -= (c2[i][j] == '1');
	if(cnt) {cout << -1; return 0;}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(c1[i][j] != c2[i][j])
			{
				if(c1[i][j] == '1') addedge(S, get(i, j, 0), 1, 0);
				else addedge(get(i, j, 1), T, 1, 0);
			}
			char ch;
			cin >> ch;
			int x = ch - '0';
			addedge(get(i, j, 0), get(i, j, 1), x / 2 + (c1[i][j] == '1' ^ c2[i][j] == '1'), 0);
			for(int k = 0; k < 8; k++)
			{
				int nx = i + dx[k], ny = j + dy[k];
				if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
				addedge(get(i, j, 1), get(nx, ny, 0), inf, 1);
			}
		}
	}
	while(SPFA()) update();
	// if(maxflow != res) {cout << -1; return 0;}
	// cout << maxflow << '\n';
	cout << ans;
	return 0;
}