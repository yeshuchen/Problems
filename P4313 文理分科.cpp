#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9, N = 3e5 + 5;
int n, m, id, S, T, tot = 1;
int a[105][105];
int s[105][105];
int ss[105][105], sa[105][105];
inline int f(int x, int y) {return (x - 1) * m + y;}
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	S = 4 * n * m + 1; T = S + 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			cin >> a[i][j]; ans += a[i][j];
			add(S, f(i, j), a[i][j]);
		}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			cin >> s[i][j]; ans += s[i][j];
			add(f(i, j), T, s[i][j]);
		}
	id = n * m; 
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			cin >> sa[i][j]; ans += sa[i][j];
			add(S, ++id, sa[i][j]);
			add(id, f(i, j), inf);
			if(i > 1) add(id, f(i - 1, j), inf);
			if(i < n) add(id, f(i + 1, j), inf);
			if(j > 1) add(id, f(i, j - 1), inf);
			if(j < m) add(id, f(i, j + 1), inf);
		}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			cin >> ss[i][j]; ans += ss[i][j];
			add(++id, T, ss[i][j]);
			add(f(i, j), id, inf);
			if(i > 1) add(f(i - 1, j), id, inf);
			if(i < n) add(f(i + 1, j), id, inf);
			if(j > 1) add(f(i, j - 1), id, inf);
			if(j < m) add(f(i, j + 1), id, inf);
		}
	while(bfs())
	{
		for(int i = 1; i <= T; i++) cur[i] = head[i];
		ans -= dfs(S, inf);
	}
	cout << ans;
	return 0;
}