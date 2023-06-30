#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, m, d, A, B;
int g[1005][1005], w[1005][1005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			g[i][j] = INF;
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		g[x][y] = g[y][x] = 0;
		w[x][y] = w[y][x] = z;
	}
	cin >> d;
	for(int i = 1; i <= d; i++)
	{
		int x, y;
		cin >> x >> y;
		g[x][y] = g[y][x] = w[x][y];
	}
	cin >> A >> B;
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
			{
				if(g[i][k] != INF && g[k][j] != INF)
					g[i][j] = min(g[i][k] + g[k][j], g[i][j]);
			}
	cout << g[A][B];
	return 0;
}