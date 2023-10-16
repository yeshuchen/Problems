#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n, m;
int a[200005];
ll ans, f[200005];
int h1 = 1, t1, q1[N];
int h2 = 1, t2, q2[N];
int query(int l, int r)
{
	int res = INT_MAX;
	for(int i = l; i <= r; i++) res = min(res, a[i]);
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i], ans += a[i];
	a[0] = INT_MAX;
	for(int i = 1; i < m; i++)
	{
		while(h2 <= t2 && a[q2[t2]] > a[i]) t2--;
		q2[++t2] = i;
	}
	for(int i = m; i <= n; i++)
	{
		while(h2 <= t2 && q2[h2] < i - m + 1) h2++;
		while(h2 <= t2 && a[q2[t2]] > a[i]) t2--;
		q2[++t2] = i;
		f[i] = f[i - m] + a[q2[h2]];
		while(h1 <= t1 && q1[h1] < i - m + 1) h1++;
		f[i] = max(f[i], f[q1[h1]]);
		while(h1 <= t1 && f[q1[t1]] < f[i]) t1--;
		q1[++t1] = i;
	}
	cout << ans - f[n];
	return 0;
}