#include<bits/stdc++.h>
using namespace std;
int n, m, T;
struct node {
	int x, y, t;
};
char c[105][105];
int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
int ans[105][105][20], vis[105][105][20];
queue<node> q;
inline void bfs()
{
	while(!q.empty())
	{
		node point = q.front(); q.pop();
		if(point.t == T || vis[point.x][point.y][point.t]) continue;
		vis[point.x][point.y][point.t] = 1;
		for(int i = 0; i < 4; i++)
		{
			int x = point.x, y = point.y;
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 1 || nx > n || ny < 1 || ny > m || c[nx][ny] == '*') continue;
			ans[nx][ny][point.t + 1] += ans[x][y][point.t];
			q.push((node){nx, ny, point.t + 1});
		}

	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> T;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> c[i][j];
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	ans[r1][c1][0] = 1;
	q.push((node){r1, c1, 0});
	bfs();
	cout << ans[r2][c2][T];
	return 0;
}