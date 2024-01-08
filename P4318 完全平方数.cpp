#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int cnt;
int mu[N], pr[N], vis[N];
void sieve(int V = 1e6)
{
	mu[1] = 1;
	for(int i = 2; i <= V; i++)
	{
		if(!vis[i]) mu[i] = -1, pr[++cnt] = i; 
		for(int j = 1; j <= cnt && i * pr[j] <= V; j++)
		{
			vis[i * pr[j]] = 1; mu[i * pr[j]] = -mu[i];
			if(i % pr[j] == 0) {mu[i * pr[j]] = 0; break;}
		}
	}
	// for(int i = 1; i <= 6; i++) cout << mu[i] << ' ';
}
long long f(long long n)
{
	long long res = 0;
	for(int i = 1; 1ll * i * i <= n; i++)
		res += mu[i] * (n / (1ll * i * i));
	return res;
}
int main()
{
	int T, n;
	cin >> T;
	sieve();
	while(T--)
	{
		cin >> n;
		long long l = 1, r = 1e12, ans = 0;
		while(l <= r)
		{
			long long mid = (l + r) / 2;
			if(f(mid) >= n) r = (ans = mid) - 1;
			else l = mid + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}