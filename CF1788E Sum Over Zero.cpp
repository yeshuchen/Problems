#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5 + 5;
int n;
int a[N], c[N], dp[N], tmp[N];
inline void add(int x, int v) {for(int i = x; i <= n; i += (i & -i)) c[i] = max(c[i], v);}
inline int ask(int x) {int res = INT_MIN; for(int i = x; i; i -= (i & -i)) res = max(res, c[i]); return res;}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	int len = 0;
	tmp[++len] = 0;
	for(int i = 1; i <= n; i++)
		cin >> a[i], a[i] += a[i - 1], tmp[++len] = a[i];
	sort(tmp + 1, tmp + len + 1);
	len = unique(tmp + 1, tmp + len + 1) - tmp - 1;
	for(int i = 0; i <= n; i++) a[i] = lower_bound(tmp + 1, tmp + len + 1, a[i]) - tmp, c[i] = INT_MIN;
	add(a[0], 0);
	for(int i = 1; i <= n; i++)
	{
		dp[i] = max(dp[i - 1], ask(a[i]) + i);
		add(a[i], dp[i] - i);
	}
	cout << dp[n];
	return 0;
}