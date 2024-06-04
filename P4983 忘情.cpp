#include<bits/stdc++.h>
#define X(id) (s[id])
#define Y(id) (dp[id] + s[id] * s[id] - 2 * s[id])
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, k, ans;
int a[N], s[N];
int cnt[N], dp[N];
long double slope(int a, int b) {return (long double)(Y(b) - Y(a)) / (X(b) - X(a));}
int hd, tl, q[N];
int check(int w)
{
	memset(dp, 0x3f, sizeof(dp));
	memset(cnt, 0, sizeof(cnt));
	dp[0] = 0;
	int hd = 1, tl = 1; q[1] = 0;
	for(int i = 1; i <= n; i++)
	{
		while(hd < tl && slope(q[hd], q[hd + 1]) < 2 * s[i]) hd++;
		dp[i] = dp[q[hd]] + (s[i] - s[q[hd]] + 1) * (s[i] - s[q[hd]] + 1) + w;
		cnt[i] = cnt[q[hd]] + 1;
		while(hd < tl && slope(q[tl - 1], q[tl]) > slope(q[tl - 1], i)) tl--;
		q[++tl] = i;
	}
	return cnt[n];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] + a[i];
	int l = 0, r = 1e18, pos;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(check(mid) <= k) r = (pos = mid) - 1;
		else l = mid + 1;
	}
	check(pos); cout << dp[n] - k * pos;
	return 0;
}