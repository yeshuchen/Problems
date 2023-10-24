#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, inf = 2e9;
int n, m;
int tot = 1;
int w[N], cur[N];
struct Edge {
	int y, z, nxt;
} e[N];
int head[N];
void add(int x, int y, int z)
{
	e[++tot] = {y, z, head[x]};
	head[x] = tot;
}
void addedge(int x, int y, int z)
{
	add(x, y, z);
	add(y, x, 0);
}
int S, T;
int dep[N], current[N];
bool bfs()
{
	memset(dep, 0, (T + 1) * sizeof(int));
	dep[S] = 1; queue<int> q;
	q.push(S);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for(int i = head[x]; i; i = e[i].nxt)
		{
			int y = e[i].y;
			if(e[i].z && !dep[y])
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
	int res = 0;
	if(x == T || !flow) return flow;
	for(int i = cur[x]; i; i = e[i].nxt)
	{
		cur[x] = i;
		int y = e[i].y, v;
		if(dep[y] == dep[x] + 1 && (v = dfs(y, min(flow - res, e[i].z))))
		{
			res += v;
			e[i].z -= v;
			e[i ^ 1].z += v;
			if(res == flow) return res;
		}
	}
	return res;
}
int SS, TT;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> SS >> TT;
	for(int i = 1; i <= m; i++)
	{
		int u, v, up;
		cin >> u >> v >> current[i] >> up;
		addedge(u, v, up - current[i]);
		w[u] -= current[i]; w[v] += current[i];
	}
	int ans = 0;
	S = n + 1; T = S + 1;
	for(int i = 1; i <= n; i++)
	{
		if(w[i] < 0) addedge(i, T, -w[i]);
		if(w[i] > 0) addedge(S, i, w[i]), ans += w[i];
	}
	addedge(TT, SS, inf);
	while(bfs())
	{
		memcpy(cur + 1, head + 1, T * sizeof(int));
		ans -= dfs(S, inf);
	}
	if(ans) {cout << "please go home to sleep"; return 0;}
	S = SS; T = TT; ans = e[head[S]].z;
	head[S] = e[head[S]].nxt; head[T] = e[head[T]].nxt;
	while(bfs())
	{
		memcpy(cur + 1, head + 1, T * sizeof(int));
		ans += dfs(S, inf);
	}
	cout << ans;
	return 0;
}