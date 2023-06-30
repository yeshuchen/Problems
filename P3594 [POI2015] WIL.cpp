#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000005];
int n, m, d, ans;
int L, R, q[2000005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> d;
	for(int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
	int l = 1;
	q[++L] = d;
	for(int i = d + 1; i <= n; i++)
	{
		while(L <= R && a[i] - a[i - d] > a[q[R]] - a[q[R] - d]) R--;
		q[++R] = i;
		while(a[i] - a[l - 1] - a[q[L]] + a[q[L] - d] > m)
		{
			l++;
			while(L <= R && q[L] - d + 1 < l) L++;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
}