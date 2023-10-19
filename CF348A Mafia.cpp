#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
ll n, l, r = 2e18;
ll a[N];
bool check(ll w)
{
	ll s = w;
	for(int i = 1; i <= n; i++)
	{
		s -= w - a[i];
		if(s <= 0) return true;
	}
	return s <= 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n; ll ans = LLONG_MAX;
	for(int i = 1; i <= n; i++)
		cin >> a[i], l = max(l, a[i]);
	while(l <= r)
	{
		ll mid = l + r >> 1;
		if(check(mid)) r = (ans = mid) - 1;
		else l = mid + 1;
	}
	cout << ans;
	return 0;
}