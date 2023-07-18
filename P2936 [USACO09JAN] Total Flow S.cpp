#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, inf = 1e9;
int n, tot = 1;
int ver[N], nxt[N], head[N], limit[N];
inline void add(int x, int y, int z)
{
	ver[++tot] = y;
	limit[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
	ver[++tot] = x;
	nxt[tot] = head[y];
	head[y] = tot;
}
int S, T;
int dep[N];
inline bool bfs()
{
	for(int i = 1; i <= 1005; i++) dep[i] = 0;
	dep[S] = 1; queue<int> q;
	q.push(S);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for(int i = head[x]; i; i = nxt[i])
		{
			int y = ver[i];
			if(!dep[y] && limit[i])
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
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i], d;
		if(dep[y] == dep[x] + 1 && (d = dfs(y, min(flow - res, limit[i]))))
		{
			res += d;
			limit[i] -= d;
			limit[i ^ 1] += d;
			if(res == flow) return res;
		}
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		char x, y; int z;
		cin >> x >> y >> z;
		add(x - 'A' + 1, y - 'A' + 1, z);
	}
	S = 1; T = 26;
	int ans = 0;
	while(bfs()) ans += dfs(S, inf);
	cout << ans;
	return 0;
}