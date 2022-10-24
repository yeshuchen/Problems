#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int T, tot;
bool vis[N];
long long mu[N], prime[N];
inline void lineshai()
{
	mu[1] = 1;
	for(int i = 2; i <= 1000000; i++)
	{
		if(!vis[i]) prime[++tot] = i, mu[i] = -1;
		for(int j = 1; j <= tot && i * prime[j] <= 1000000; j++)
		{
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0)
			{
				mu[i * prime[j]] = 0;
				break;
			}
			mu[i * prime[j]] = -mu[i];
		}
	}
	for(int i = 1; i <= 1000000; i++) mu[i] += mu[i - 1];
}
inline long long solve(int n, int m)
{
	long long ans = 0;
	if(n > m) swap(n, m);
	for(int i = 1, j; i <= n; i = j + 1)
	{
		j = min(n / (n / i), m / (m / i));
		ans += (mu[j] - mu[i - 1]) * (n / i) * (m / i);
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	lineshai();
	int a, b, k;
	cin >> a >> b >> k;
	cout << solve(a / k, b / k);
	return 0;
}