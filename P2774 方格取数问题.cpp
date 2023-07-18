#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 1e10;
struct Edge {
	int nxt, y, z;
} e[5000005];
int n, m, S, T, tot = 1;
int head[100005];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
inline void addedge(int x, int y, int z)
{
	e[++tot] = (Edge) {head[x], y, z};
	head[x] = tot;
}
inline void add(int x, int y, int z)
{
	addedge(x, y, z);
	addedge(y, x, 0);
}
int dep[100005], cur[100005]; 
inline bool bfs()
{
	queue<int> q;
	memset(dep, 0, sizeof(int) * (T + 1));
	dep[S] = 1; q.push(S);
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
inline int dfs(int x, int flow)
{
	int res = 0;
	if(x == T || !flow) return flow;
	for(int i = cur[x]; i; i = e[i].nxt)
	{
		cur[x] = i;
		int y = e[i].y, d;
		if(dep[y] == dep[x] + 1 && (d = dfs(y, min(e[i].z, flow - res))))
		{
			res += d;
			e[i].z -= d;
			e[i ^ 1].z += d;
			if(res == flow) return res;
		}
	}
	return res;
}
int sum;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	S = n * m + 1; T = S + 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			int x;
			cin >> x; sum += x;
			if((i + j) % 2 == 0) add(S, (i - 1) * m + j, x);
			else add((i - 1) * m + j, T, x);
		}
	for(int x = 1; x <= n; x++)
		for(int y = 1; y <= m; y++)
		{
			if(x + y & 1) continue;
			for(int c = 0; c < 4; c++)
			{
				int nx = x + dx[c], ny = y + dy[c];
				if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
				add((x - 1) * m + y, (nx - 1) * m + ny, inf);
			}
		}
	int maxflow = 0;
	while(bfs())
	{
		for(int i = 1; i <= T; i++) cur[i] = head[i];
		maxflow += dfs(S, inf);
	}
	cout << sum - maxflow;
	return 0;
}