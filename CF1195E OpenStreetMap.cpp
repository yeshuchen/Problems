#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, R, C;
int x, y, z;
int q[300001];
int a[3001][3001], f[3001][3001], g[9000001];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> R >> C;
	cin >> g[1] >> x >> y >> z;
	for(int i = 2; i <= n * m; i++)
		g[i] = (g[i - 1] * x + y) % z;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			a[i][j] = g[(i - 1) * m + j];
	for(int i = 1; i <= n; i++)
	{
		int h = 1, t = 0;
		for(int j = 1; j <= m; j++)
		{
			while(h <= t && q[h] <= j - C) h++;
			while(h <= t && a[i][q[t]] > a[i][j]) t--;
			q[++t] = j;
			if(j >= C) f[i][j - C + 1] = a[i][q[h]];
		}
	}
	int ans = 0;
	for(int j = 1; j <= m - C + 1; j++)
	{
		int h = 1, t = 0;
		for(int i = 1; i <= n; i++)
		{
			while(h <= t && q[h] <= i - R) h++;
			while(h <= t && f[q[t]][j] > f[i][j]) t--;
			q[++t] = i;
			if(i >= R) ans += f[q[h]][j];
		}
	}
	cout << ans;
	return 0;
}