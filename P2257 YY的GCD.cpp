#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e7 + 5;
int tot;
int s[N], mu[N], pr[N], vis[N];
void sieve(int maxn)
{
	mu[1] = 1;
	for(int i = 2; i <= maxn; i++)
	{
		if(!vis[i]) mu[i] = -1, pr[++tot] = i;
		for(int j = 1; j <= tot && i * pr[j] <= maxn; j++)
		{
			vis[i * pr[j]] = 1;
			mu[i * pr[j]] = mu[i] * -1;
			if(i % pr[j] == 0)
			{
				mu[i * pr[j]] = 0;
				break;
			}
		}
	}
	for(int i = 1; i <= maxn; i++)
	{
		for(int j = 1; j <= tot && i * pr[j] <= maxn; j++)
			s[i * pr[j]] += mu[i];
	}
	for(int i = 1; i <= maxn; i++) s[i] += s[i - 1];
}
int solve(int n, int m)
{
	int ans = 0;
	for(int l = 1, r; l <= min(n, m); l = r + 1)
	{
		r = min(n / (n / l), m / (m / l));
		ans += (n / l) * (m / l) * (s[r] - s[l - 1]);
	}
	return ans;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	sieve(1e7);
	int T;
	cin >> T;
	while(T--)
	{
		int x, y, ans = 0;
		cin >> x >> y;
		cout << solve(x, y) << '\n';
	}
	return 0;
}