#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, INF = 1e9;
int n, p, q;
struct Edge {
	int y, cap, flow;
} e[N];
int S, T;
int tot, nxt[N], head[N];
inline void add(int x, int y, int z)
{
	e[tot] = (Edge){y, z, 0};
	nxt[tot] = head[x];
	head[x] = tot++;
	e[tot] = (Edge){x, 0, 0};
	nxt[tot] = head[y];
	head[y] = tot++;
}
int dep[N], cur[N];
inline bool bfs()
{
	queue<int> q; 
	memset(dep, 0, sizeof(dep));
	dep[S] = 1; q.push(S);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for(int i = head[x]; ~i; i = nxt[i])
		{
			int y = e[i].y;
			if(!dep[y] && (e[i].cap > e[i].flow))
				dep[y] = dep[x] + 1, q.push(y);
		}
	}
	return dep[T];
}
inline int dfs(int x, int flow)
{
	if(x == T || (!flow)) return flow;
	int res = 0;
	for(int i = cur[x]; ~i; i = nxt[i])
	{
		cur[x] = i;
		int y = e[i].y, d;
		if(dep[y] == dep[x] + 1 && (d = dfs(y, min(flow - res, e[i].cap - e[i].flow))))
		{
			res += d;
			e[i].flow += d;
			e[i ^ 1].flow -= d;
			if(res == flow) return res;
		}
	}
	return res;
}
int maxflow;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> p >> q;
	memset(head, -1, sizeof(head));
	for(int i = 1; i <= n; i++)
	{
		int fi, di;
		cin >> fi >> di;
		for(int j = 1; j <= fi; j++)
		{
			int u; cin >> u;
			add(2 * n + u, i, 1);
		}
		for(int j = 1; j <= di; j++)
		{
			int u; cin >> u;
			add(i + n, 2 * n + p + u, 1);
		}
	}
	S = 2 * n + p + q + 1; T = 2 * n + p + q + 2;
	for(int i = 1; i <= n; i++)
		add(i, i + n, 1);
	for(int i = 1; i <= p; i++)
		add(S, 2 * n + i, 1);
	for(int i = 1; i <= q; i++)
		add(2 * n + p + i, T, 1);
	while(bfs())
	{
		for(int i = 1; i <= T; i++) cur[i] = head[i];
		maxflow += dfs(S, INF);
	}
	cout << maxflow;
	return 0;
}