#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000005], dp[1000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		dp[i] = max(dp[i - 1], a[i] - dp[i - 1]);
	cout << dp[n];
	return 0;
}