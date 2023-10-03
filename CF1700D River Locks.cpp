#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q;
int a[N];
long long sum;
inline bool check(int x)
{
	long long res = 0, w = 0;
	for(int i = 1; i <= n; i++)
	{
		res += x, w += a[i];
		if(res < w) return false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n; int mn = 0;
	for(int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
	int l = a[1], r = 1000000000;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(check(mid)) r = (mn = mid) - 1;
		else l = mid + 1;
	}
	cin >> q;
	while(q--)
	{
		int t;
		cin >> t;
		if(t < mn) {cout << -1 << '\n'; continue;}
		int l = 1, r = n, ans = -1;
		while(l <= r)
		{
			int mid = l + r >> 1;
			if(1ll * mid * t >= sum) r = (ans = mid) - 1;
			else l = mid + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}