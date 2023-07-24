#include<bits/stdc++.h>
using namespace std;
int n, m, x, y, k;
int h, t, q[20005], tmp[205];
int f[2][205][205];
char c[205][205];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> x >> y >> k;
	for(int i = 1; i <= n; i++)
	    for(int j = 1; j <= m; j++)
	        f[0][i][j] = f[1][i][j] = -1;
	f[0][x][y] = f[1][x][y] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> c[i][j];
	for(int i = 1; i <= k; i++)
	{
		int l, r, d;
		cin >> l >> r >> d;
		int len = r - l + 1;
		if(d == 1)
		{
			for(int j = 1; j <= m; j++)
			{
				h = 1; t = 0;
				for(int i = n; i; i--)
				{
					if(c[i][j] == 'x')
					{
						h = 1; t = 0;
						continue;
					}
					while(q[h] > i + len && h <= t) h++;
					if(h <= t) f[1][i][j] = max(f[0][i][j], tmp[q[h]] - i);
					if(f[0][i][j] == -1) continue;
					tmp[i] = f[0][i][j] + i;
					while(tmp[q[t]] < tmp[i] && h <= t) t--;
					q[++t] = i;
				}
			}
		}
		if(d == 2)
		{
			for(int j = 1; j <= m; j++)
			{
				h = 1; t = 0;
				for(int i = 1; i <= n; i++)
				{
					if(c[i][j] == 'x')
					{
						h = 1; t = 0;
						continue;
					}
					while(q[h] < i - len && h <= t) h++;
					if(h <= t) f[1][i][j] = max(f[0][i][j], tmp[q[h]] + i);
					if(f[0][i][j] == -1) continue;
					tmp[i] = f[0][i][j] - i;
					while(tmp[q[t]] < tmp[i] && h <= t) t--;
					q[++t] = i;
				}
			}
		}
		if(d == 3)
		{
			for(int i = 1; i <= n; i++)
			{
				h = 1; t = 0;
				for(int j = m; j; j--)
				{
					if(c[i][j] == 'x')
					{
						h = 1; t = 0;
						continue;
					}
					while(q[h] > j + len && h <= t) h++;
					if(h <= t) f[1][i][j] = max(f[0][i][j], tmp[q[h]] - j);
					if(f[0][i][j] == -1) continue;
					tmp[j] = f[0][i][j] + j;
					while(tmp[q[t]] < tmp[j] && h <= t) t--;
					q[++t] = j;
				}
			}
		}
		if(d == 4)
		{
			for(int i = 1; i <= n; i++)
			{
				h = 1; t = 0;
				for(int j = 1; j <= m; j++)
				{
					if(c[i][j] == 'x')
					{
						h = 1; t = 0;
						continue;
					}
					while(q[h] < j - len && h <= t) h++;
					if(h <= t) f[1][i][j] = max(f[0][i][j], tmp[q[h]] + j);
					if(f[0][i][j] == -1) continue;
					tmp[j] = f[0][i][j] - j;
					while(tmp[q[t]] < tmp[j] && h <= t) t--;
					q[++t] = j;
				}
			}
		}
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				f[0][i][j] = f[1][i][j];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			ans = max(ans, f[0][i][j]);
	cout << ans;
	return 0;
}