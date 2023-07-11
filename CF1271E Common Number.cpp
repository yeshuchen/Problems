#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, k;
inline int check(int w)
{
	if(w == n) return 1;
	int sum = 0, fr = 1, l, r;
	if(w & 1)
	{
		sum++;
		l = w * 2, r = w * 2 + 1;
	}
	else
	{
		l = w;
		r = w + 1;
	}
	while(r <= n)
	{
		fr *= 2;
		sum += fr;
		l *= 2;
		r = r * 2 + 1;
	}
	r = min(r, n);
	sum += max(r - l + 1, 0ll);
	return sum;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	if(k == n) {cout << 1; return 0;}
	if(k == 1) {cout << n; return 0;}
	int l = 1, r = n / 2, ans, tmp;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(check(mid * 2) >= k) l = (tmp = mid) + 1;
		else r = mid - 1;
	}
	ans = tmp * 2;
	l = 1, r = (n + 1) / 2;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(check(mid * 2 - 1) >= k) l = (tmp = mid) + 1;
		else r = mid - 1;
	}
	ans = max(ans, tmp * 2 - 1);
	cout << ans;
	return 0;
}