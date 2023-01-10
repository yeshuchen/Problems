#include<bits/stdc++.h>
using namespace std;
int n, m, tot, tra, mid;
int a[55], b[2005], sum[2005];
inline bool dfs(int p, int step)
{
	if(tot - tra < sum[mid]) return 0;
	if(!p) return 1;
	bool f = 0;
	for(int i = step; i <= n; i++)
		if(a[i] >= b[p])
		{
			a[i] -= b[p];
			if(a[i] < b[1]) tra += a[i];
			if(b[p - 1] == b[p]) f = dfs(p - 1, step);
			else f = dfs(p - 1, 1);
			if(a[i] < b[1]) tra -= a[i];
			a[i] += b[p];
			if(f) return 1;
		}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], tot += a[i];
	cin >> m;
	for(int i = 1; i <= m; i++) cin >> b[i];
	sort(b + 1, b + m + 1);
	for(int i = 1; i <= m; i++) sum[i] = sum[i - 1] + b[i];
	while(sum[m] > tot) m--;
	int l = 0, r = m;
	while(l <= r)
	{
		mid = l + r >> 1;
		if(dfs(mid, 1)) l = mid + 1;
		else r = mid - 1;
	}
	cout << l - 1;
	return 0;
}