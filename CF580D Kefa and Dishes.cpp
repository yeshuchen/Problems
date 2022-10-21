#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int a[20], c[20][20];
long long f[1 << 18][20];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= k; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		c[x][y] = z;
	}
	for(int i = 1; i < (1 << n); i <<= 1)
		for(int j = 1; j <= n; j++)
			if(i & (1 << j - 1))
				f[i][j] = a[j];
	for(int i = 1; i < (1 << n); i++)
		for(int j = 1; j <= n; j++)
			if(i & (1 << j - 1))
				for(int k = 1; k <= n; k++)
					if(i & (1 << k - 1) && j != k)
						f[i][j] = max(f[i ^ (1 << j - 1)][k] + a[j] + c[k][j], f[i][j]);
	long long ans = 0;
	for(int i = 1; i < (1 << n); i++)
	{
		int cnt = 0;
		for(int j = 1; j <= n; j++)
			if(i & (1 << j - 1)) cnt++;
		if(cnt == m)
		{
			for(int j = 1; j <= n; j++)
				ans = max(ans, f[i][j]);
		}
	}
	cout << ans;
	return 0;
}