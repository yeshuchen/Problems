#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int T;
int a[4][N], p[5], n[5];
int calc(int x, int y, int z)
{
	return (a[p[1]][x] - a[p[2]][y]) * (a[p[1]][x] - a[p[2]][y]) + (a[p[1]][x] - a[p[3]][z]) * (a[p[1]][x] - a[p[3]][z]) + (a[p[2]][y] - a[p[3]][z]) * (a[p[2]][y] - a[p[3]][z]);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int ans = LLONG_MAX;
		cin >> n[1] >> n[2] >> n[3];
		p[1] = 1; p[2] = 2; p[3] = 3;
		for(int i = 1; i <= 3; i++)
		{
			for(int j = 1; j <= n[i]; j++)
				cin >> a[i][j];
			sort(a[i] + 1, a[i] + n[i] + 1);
		}
		do
		{
			for(int i = 1; i <= n[p[1]]; i++)
			{
				int x = lower_bound(a[p[2]] + 1, a[p[2]] + n[p[2]] + 1, a[p[1]][i]) - a[p[2]];
				if(x > n[p[2]]) break;
				int y = lower_bound(a[p[3]] + 1, a[p[3]] + n[p[3]] + 1, a[p[2]][x]) - a[p[3]];
				if(y > n[p[3]]) break;
				int x2 = upper_bound(a[p[2]] + 1, a[p[2]] + n[p[2]] + 1, (a[p[3]][y] + a[p[1]][i]) / 2) - a[p[2]] - 1;
				ans = min(ans, calc(i, x, y));
				ans = min(ans, calc(i, x2, y));
				if(x2 < n[p[2]]) ans = min(ans, calc(i, x2 + 1, y));
			}
		} while (next_permutation(p + 1, p + 4));
		cout << ans << '\n';
	}
	return 0;
}