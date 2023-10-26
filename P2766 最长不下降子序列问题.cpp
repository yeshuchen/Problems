#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, inf = 2e9;
int S, T;
int n, ans, tot = 1;
int a[N], dp[N];
int ver[N], nxt[N], head[N], limit[N];
int dep[N], cur[N];
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
bool bfs()
{
	memset(dep, 0, (T + 1) * sizeof(int));
	queue<int> q; q.push(S);
	dep[S] = 1;
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
	for(int i = head[x]; i; i = nxt[i])
	{
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
	cin >> n;
	if(n == 1)
	{
		cout << 1 << '\n' << 1 << '\n' << 1;
		return 0;
	}
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for(int j = 1; j < i; j++)
			if(a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + 1);
		ans = max(ans, dp[i]);
	}
	S = 2 * n + 1; T = S + 1;
	int res = ans;
	cout << ans << '\n';
	for(int i = 1; i <= n; i++)
	{
		if(dp[i] == 1) addedge(S, i, 1);
		if(dp[i] == ans) addedge(i + n, T, 1);
		addedge(i, i + n, 1);
		for(int j = i + 1; j <= n; j++)
			if(a[i] <= a[j] && dp[i] + 1 == dp[j])
				addedge(i + n, j, 1);
	}
	ans = 0;
	while(bfs())
	{
		memcpy(cur + 1, head + 1, T * sizeof(int));
		ans += dfs(S, inf);
	}
	cout << ans << '\n';
	if(dp[1] == 1 && dp[n] == res)
	{
		addedge(S, 1, inf);
		addedge(1, 1 + n, inf);
		addedge(n, n + n, inf);
		addedge(n + n, T, inf);
	}
	while(bfs())
	{
		memcpy(cur + 1, head + 1, T * sizeof(int));
		ans += dfs(S, inf);
	}
	cout << ans << '\n';
	return 0;
}