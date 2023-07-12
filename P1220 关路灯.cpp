#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, c, sum;
int a[505], x[505];
int f[505][505][2];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> c;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			f[i][j][0] = f[i][j][1] = INT_MAX;
	f[c][c][0] = f[c][c][1] = 0;
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> x[i], sum += x[i], x[i] += x[i - 1];
	for(int len = 2; len <= n; len++)
		for(int i = 1; i + len - 1 <= n; i++)
		{
			int j = i + len - 1;
			f[i][j][0] = min(f[i + 1][j][0] + (a[i + 1] - a[i]) * (sum - (x[j] - x[i])), f[i + 1][j][1] + (a[j] - a[i]) * (sum - (x[j] - x[i])));
			f[i][j][1] = min(f[i][j - 1][0] + (a[j] - a[i]) * (sum - (x[j - 1] - x[i - 1])), f[i][j - 1][1] + (a[j] - a[j - 1]) * (sum - (x[j - 1] - x[i - 1])));
		}
	cout << min(f[1][n][0], f[1][n][1]);
	return 0;
}