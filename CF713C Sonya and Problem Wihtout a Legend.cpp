#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e4 + 5;
int n;
int a[N], ret[N];
int f[3005][3005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], a[i] -= i, ret[i] = a[i];
	sort(ret + 1, ret + n + 1);
	int tot = unique(ret + 1, ret + n + 1) - ret - 1;
	for(int i = 1; i <= n; i++)
	{
		int mn = LLONG_MAX;
		for(int j = 1; j <= tot; j++)
		{
			mn = min(mn, f[i - 1][j]);
			f[i][j] = mn + abs(ret[j] - a[i]);
		}
	}
	int ans = LLONG_MAX;
	for(int i = 1; i <= tot; i++) ans = min(ans, f[n][i]);
	cout << ans;
	return 0;
}