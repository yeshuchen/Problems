#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll a1[25], a2[25];
ll a[25], dp[25], mu[25];
inline void solve(ll *cnt, ll n)
{
	int len = 0;
	ll tmp = n;
	while(n)
	{
		a[++len] = n % 10;
		n /= 10;
	}	
	for(int i = len; i; i--)
	{
		for(int j = 0; j < 10; j++) cnt[j] += dp[i - 1] * a[i];
		for(int j = 0; j < a[i]; j++) cnt[j] += mu[i - 1];
		tmp -= a[i] * mu[i - 1]; cnt[a[i]] += tmp + 1;
		cnt[0] -= mu[i - 1];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	mu[0] = 1;
	for(int i = 1; i <= 16; i++)
	{
		dp[i] = 10 * dp[i - 1] + mu[i - 1];
		mu[i] = mu[i - 1] * 10;
	}
	int T;
	cin >> T;
	while(T--)
	{
		ll l, r, sum = 0, ans[15];
		memset(ans, 0, sizeof(ans));
		memset(a1, 0, sizeof(a1));
		memset(a2, 0, sizeof(a2));
		cin >> l >> r;
		if(l < 1) l = 1;
		solve(a1, l - 1);
		solve(a2, r);
		for(int i = 0; i < 10; i++) ans[i] += a2[i] - a1[i];
		for(int i = 0; i < 10; i++)
			sum = sum + 1ll * i * ans[i];
		cout << sum << '\n';
	}
	return 0;
}