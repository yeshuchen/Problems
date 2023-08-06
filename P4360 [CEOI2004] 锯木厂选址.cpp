#include<bits/stdc++.h>
using namespace std;
int n;
int w[200005], d[200005], wd[200005];
inline int cost(int x, int y)
{
	return wd[y] - wd[x - 1] - (w[y] - w[x - 1]) * d[y];
}
int f[200005];
inline void solve(int l, int r, int pl, int pr)
{
	int p;
	int m = l + r >> 1; f[m] = INT_MAX;
	for(int i = pl, v; i <= min(m - 1, pr); i++)
		if((v = cost(1, i) + cost(i + 1, m)) < f[m])
			f[m] = v, p = i;
	if(l < m) solve(l, m - 1, pl, p);
	if(m < r) solve(m + 1, r, p, pr);
}
int main()
{
	int ans = INT_MAX;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> w[i] >> d[i];
	for(int i = n; i; i--) d[i] += d[i + 1];
	for(int i = 1; i <= n + 1; i++)
	{
		wd[i] = wd[i - 1] + w[i] * d[i];
		w[i] += w[i - 1];
	}
	solve(2, n, 1, n - 1);
	for(int i = 2; i <= n; i++)
		ans = min(ans, f[i] + cost(i + 1, n + 1));
	cout << ans;
	return 0;
}