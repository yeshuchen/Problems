#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e6 + 5, inf = 1e9;
int n, m, S, T, tot = 1;
int head[N];
struct Edge {
	int nxt, y, z;
} e[N];
inline void add(int x, int y, int z)
{
	e[++tot] = (Edge) {head[x], y, z};
	head[x] = tot;
	e[++tot] = (Edge) {head[y], x, 0};
	head[y] = tot;
}
int dep[N], cur[N];
inline bool bfs()
{
	memset(dep, 0, sizeof(int) * (T + 1));
	queue<int> q;
	q.push(S); dep[S] = 1;
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
		if(dep[y] == dep[x] + 1 && (d = dfs(y, min(flow - res, e[i].z))))
		{
			res += d;
			e[i].z -= d;
			e[i ^ 1].z += d;
			if(res == flow) return res;
		}
	}
	return res;
}
long long ans;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m; int res = n;
	S = 3001; T = S + 1;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		add(S, i, x), add(i, T, x ^ 1);
	}
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y, 1);
		add(y, x, 1);
	}
	while(bfs())
	{
		for(int i = 1; i <= T; i++) cur[i] = head[i];
		ans += dfs(S, inf);
	}
	cout << ans;
	return 0;
}