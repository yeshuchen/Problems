#include<bits/stdc++.h>
using namespace std;
int n, m;
char c[505][505];
bool vis[505][505];
vector< pair<int, int> > v;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
inline bool bfs()
{
	queue< pair<int, int> > q;
	for(int i = 0; i < v.size(); i++) q.push(v[i]);
	v.clear();
	while(!q.empty())
	{
		int x = q.front().first, y = q.front().second; q.pop();
		if(vis[x][y]) continue; vis[x][y] = 1;
		if(x == n && y == m) return true;
		for(int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
			if(c[nx][ny] == '#') v.push_back(make_pair(nx, ny));
			else q.push(make_pair(nx, ny));
		}
	}
	return false;
}
int ans = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> c[i][j];
    v.push_back(make_pair(1, 1));
	while(!bfs())
	{
		ans++;
		for(int i = 0; i < v.size(); i++)
		{
			int x = v[i].first, y = v[i].second;
			c[x][y] = c[x - 1][y - 1] = c[x - 1][y] = c[x - 1][y + 1] = c[x][y - 1] = c[x][y + 1] = c[x + 1][y - 1] = c[x + 1][y] = c[x + 1][y + 1] = '.';
		}
	}
	cout << ans;
	return 0;
}