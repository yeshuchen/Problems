#include<bits/stdc++.h>
using namespace std;
struct node {
	int x, y, k, d;
};
int n, m, p, k;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int in[105][105], vis[105][105];
int used[15][15][10005];
inline int get(int x, int y) {return (x - 1) * m + y;}
inline int solve()
{
	queue<node> q;
	q.push((node){1, 1, in[1][1], 0});
	while(!q.empty())
	{
		node t = q.front(); q.pop();
		used[t.x][t.y][t.k] = 1;
		// cout << t.x << ' ' << t.y << ' ' << t.k << ' ' << t.d << '\n';
		if(t.x == n && t.y == m) return t.d;
		for(int i = 0; i < 4; i++)
		{
			int nx = t.x + dx[i], ny = t.y + dy[i];
			if(nx < 1 || nx > n || ny < 1 || ny > m || used[nx][ny][t.k | in[nx][ny]] || vis[get(t.x, t.y)][get(nx, ny)] == 0 || (vis[get(t.x, t.y)][get(nx, ny)] > 0 && !((1 << vis[get(t.x, t.y)][get(nx, ny)] - 1) & t.k))) continue;
			used[nx][ny][t.k | in[nx][ny]] = 1;
			q.push((node){nx, ny, t.k | in[nx][ny], t.d + 1});
		}
	}
	return -1;
}
int main()
{
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> p >> k;
	memset(vis, -1, sizeof(vis));
	for(int i = 1; i <= k; i++)
	{
		int x1, y1, x2, y2, g;
		cin >> x1 >> y1 >> x2 >> y2 >> g;
		vis[get(x1, y1)][get(x2, y2)] = vis[get(x2, y2)][get(x1, y1)] = g;
	}
	int S;
	cin >> S;
	for(int i = 1; i <= S; i++)
	{
		int x, y, q;
		cin >> x >> y >> q;
		in[x][y] |= (1 << q - 1);
	}
	cout << solve();
}