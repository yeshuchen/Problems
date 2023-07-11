#include<bits/stdc++.h>
using namespace std;
int T, n;
int a[200005], dp[200005], mx[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			dp[i] = 0, mx[i] = -20000000;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 1; i <= n; i++)
		{
			dp[i] = max(dp[i - 1], i + mx[a[i]]);
			mx[a[i]] = max(mx[a[i]], dp[i - 1] - i + 1);
		}
		cout << dp[n] << '\n';
	}
	return 0;
}