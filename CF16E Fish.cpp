#include<bits/stdc++.h>
using namespace std;
int n;
double p[505][505], dp[5000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> p[i][j];
	dp[(1 << n) - 1] = 1;
	for(int i = (1 << n) - 1; i; i--)
		for(int j = 1; j <= n; j++)
		{
			int res = 0;
			if(i & (1 << j - 1)) continue;
			for(int k = 1; k <= n; k++) res += (bool)(i & (1 << k - 1));
			for(int k = 1; k <= n; k++)
			{
				if(!(i & (1 << k - 1))) continue;
				dp[i] += dp[i + (1 << j - 1)] * p[k][j] / (1.0 * (res + 1) * res / 2);
			}
		}
	for(int i = 1; i <= n; i++) printf("%.6lf ", dp[1 << (i - 1)]);
	return 0;
}