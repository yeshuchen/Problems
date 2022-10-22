#include<bits/stdc++.h>
using namespace std;
int n, ans = INT_MAX;
int h[25][25];
int f[(1 << 20)][21];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> h[i][j];
	f[1][1] = 0;
	for(int i = 1; i < (1 << n); i += 2)
		for(int j = 1; j <= n; j++)
		{
			if(!(i & (1 << j - 1))) continue;
			for(int k = 1; k <= n; k++)
			{
				if(k == j || !(i & (1 << k - 1))) continue;
				f[i][j] = min(f[i][j], f[i ^ (1 << j - 1)][k] + h[k][j]);
			}
		}
	for(int i = 2; i <= n; i++)
		ans = min(ans, f[(1 << n) - 1][i] + h[i][1]);
	cout << ans;
	return 0;
}