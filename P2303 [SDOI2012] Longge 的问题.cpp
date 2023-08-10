#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, q, cnt;
long long ans;
int p[N], tmp[N];
inline int phi(int x)
{
	int res = x;
	for(int i = 2; i * i <= x; i++)
		if(x % i == 0)
		{
			res = 1ll * res * (i - 1) / i;
			while(x % i == 0) x /= i;
		}
	if(x > 1) res = 1ll * res * (x - 1) / x;
	return res;
}
inline void dfs(int x, int val)
{
	if(x > cnt)
	{
		ans = ans + val * phi(q / val);
		return;
	}
	for(int i = 0; i <= p[x]; i++)
	{
		dfs(x + 1, val);
		val *= tmp[x];
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	q = n;
	for(int i = 2; i * i <= n; i++)
	{
		if(n % i) continue;
		tmp[++cnt] = i;
		while(n % i == 0)
		{
			n /= i;
			p[cnt]++;
		}
	}
	if(n > 1)
	{
		tmp[++cnt] = n;
		p[cnt]++;
	}
	dfs(1, 1);
	cout << ans;
	return 0;
}