#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int n, m, S, T;
int nd[1000005];
struct Edge {
	int y, cap, flow;
} e[1000005];
int tot = 1;
int nxt[1000005], head[1000005];
inline void add(int x, int y, int z)
{
	e[++tot] = (Edge) {y, z, 0};
	nxt[tot] = head[x];
	head[x] = tot;
	e[++tot] = (Edge) {x, 0, 0};
	nxt[tot] = head[y];
	head[y] = tot;
}
int dep[1000005], cur[1000005];
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
	for(int i = 1; i <= n; i++)
		cin >> nd[i], sum += nd[i];
	for(int i = 1; i <= m; i++)
	{
		int k, p;
		cin >> k;
		for(int j = 1; j <= k; j++)
			cin >> p, add(i, p + m, 1);
	}
	S = n + m + 1, T = n + m + 2;
	for(int i = 1; i <= m; i++)
		add(S, i, 1);
	for(int i = 1; i <= n; i++)
		add(i + m, T, nd[i]);
	while(bfs())
	{
		for(int i = 1; i <= T; i++) cur[i] = head[i];
		ans += dfs(S, inf);
	}
	if(ans < sum) cout << "No Solution!";
	else
	{
		for(int i = 1; i <= n; i++)
		{
			cout << i << ": ";
			for(int j = head[i + m]; j; j = nxt[j])
				if(e[j].cap - e[j].flow > 0)
					cout << e[j].y << ' ';
			cout << '\n';
		}
	}
	return 0;
}