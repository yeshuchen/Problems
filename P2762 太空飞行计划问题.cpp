#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9, N = 1e5 + 5;
int n, m, S, T;
int tot = 1, nxt[N], head[N];
struct Edge {
	int y, cap, flow;
} e[N];
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
	queue<int> q;
	q.push(S);
	dep[S] = 1;
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
int ans, flow;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	S = n + m + 1; T = n + m + 2;
	for(int i = 1; i <= n; i++)
	{
		int cost;
		cin >> cost;
		add(S, i, cost);
		ans += cost;
		string s;
    	getline(cin, s);
    	for(int j = 0; j < s.size(); j++)
		{
    	 	if(!isdigit(s[j])) continue;
    	  	int x = 0;
    	  	while(j < s.size() && isdigit(s[j])) x = x * 10 + s[j++] - '0';
    	  	add(i, x + n, inf);
    	}
	}
	for(int i = 1; i <= m; i++)
	{
		int cost;
		cin >> cost;
		add(i + n, T, cost);
	}
	while(bfs())
	{
		for(int i = 1; i <= T; i++) cur[i] = head[i];
		flow += dfs(S, inf);
	}
	for(int i = 1; i <= n; i++)
		if(dep[i])
			cout << i << ' ';
	cout << '\n';
	for(int i = 1; i <= m; i++)
		if(dep[i + n])
			cout << i << ' ';
	cout << '\n' << ans - flow;
	return 0;
}