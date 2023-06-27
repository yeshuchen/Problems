#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e4 + 4, INF = 1e14;
struct Edge {
	int nxt, y, cap, flow;
} e[N];
int n, m, S, T, tot;
int head[N];
inline void add(int x, int y, int z)
{
	e[tot] = (Edge){head[x], y, z, 0};
	head[x] = tot++;
	e[tot] = (Edge){head[y], x, 0, 0};
	head[y] = tot++;
}
int maxflow;
int cur[N], dep[N];
bool bfs()
{
	queue<int> q;
	memset(dep, 0, sizeof(dep));
	dep[S] = 1; q.push(S);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for(int i = head[x]; ~i; i = e[i].nxt)
		{
			int y = e[i].y;
			if(!dep[y] && e[i].cap > e[i].flow)
			{
				dep[y] = dep[x] + 1;
				q.push(y);
			}
		}
	}
	return dep[T];
}
int dfs(int x, int flow)
{
	if(x == T || (!flow)) return flow;
	int res = 0;
	for(int i = cur[x]; ~i; i = e[i].nxt)
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
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	memset(head, -1, sizeof(head));
	cin >> n >> m >> S >> T;
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}
	while(bfs())
	{
		for(int i = 1; i <= n; i++) cur[i] = head[i];
		maxflow += dfs(S, INF);
	}
	cout << maxflow;
	return 0;
}