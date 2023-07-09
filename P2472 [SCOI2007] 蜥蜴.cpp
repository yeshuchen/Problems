#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9, N = 2e5 + 5;
int n, m, d, S, T, tot = 1;
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
int dep[N], cur[N];
inline bool bfs()
{
	memset(dep, 0, sizeof(int) * (T + 1));
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
int ans;
char c[25][25];
inline double dis(int x1, int y1, int x2, int y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> d;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			cin >> c[i][j];
			int h = c[i][j] - '0';
			add((i - 1) * m + j, (n + i - 1) * m + j, h);
		}
	S = 2 * n * m + 1; T = 2 * n * m + 2;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			char ch;
			cin >> ch;
			if(ch == 'L')
			{
				ans++;
				add(S, (i - 1) * m + j, 1); 
			}
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= m; k++)
				if(abs(j - i) + min(k, m - k + 1) <= d && c[j][k] != '0')	
				{
					// cout << '(' << j << ',' << k << ')' << '\n';
					add((n + j - 1) * m + k, T, inf);
				}
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= m; k++)
				if(abs(k - i) + min(j, n - j + 1) <= d && c[j][k] != '0')
				{
					// cout << '(' << j << ',' << k << ')' << '\n';
					add((n + j - 1) * m + k, T, inf);
				}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			for(int k = 1; k <= n; k++)
				for(int l = 1; l <= m; l++)
					if(dis(i, j, k, l) <= d && c[i][j] != '0' && c[k][l] != '0' && (i != k || j != l))
					{
						// cout << '(' << i << ',' << j << ')' << '(' << k << ',' << l << ')' << '\n'; 
						add((n + i - 1) * m + j, (k - 1) * m + l, inf);
					}
	while(bfs())
	{
		for(int i = 1; i <= T; i++) cur[i] = head[i];
		ans -= dfs(S, inf);
	}
	cout << ans;
	return 0;
}