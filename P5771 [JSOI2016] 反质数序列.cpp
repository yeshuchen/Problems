#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int n, S, T;
int a[300005];
int tot = 1;
int limit[9000005], ver[9000005], nxt[9000005], head[3005];
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
int dep[3005], cur[3005];
inline bool bfs()
{
	memset(dep, 0, sizeof(dep));
	queue<int> q;
	q.push(S);
	dep[S] = 1;
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
int cnt;
int vis[200005], prime[200005];
inline void lineshai()
{
	for(int i = 2; i <= 200000; i++)
	{
		if(!vis[i]) prime[++cnt] = i;
		for(int j = 1; j <= cnt && i * prime[j] <= 200000; j++)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	bool flag = 0;
	lineshai();
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] == 1)
		{
			if(flag) i--, n--;
			else flag = 1;
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
		{
			if(a[i] % 2 == 0 || a[j] % 2 == 1) continue;
			if(!vis[a[i] + a[j]])
				add(i, j, 1);
		}
	S = n + 1, T = n + 2;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] & 1) add(S, i, 1);
		else add(i, T, 1);
	}
	int flow = 0;
	while(bfs())
	{
		for(int i = 1; i <= T; i++) cur[i] = head[i];
		flow += dfs(S, inf);
	}
	cout << n - flow;
	return 0;
}