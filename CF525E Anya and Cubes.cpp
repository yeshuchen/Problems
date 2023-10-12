#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n, m;
ll s, ans;
int a[30];
map<ll, ll> mp[30];
inline ll fac(int x)
{
	ll base = 1;
	for(int i = x; i; i--)
	{
		if(base > s / i) return s + 1;
		base = base * i; 
	}
	return base;
}
inline void dfs(int l, int r, int f, ll v, int cnt)
{
	if(cnt > m) return;
	if(l > r)
	{
		if(f) ans += mp[m - cnt][s - v];
		else
		{
			for(int i = cnt; i <= m; i++)
				mp[i][v]++;
		}
		return;
	}
	dfs(l + 1, r, f, v, cnt);
	if(v + a[l] <= s) dfs(l + 1, r, f, v + a[l], cnt);
	if(v + fac(a[l]) <= s) dfs(l + 1, r, f, v + fac(a[l]), cnt + 1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(1, n / 2, 0, 0, 0);
	dfs(n / 2 + 1, n, 1, 0, 0);
	cout << ans;
	return 0;
}