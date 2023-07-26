#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n, S, T, tot;
int c[N], f[N];
int ver[N], nxt[N], head[N];
inline int find(int k) {return f[k] == k ? k : f[k] = find(f[k]);}
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
double k;
int dp[N][2];
inline void dfs(int x, int fa)
{
	dp[x][0] = 0; dp[x][1] = c[x];
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y == fa) continue;
		dfs(y, x);
		dp[x][0] += max(dp[y][0], dp[y][1]);
		dp[x][1] += dp[y][0];
	}
}
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		x++; y++;
		if(find(x) == find(y))
		{
			S = x; T = y;
			continue;
		}
		add(x, y); add(y, x);
		f[find(x)] = find(y);
	}
	cin >> k;
	int ans = 0;
	dfs(S, 0); ans = dp[S][0];
	dfs(T, 0); ans = max(ans, dp[T][0]);
	printf("%.1lf", ans * k);
	return 0;
}