#include<bits/stdc++.h>
#define ll long long
using namespace std;
int tot;
int prime[100005];
map<int, int> m;
inline void separate(int x)
{
	for(int i = 2; i * i <= x; i++)
	{
		if(x % i) continue;
		if(!m[i]) prime[++tot] = i;
		while(x % i == 0) x /= i, m[i]++;
	}
	if(x > 1)
	{
		if(!m[x]) prime[++tot] = x;
		m[x]++;
	}
}
int T, n, m1, m2;
int ans, sum;
vector<ll> v;
inline void dfs(int p, ll val)
{
	if(p > tot)
	{
		v.push_back(val);
		return;
	}
	ll base = 1;
	for(int i = 0; i <= m[prime[p]]; i++)
	{
		dfs(p + 1, val * base);
		base *= prime[p];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		v.clear();
		tot = 0; ans = 0; sum = 0;
		cin >> n >> m1 >> m2;
		separate(m1);
		separate(m2);
		dfs(1, 1);
		sort(v.begin(), v.end());
		for(int i = 0; i < v.size(); i++)
		{
			ll x = v[i], p;
			if(x % n == 0) p = x / n;
			else p = x / n + 1;
			if(v[v.size() - 1] < p) continue;
			p = lower_bound(v.begin(), v.end(), p) - v.begin();
			for(int j = p; j <= i; j++)
			{
				if(v[j] > n) break;
				if(v[i] % v[j] == 0)
				{
					ans++;
					sum ^= v[j];
					break;
				}
			}
		}
		for(int i = 1; i <= tot; i++) m[prime[i]] = 0;
		cout << ans << " " << sum << '\n';
	}
	return 0;
}