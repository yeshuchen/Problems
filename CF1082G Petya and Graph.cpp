#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5, inf = 1e9;
int n, m, tot = 1;
int a[N];
int head[N];
struct Edge {
	int nxt, y, z;
} e[N];
int S, T, maxflow;
inline void addedge(int x, int y, int z)
{
	e[++tot] = (Edge) {head[x], y, z};
	head[x] = tot;
}
inline void add(int x, int y, int z)
{
	addedge(x, y, z);
	addedge(y, x, 0);
}
int dep[N], cur[N];
inline bool bfs()
{
	queue<int> q;
	memset(dep, 0, sizeof(int) * (T + 1));
	dep[S] = 1; q.push(S);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for(int i = head[x]; i; i = e[i].nxt)
		{
			int y = e[i].y, z = e[i].z;
			if(z && !dep[y])
			{
				dep[y] = dep[x] + 1;
				q.push(y);
			}
		}
	}
	return dep[T];
}
inline int dfs(int x, int flow)
{
	int res = 0;
	if(x == T || !flow) return flow;
	for(int i = cur[x]; i; i = e[i].nxt)
	{
		cur[x] = i;
		int y = e[i].y, z = e[i].z, d;
		if(z && dep[y] == dep[x] + 1 && (d = dfs(y, min(z, flow - res))))
		{
			res += d;
			e[i].z -= d;
			e[i ^ 1].z += d;
			if(res == flow) return res;
		}
	}
	return res;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m; S = n + m + 1; T = S + 1;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		add(i + m, T, x);
	}
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		maxflow += z;
		add(S, i, z);
		add(i, x + m, inf);
		add(i, y + m, inf);
	}
	while(bfs())
	{
		for(int i = 1; i <= T; i++) cur[i] = head[i];
		maxflow -= dfs(S, inf);
	}
	cout << maxflow;
	return 0;
}