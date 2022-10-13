#include<bits/stdc++.h>
using namespace std;
int a[85];
__int128 power[85];
__int128 ans, f[85][85];
inline void write(__int128 x)
{
	if(x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
int main()
{
	int n, m;
	cin >> n >> m;
	power[0] = 1;
	for(int i = 1; i <= m; i++) power[i] = power[i - 1] * 2;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
			cin >> a[j];
		for(int j = 1; j <= m; j++) f[j][j] = (__int128)a[j] * power[m];
		for(int len = 2; len <= m; len++)
		{
			for(int j = 1; j <= m; j++)
			{
				int k = j + len - 1;
				if(k > m) break;
				f[j][k] = max(f[j][k - 1] + a[k] * power[m - len + 1], f[j + 1][k] + a[j] * power[m - len + 1]);
			}
		}
		ans += f[1][m];
	}
	write(ans);
	return 0;
}