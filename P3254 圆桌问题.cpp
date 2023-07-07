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
	memset(dep, 0, sizeof(int) * (T + 1));
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
	cin >> n >> m;
	S = n + m + 1, T = n + m + 2;
	for(int i = 1; i <= n; i++)
		cin >> a[i], sum += a[i];
	for(int i = 1; i <= m; i++)
		cin >> b[i];
	for(int i = 1; i <= n; i++)
		add(S, i, a[i]);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			add(i, n + j, 1);
	for(int i = 1; i <= m; i++)
		add(n + i, T, b[i]);
	while(bfs())
	{
		for(int i = 1; i <= T; i++) cur[i] = head[i];
		ans += dfs(S, inf);
	}
	if(ans < sum) cout << 0;
	else
	{
		cout << 1 << '\n';
		for(int i = 1; i <= n; i++)
		{
			for(int j = head[i]; j; j = nxt[j])
				if(e[j].cap - e[j].flow == 0)
					cout << e[j].y - n << ' ';
			cout << '\n';
		}
	}
	return 0;
}