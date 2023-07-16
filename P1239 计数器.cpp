#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll ans[15], a[15];
ll mu[20], dp[20];
inline void solve()
{
	int tmp = n, len = 0;
	while(tmp)
	{
		a[++len] = tmp % 10;
		tmp /= 10;
	}
	tmp = n;
	for(int i = len; i >= 1; i--)
	{
		for(int j = 0; j < 10; j++) ans[j] += dp[i - 1] * a[i];
		for(int j = 0; j < a[i]; j++) ans[j] += mu[i - 1];
		tmp -= a[i] * mu[i - 1]; ans[a[i]] += tmp + 1;
		ans[0] -= mu[i - 1];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	mu[0] = 1;
	for(int i = 1; i <= 10; i++)
	{
		dp[i] = 10 * dp[i - 1] + mu[i - 1];
		mu[i] = mu[i - 1] * 10;
	}
	solve();
	for(int i = 0; i <= 9; i++)
		cout << ans[i] << '\n';
	return 0;
}