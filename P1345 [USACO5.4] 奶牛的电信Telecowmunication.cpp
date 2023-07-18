#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, inf = 1e9;
int n, m, S, T;
int a[N], b[N], nd[N];
struct Edge {
	int y, cap, flow;
} e[N];
int tot = 1;
int nxt[N], head[N];
inline void add(int x, int y, int z)
{
	e[++tot] = (Edge) {y, z, 0};
	nxt[tot] = head[x];
	head[x] = tot;
	e[++tot] = (Edge) {x, 0, 0};
	nxt[tot] = head[y];
	head[y] = tot;
}
int dep[N], cur[N];
inline bool bfs()
{
	memset(dep, 0, sizeof(int) * (2 * n+ 1));
	dep[S] = 1; queue<int> q;
	q.push(S);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for(int i = head[x]; i; i = nxt[i])
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
inline int dfs(int x, int flow)
{
	if(x == T || !flow) return flow;
	int res = 0;
	for(int i = cur[x]; i; i = nxt[i])
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
int ans, sum;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> S >> T;
	S = S + n;
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x + n, y, inf);
		add(y + n, x, inf);
	}
	for(int i = 1; i <= n; i++)
		add(i, i + n, 1);
	while(bfs())
	{
		for(int i = 1; i <= 2 * n; i++) cur[i] = head[i];
		ans += dfs(S, inf);
	}
	cout << ans;
	return 0;
}