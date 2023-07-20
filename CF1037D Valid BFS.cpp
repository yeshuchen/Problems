#include<bits/stdc++.h>
using namespace std;
int n;
int p[200005];
int f[200005];
bool vis[200005];
vector<int> g[200005];
inline void bfs()
{
	queue<int> q;
	q.push(1);
	int pos = 2;
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		int lastpos = pos;
		for(int i = 0; i < g[x].size(); i++)
		{
			int y = g[x][i];
			if(y == f[x]) continue;
			f[y] = x;
			vis[y] = 1;
		}
		while(vis[p[pos]] && pos <= n) q.push(p[pos++]);
		if(x == 1 && pos - lastpos != g[x].size() || x != 1 && pos - lastpos != g[x].size() - 1)
		{
			cout << "No";
			return;
		}
		for(int i = 0; i < g[x].size(); i++)
			vis[g[x][i]] = 0;
	}
	if(pos <= n)
	{
		cout << "No";
		return;
	}
	cout << "Yes";
	return;
}
int main()
{
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i = 1; i <= n; i++) cin >> p[i];
	bfs();
	return 0;
}