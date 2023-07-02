#include<bits/stdc++.h>
using namespace std;
const int N = 200, inf = 1e9;
int n, m, k, tot, S, T;
int p[205][205];
struct Edge {
	int y, cap, flow;
} e[800005];
int nxt[800005], head[800005];
inline void add(int x, int y, int z)
{
	e[tot] = (Edge) {y, z, 0};
	nxt[tot] = head[x];
	head[x] = tot++;
	e[tot] = (Edge) {x, 0, 0};
	nxt[tot] = head[y];
	head[y] = tot++;
}
int dep[200005], cur[200005];
inline bool bfs()
{
	queue<int> q;
	memset(dep, 0, sizeof(dep));
	dep[S] = 1;
	q.push(S);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for(int i = head[x]; ~i; i = nxt[i])
		{
			int y = e[i].y;
			if(dep[y] || e[i].cap <= e[i].flow) continue;
			dep[y] = dep[x] + 1;
			q.push(y);
		}
	}
	return dep[T];
}
inline int dfs(int x, int flow)
{
	int res = 0;
	if(x == T || !flow) return flow;
	for(int i = cur[x]; ~i; i = nxt[i])
	{
		cur[x] = i;
		int y = e[i].y, d;
		if(dep[y] == dep[x] + 1 && (d = dfs(y, min(e[i].cap - e[i].flow, flow - res))))
		{
			res += d;
			e[i].flow += d;
			e[i ^ 1].flow -= d; 
		}
	}
	return res;
}
int ans;
int mx[8] = {-3, -3, -1, -1, 1, 1, 3, 3}, my[8] = {-1, 1, -3, 3, -3, 3, -1, 1};
int main()
{
	cin >> n >> m >> k;
	int sum = n * m;
	for(int i = 1; i <= k; i++)
	{
		int x, y;
		cin >> x >> y;
		if(!p[x][y]) sum--;
		p[x][y] = 1;
	}
	memset(head, -1, sizeof(head));
	for(int i = 1; i <= n; i += 2)
	{
		for(int j = 1; j <= m; j++)
		{
			if(p[i][j]) continue;
			for(int k = 0; k < 8; k++)
			{
				int dx = i + mx[k], dy = j + my[k];
				if(dx < 1 || dx > n || dy < 1 || dy > m || p[dx][dy]) continue;
				add((i - 1) * N + j, (dx - 1) * N + dy, 1);
			}
		}
	}
	S = N * N + 1, T = N * N + 2;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			if(i & 1) add(S, (i - 1) * N + j, 1);
			else add((i - 1) * N + j, T, 1);
		}
	while(bfs())
	{
		for(int i = 1; i <= T; i++) cur[i] = head[i];
		ans += dfs(S, inf);
	}
	cout << sum - ans;
	return 0;
}