#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 205;
ll n, a[N];
char op[N];
ll f[N][N][2];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> op[i] >> a[i];
	for(int i = n + 1; i <= 2 * n; i++)
		op[i] = op[i - n], a[i] = a[i - n];
	for(int i = 1; i <= 2 * n; i++)
		f[i][i][0] = f[i][i][1] = a[i];
	for(int len = 2; len <= 2 * n; len++)
		for(int i = 1; i <= 2 * n; i++)
		{
			int j = i + len - 1;
			if(j > 2 * n) break;
			f[i][j][0] = INT_MAX;
			f[i][j][1] = INT_MIN;
			for(int k = i; k < j; k++)
			{
				if(op[k + 1] == 't') f[i][j][0] = min(f[i][j][0], f[i][k][0] + f[k + 1][j][0]), f[i][j][1] = max(f[i][j][1], f[i][k][1] + f[k + 1][j][1]);
				else
				{
					f[i][j][0] = min(f[i][j][0], min(min(f[i][k][0] * f[k + 1][j][0], f[i][k][0] * f[k + 1][j][1]), min(f[i][k][1] * f[k + 1][j][0], f[i][k][1] * f[k + 1][j][1])));
					f[i][j][1] = max(f[i][j][1], max(max(f[i][k][0] * f[k + 1][j][0], f[i][k][0] * f[k + 1][j][1]), max(f[i][k][1] * f[k + 1][j][0], f[i][k][1] * f[k + 1][j][1])));
				}
			}
		} 
	ll ans = INT_MIN;
	for(int i = 1; i <= n; i++)
		ans = max(ans, f[i][i + n - 1][1]);
	cout << ans << '\n';
	for(int i = 1; i <= n; i++)
		if(f[i][i + n - 1][1] == ans)
			cout << i << ' ';
	return 0;
}
/*
f[i][j][0]表示区间[i, j]能够凑出来的最小值
f[i][j][1]表示区间[i, j]能够凑出来的最大值
*/