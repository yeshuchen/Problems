#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, k, dep, ans;
int a[N], dp[N][25];
int ql = 1, qr, cnt[N];
inline int cal(int l, int r)
{
	while(ql > l) ans += cnt[a[--ql]]++;
	while(qr < r) ans += cnt[a[++qr]]++;
	while(ql < l) ans -= --cnt[a[ql++]];
	while(qr > r) ans -= --cnt[a[qr--]];
	return ans;
}
inline void compute(int l, int r, int L, int R)
{
	if(l > r) return;
	int mid = l + r >> 1;
	int minn = 1e15, pos;
	for(int i = L; i <= min(mid, R); i++)
	{
		int v = dp[i - 1][dep - 1] + cal(i, mid);
		if(v <= minn) minn = v, pos = i;
	}
	dp[mid][dep] = minn;
	compute(l, mid - 1, L, pos);
	compute(mid + 1, r, pos, R);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i], dp[i][0] = 2e15;
	dep = 1;
	while(dep <= k)
	{
		compute(1, n, 1, n);
		dep++; 
	}
	cout << dp[n][k];
	return 0;
}