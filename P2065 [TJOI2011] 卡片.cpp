#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int n, m, tot;
int x[10005], y[10005];
int head[800005], nxt[800005], ver[800005], limit[800005];
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
int dep[800005], cur[800005];
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
int t, ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--)
	{
		vector<int> v;
		ans = 0; tot = 1;
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			cin >> x[i];
		for(int i = 1; i <= m; i++)
			cin >> y[i];
		for(int i = 1; i <= n; i++)
		{
			int tmp = x[i];
			for(int j = 2; j * j <= x[i]; j++)
			{
				if(tmp % j) continue;
				while(tmp % j == 0) tmp /= j;
				v.push_back(j);
			}
			if(tmp > 1) v.push_back(tmp);
		}
		for(int i = 1; i <= m; i++)
		{
			int tmp = y[i];
			for(int j = 2; j * j <= y[i]; j++)
			{
				if(tmp % j) continue;
				while(tmp % j == 0) tmp /= j;
				v.push_back(j);
			}
			if(tmp > 1) v.push_back(tmp);
		}
		sort(v.begin(), v.end());
		unique(v.begin(), v.end());
		for(int i = 1; i <= n; i++)
		{
			for(int j = 0; j < v.size(); j++)
				if(x[i] % v[j] == 0)
					add(i, j + n + m + 1, 1);
		}
		for(int i = 1; i <= m; i++)
		{
			for(int j = 0; j < v.size(); j++)
				if(y[i] % v[j] == 0)
					add(j + n + m + 1, i + n, 1);
		}
		S = n + m + v.size() + 1, T = n + m + v.size() + 2;
		for(int i = 1; i <= n; i++) add(S, i, 1);
		for(int i = 1; i <= m; i++) add(i + n, T, 1);
		while(bfs())
		{
			for(int i = 1; i <= T; i++) cur[i] = head[i];
			ans += dfs(S, inf);
		}
		cout << ans << '\n';
		for(int i = 1; i <= tot; i++)
			head[i] = nxt[i] = limit[i] = 0;
	}
	return 0;
}