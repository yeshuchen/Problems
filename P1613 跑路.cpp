#include<bits/stdc++.h>
using namespace std;
int n, m;
int dis[55][55];
bool f[55][55][70];
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			dis[i][j] = 1e9;
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		f[x][y][0] = 1;
		dis[x][y] = 1;
	}
	for(int base = 1; base <= 60; base++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				for(int k = 1; k <= n; k++)
					if(f[j][i][base - 1] && f[i][k][base - 1])
						f[j][k][base] = 1, dis[j][k] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= n; k++)
				if(dis[j][i] + dis[i][k] < dis[j][k])
					dis[j][k] = dis[j][i] + dis[i][k];
	cout << dis[1][n];
	return 0;
}