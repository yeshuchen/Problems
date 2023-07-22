#include<bits/stdc++.h>
using namespace std;
const int N = 3e6 + 5, inf = 1e9;
int n, m, S, T;
struct Edge {
	int nxt, y, z;
};
int tot = 1;
int head[N];
Edge e[N];
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
	memset(dep, 0, sizeof(int) * (2 * n + 1));
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
int a[10005], b[10005];
long long ans;
int main()
{
	while(cin >> n >> m)
	{
		for(int i = 1; i <= m; i++)
		{
			int x, y;
			scanf(" (%d,%d)", &a[i], &b[i]);
			a[i]++; b[i]++;
		}
		int ans = inf;
		for(S = 1; S <= n; S++)
			for(T = S + 1; T <= n; T++)
			{
				int res = 0;
				tot = 1;
				memset(head, 0, sizeof(int) * (2 * n + 1));
				for(int i = 1; i <= n; i++)
				{
					if(i == S || i == T) add(i, i + n, inf);
					else add(i, i + n, 1);
				}
				for(int i = 1; i <= m; i++)
				{
					add(a[i] + n, b[i], inf);
					add(b[i] + n, a[i], inf);
				}
				while(bfs())
				{
					for(int i = 1; i <= 2 * n; i++) cur[i] = head[i];
					res += dfs(S, inf);
				}
				ans = min(ans, res);
			}
		if(ans == inf || n <= 1) ans = n;
		cout << ans << '\n';
	}
	return 0;
}
