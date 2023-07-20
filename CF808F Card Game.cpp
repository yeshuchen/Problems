#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5, inf = 1e9;
int n, m, tot = 1;
int a[N];
int head[N];
struct Edge {
	int nxt, y, z;
} e[N];
int S, T, maxflow;
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
int dep[N], cur[N];
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
			int y = e[i].y, z = e[i].z;
			if(z && !dep[y])
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
		int y = e[i].y, z = e[i].z, d;
		if(z && dep[y] == dep[x] + 1 && (d = dfs(y, min(z, flow - res))))
		{
			res += d;
			e[i].z -= d;
			e[i ^ 1].z += d;
			if(res == flow) return res;
		}
	}
	return res;
}
int l[105], p[105], c[105];
inline bool check(int x)
{
	for(int i = 2; i * i <= x; i++)
		if(x % i == 0)
			return false;
	return true;
}
inline int solve(int level)
{
	tot = 1; maxflow = 0;
	memset(head, 0, sizeof(int) * (T + 1));
	for(int i = 1; i <= n; i++)
	{
		if(l[i] > level) continue;
		maxflow += p[i];
	}
	for(int i = 1; i <= n; i++)
	{
		if(!(c[i] & 1) || l[i] > level) continue;
		for(int j = 1; j <= n; j++)
		{
			if((c[j] & 1) || l[j] > level) continue;
			if(check(c[i] + c[j]))
				add(i, j, inf);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(l[i] > level) continue;
		if(c[i] & 1) add(S, i, p[i]);
		else add(i, T, p[i]);
	}
	while(bfs())
	{
		for(int i = 1; i <= T; i++) cur[i] = head[i];
		maxflow -= dfs(S, inf);
	}
	return maxflow;
}
signed main()
{
	bool flag = 0; int k, mx = 0;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k; S = n + 1; T = S + 1;
	for(int i = 1; i <= n; i++) cin >> p[i] >> c[i] >> l[i];
	for(int i = 1; i <= n; i++)
	{
		if(c[i] == 1)
		{
			mx = max(mx, p[i]);
			if(flag)
			{
				for(int j = i; j < n; j++)
					p[j] = p[j + 1], c[j] = c[j + 1], l[j] = l[j + 1];
				n--; i--;
			}
			else flag = 1;
		}
	}
	for(int i = 1; i <= n; i++)
		if(c[i] == 1) p[i] = mx;
	for(int i = 1; i <= n; i++)
		if(solve(i) >= k)
		{
			cout << i;
			return 0;
		}
	cout << -1;
	return 0;
}