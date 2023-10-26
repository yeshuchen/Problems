#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5, inf = 2e9;
int n, m, tot = 1, S, T;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ver[N], nxt[N], head[N], limit[N];
int get_id(int x, int y) {return (x - 1) * m + y;}
void add(int x, int y, int z)
{
	ver[++tot] = y;
	limit[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
}
void addedge(int x, int y, int z)
{
	add(x, y, z);
	add(y, x, 0);
}
int dep[N], cur[N];
bool bfs()
{
	queue<int> q;
	memset(dep, 0, (T + 1) * sizeof(int));
	q.push(S); dep[S] = 1;
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for(int i = head[x]; i; i = nxt[i])
		{
			int y = ver[i];
			if(limit[i] && !dep[y])
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
	if(x == T || !flow) return flow;
	int res = 0;
	for(int i = cur[x]; i; i = nxt[i])
	{
		cur[x] = i;
		int y = ver[i], v;
		if(dep[y] == dep[x] + 1 && (v = dfs(y, min(flow - res, limit[i]))))
		{
			res += v;
			limit[i] -= v;
			limit[i ^ 1] += v;
			if(res == flow) return res;
		}
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	S = n * m + 1; T = S + 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			int x;
			cin >> x;
			if(x == 1) addedge(S, get_id(i, j), inf);
			if(x == 2) addedge(get_id(i, j), T, inf);
			for(int k = 0; k < 4; k++)
			{
				int nx = i + dx[k], ny = j + dy[k];
				if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
				addedge(get_id(i, j), get_id(nx, ny), 1);
			}
		}
	int ans = 0;
	while(bfs())
	{
		memcpy(cur + 1, head + 1, T * sizeof(int));
		ans += dfs(S, inf);
	}
	cout << ans;
	return 0;
}