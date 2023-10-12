#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, tot;
int op[N], x[N], y[N];
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int col[N];
inline void dfs(int x, int c)
{
	col[x] = c;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(col[y])
		{
			if(col[x] == col[y]) {cout << "NO"; exit(0);}
			continue;
		}
		dfs(y, 3 - c);
	}
}
int deg[N], ans[N];
vector<int> g[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> op[i] >> x[i] >> y[i];
		add(x[i], y[i]); add(y[i], x[i]);
	}
	for(int i = 1; i <= n; i++)
		if(!col[i]) dfs(i, 1);
	for(int i = 1; i <= m; i++)
	{
		if(op[i] == 1)
		{
			if(col[x[i]] == 1) g[x[i]].push_back(y[i]), deg[y[i]]++;
			else g[y[i]].push_back(x[i]), deg[x[i]]++;
		}
		else
		{
			if(col[x[i]] == 1) g[y[i]].push_back(x[i]), deg[x[i]]++;
			else g[x[i]].push_back(y[i]), deg[y[i]]++;
		}
	}
	queue<int> q;
	for(int i = 1; i <= n; i++)
		if(!deg[i])
			q.push(i);
	int res = 0;
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		ans[x] = ++res;
		for(int y : g[x])
			if(--deg[y] == 0)
				q.push(y);
	}
	if(res != n) {cout << "NO"; return 0;}
	cout << "YES\n";
	for(int i = 1; i <= n; i++)
	{
		if(col[i] == 1) cout << "L ";
		else cout << "R ";
		cout << ans[i] << '\n';
	}
	return 0;
}