#include<bits/stdc++.h>
using namespace std;
int n;
int h[2005], a[2005], f[2005][2005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> h[i];
	memcpy(a, h, sizeof(h));
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		f[1][i] = abs(h[1] - a[i]);
	for(int i = 2, minn = INT_MAX; i <= n; i++, minn = INT_MAX)
		for(int j = 1; j <= n; j++)
		{
			minn = min(minn, f[i - 1][j]);
			f[i][j] = minn + abs(h[i] - a[j]);
		}
	int ans = INT_MAX;
	for(int i = 1; i <= n; i++)
		ans = min(ans, f[n][i]);
	cout << ans;
	return 0;
}