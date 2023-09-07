#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, k, dep;
long long ans;
long long a[N], dp[N][26];
int ql = 1, qr, c[N];
inline void add(int x, int v) {for(int i = x; i <= n; i += (i & -i)) c[i] += v;}
inline long long ask(int x, long long res = 0) {for(int i = x; i; i -= (i & -i)) res += c[i]; return res;}
inline long long cal(int l, int r)
{
	while(ql > l) add(a[--ql], 1), ans += ask(n) - ask(a[ql]);
	while(qr < r) ans += ask(a[++qr]), add(a[qr], 1);
	while(ql < l) ans -= ask(n) - ask(a[ql]), add(a[ql++], -1);
	while(qr > r) add(a[qr], -1), ans -= ask(a[qr--]);
	return ans;
}
inline void compute(int l, int r, int L, int R)
{
	if(l > r) return;
	int mid = l + r >> 1;
	long long minn = 1e15, pos;
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