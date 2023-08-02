#include<bits/stdc++.h>
using namespace std;
int c[5], d[5], n;
long long dp[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c[1] >> c[2] >> c[3] >> c[4] >> n;
	dp[0] = 1;
	for(int i = 1; i <= 4; i++)
		for(int j = c[i]; j <= 1e5; j++)
			dp[j] += dp[j - c[i]];
	for(int i = 1; i <= n; i++)
	{
		long long ans, s;
		cin >> d[1] >> d[2] >> d[3] >> d[4] >> s;
		ans = dp[s];
		for(int i = 1; i <= 15; i++)
		{
			int f = 1, num = 0;
			long long k = 0;
			for(int j = 1; j <= 4; j++)
				if(i & (1 << j - 1))
					num++, k += 1ll * c[j] * (d[j] + 1);
			if(num & 1) f = -1;
			if(k <= s) ans += f * dp[s - k];
		}
		cout << ans << '\n';
	}
	return 0;
}