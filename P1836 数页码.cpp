#include<bits/stdc++.h>
using namespace std;
int n, len;
long long sum;
long long a[15], ans[15], dp[15], mu[15];
inline void solve()
{
	int tmp = n;
	while(n)
	{
		a[++len] = n % 10;
		n /= 10;
	}	
	for(int i = len; i; i--)
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
	for(int i = 1; i <= 9; i++)
	{
		dp[i] = 10 * dp[i - 1] + mu[i - 1];
		mu[i] = mu[i - 1] * 10;
	}
	solve();
	for(int i = 0; i < 10; i++)
		sum = sum + 1ll * i * ans[i];
	cout << sum;
	return 0;
}