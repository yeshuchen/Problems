#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5, inf = 2e9;
int p, q, r, d, tot = 1;
int v[45][45][45];
int ver[N], nxt[N], head[N], limit[N];
inline int h(int x, int y, int z) {return (z - 1) * p * q + (x - 1) * q + y;}
inline void add(int x, int y, int z)
{
	ver[++tot] = y;
	limit[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
}
inline void addedge(int x, int y, int z)
{
	add(x, y, z);
	add(y, x, 0);
}
int S, T;
int cur[N], dep[N];
inline bool bfs()
{
	queue<int> q;
	memset(dep, 0, sizeof(dep));
	q.push(S); dep[S] = 1;
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
	if(!flow || x == T) return flow;
	int res = 0;
	for(int i = cur[x]; i; i = nxt[i])
	{
		cur[x] = i;
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
	cin >> p >> q >> r >> d;
	for(int i = 1; i <= r; i++)
		for(int j = 1; j <= p; j++)
			for(int k = 1; k <= q; k++)
				cin >> v[j][k][i];
	S = p * q * (r + 1) + 1; T = S + 1;
	for(int i = 1; i <= p; i++)
		for(int j = 1; j <= q; j++)
		{
			addedge(S, h(i, j, 1), inf);
			addedge(h(i, j, r + 1), T, inf);
			for(int k = 1; k <= r; k++)
			{
				addedge(h(i, j, k), h(i, j, k + 1), v[i][j][k]);
				if(k > d)
				{
					if(i > 1) addedge(h(i, j, k), h(i - 1, j, k - d), inf);
					if(i < p) addedge(h(i, j, k), h(i + 1, j, k - d), inf);
					if(j > 1) addedge(h(i, j, k), h(i, j - 1, k - d), inf);
					if(j < q) addedge(h(i, j, k), h(i, j + 1, k - d), inf);
				}
			}
		}
	int res = 0;
	while(bfs())
	{
		for(int i = 1; i <= T; i++) cur[i] = head[i];
		res += dfs(S, inf);
	}
	cout << res;
	return 0;
}