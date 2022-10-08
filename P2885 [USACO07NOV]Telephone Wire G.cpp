#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, c, maxn;
int h[N], f[N][105];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> c;
	for(int i = 1; i <= n; i++)
		cin >> h[i], maxn = max(maxn, h[i]);
	for(int i = h[1]; i <= maxn; i++)
		f[1][i] = (h[1] - i) * (h[1] - i);
	for(int i = 2; i <= n; i++)
		for(int j = h[i]; j <= maxn; j++)
		{
			int w = (h[i] - j) * (h[i] - j);
			f[i][j] = INT_MAX;
			for(int k = h[i - 1]; k <= maxn; k++)
				f[i][j] = min(f[i][j], f[i - 1][k] + abs(j - k) * c + w);
		}
	int ans = INT_MAX;
	for(int i = h[n]; i <= maxn; i++)
		ans = min(ans, f[n][i]);
	cout << ans;
	return 0;
}