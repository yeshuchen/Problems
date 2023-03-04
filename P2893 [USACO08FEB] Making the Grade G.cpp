#include<bits/stdc++.h>
using namespace std;
int n;
long long ans = LLONG_MAX;
long long h[2005], a[2005], f[2005][2005];
inline void solve()
{
	for(int i = 1; i <= n; i++)
		f[1][i] = abs(h[1] - a[i]);
	for(int i = 2; i <= n; i++)
	{
		long long minn = LLONG_MAX;
		for(int j = 1; j <= n; j++)
		{
			minn = min(minn, f[i - 1][j]);
			f[i][j] = minn + abs(h[i] - a[j]);
		}
	}
	for(int i = 1; i <= n; i++)
		ans = min(ans, f[n][i]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> h[i];
	memcpy(a, h, sizeof(h));
	sort(a + 1, a + n + 1);
	solve();
	reverse(h + 1, h + n + 1);
	solve();
	cout << ans;
	return 0;
}