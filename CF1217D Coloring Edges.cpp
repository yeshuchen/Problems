#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, tot;
int x[N], y[N], col[N];
int deg[N], ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
	deg[y]++;
}
inline bool topo_sort()
{
	queue<int> q;
	for(int i = 1; i <= n; i++)
		if(!deg[i]) q.push(i);
	int cnt = 0;
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		cnt++;
		for(int i = head[x]; i; i = nxt[i])
		{
			int y = ver[i];
			if(--deg[y] == 0) q.push(y);
		}
	}
	return cnt == n;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> x[i] >> y[i];
		add(x[i], y[i]);
	}
	if(topo_sort())
	{
		cout << 1 << '\n';
		for(int i = 1; i <= m; i++)
			cout << 1 << ' ';
	}
	else
	{
		cout << 2 << '\n';
		for(int i = 1; i <= m; i++)
		{
			if(x[i] < y[i]) col[i] = 1;
			else col[i] = 2;
			cout << col[i] << ' ';
		}
	}
	return 0;
}