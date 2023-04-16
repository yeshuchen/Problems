#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
double f[400005][20];
int x[105], y[105], d[1000005];
inline double dis(int x, int y, int xx, int yy) {return sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));}
signed main()
{
	cin >> n >> m;
	n++; x[1] = 0, y[1] = 0;
	for(int i = 2; i <= n; i++)
		cin >> x[i] >> y[i];
	n += m;
	for(int i = n - m + 1; i <= n; i++)
		cin >> x[i] >> y[i];
	for(int i = 0; i < (1 << n); i++)
		for(int j = 0; j <= n; j++)
			for(int k = 0; k < (1 << m); k++)
				f[i][j] = 1e18;
	f[1][1] = 0;
	for(int i = 0; i < (1 << n); i++)
	{
		int cnt = 0;
		int tmp = (i >> n - m);
		for(int j = 1; j <= m; j++)
			if((1 << j - 1) & tmp)
				cnt++;
		d[i] = pow(2, cnt);
	}
	for(int i = 0; i < (1 << n); i++)
		for(int j = 1; j <= n; j++)
		{
			if(!((1 << j - 1) & i)) continue;
			for(int k = 1; k <= n; k++)
			{
				if(!((1 << k - 1) & i) || j == k) continue;
				f[i][j] = min(f[i][j], f[i - (1 << j - 1)][k] + dis(x[k], y[k], x[j], y[j]) / d[i - (1 << j - 1)]);
			}
		}
	double ans = 1e18;
	for(int i = 2; i <= n; i++)
		for(int j = 0; j < (1 << m); j++)
			ans = min(ans, f[(j << n - m) + (1 << n - m) - 1][i] + dis(0, 0, x[i], y[i]) / d[(j << n - m) + (1 << n - m) - 1]);
	printf("%.10lf", ans);
	return 0;
}