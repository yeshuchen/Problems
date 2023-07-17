#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, inf = 1e9;
int n, m, k, tot = 1;
int ph[105][105], num[105];
int h[N], r[N], f[N];
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
int dep[N], cur[N];
inline bool bfs()
{
	dep[T] = 0;
	for(int i = 1; i <= 100005; i++) dep[i] = 0;
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
inline int find(int k) {return f[k] == k ? k : f[k] = find(f[k]);}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= n + 3; i++) f[i] = i;
	for(int i = 1; i <= m; i++)
	{
		cin >> h[i] >> num[i];
		for(int j = 0; j < num[i]; j++)
		{
			int p;
			cin >> p;
			if(!p) p = n + 1;
			else if(p == -1) p = n + 2;
			ph[i][j] = p + 1;
		}
		for(int j = 0; j < num[i] - 1; j++)
		{
			int fx = find(ph[i][j]), fy = find(ph[i][j + 1]);
			if(fx == fy) continue;
			f[fx] = fy; 
		}
	}
	// for(int i = 1; i <= m; i++, cout << '\n')
	// 	for(int j = 1; j <= num[i]; j++)
	// 		cout << ph[i][j - 1] << ' ';
	S = 1; T = 5e5;
	if(find(n + 2) != find(n + 3)) {cout << 0; return 0;}
	int ans, mx = 0;
	add(S, n + 2, inf);
	for(ans = 1; ; ans++)
	{
		add(S, (ans - 1) * (n + 1) + n + 2, inf);
		
		for(int i = 1; i <= m; i++)
		{
			int x = (ans - 1) % num[i], y = ans % num[i];
			if(ph[i][x] == n + 3) x = T;
			else x = (ans - 1) * (n + 1) + ph[i][x];
			if(ph[i][y] == n + 3) y = T;
			else y = ans * (n + 1) + ph[i][y];
			add(x, y, h[i]);
		}
		while(bfs())
		{
			for(int i = 1; i <= ans * (n + 1) + n + 2; i++) cur[i] = head[i];
			mx += dfs(S, inf);
		}
		if(mx >= k) break;
		for(int i = 2; i <= n + 2; i++) add((ans - 1) * (n + 1) + i, ans * (n + 1) + i, inf);
	}
	cout << ans;
	return 0;
}