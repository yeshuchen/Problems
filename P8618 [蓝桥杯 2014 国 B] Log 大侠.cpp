#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int maxn[200005], sum[200005];
int a[200005], bl[200005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int size = sqrt(n);
	for(int i = 1; i <= n; i++)
		cin >> a[i], bl[i] = (i - 1) / size + 1;
	for(int i = 1; i <= n; i++)
		maxn[bl[i]] = max(maxn[bl[i]], a[i]), sum[bl[i]] += a[i];
	while(m--)
	{
		int l, r, ans = 0;
		cin >> l >> r;
		int pos = bl[l];
		if(bl[l] == bl[r])
		{
			for(int i = l; i <= r; i++)
				a[i] = log2(a[i]) + 1;
			maxn[pos] = sum[pos] = 0;
			for(int i = (pos - 1) * size + 1; i <= pos * size; i++)
				maxn[pos] = max(maxn[pos], a[i]), sum[pos] += a[i];
			for(int i = 1; i <= bl[n]; i++)
				ans += sum[i];
			cout << ans << '\n';
			continue;
		}
		if(maxn[pos] > 2)
		{
			maxn[pos] = sum[pos] = 0;
			for(int i = l; i <= pos * size; i++)
				a[i] = log2(a[i]) + 1;
			for(int i = (pos - 1) * size + 1; i <= pos * size; i++)
				maxn[pos] = max(maxn[pos], a[i]), sum[pos] += a[i];
		}
		for(int i = pos + 1; i < bl[r]; i++)
		{
			if(maxn[i] > 2)
			{
				maxn[i] = sum[i] = 0;
				for(int j = (i - 1) * size + 1; j <= i * size; j++)
					a[j] = log2(a[j]) + 1;
				for(int j = (i - 1) * size + 1; j <= i * size; j++)
					maxn[i] = max(maxn[i], a[j]), sum[i] += a[j];
			}
		}
		if(maxn[bl[r]] > 2)
		{
			maxn[bl[r]] = sum[bl[r]] = 0;
			for(int i =	(bl[r] - 1) * size + 1; i <= r; i++)
				a[i] = log2(a[i]) + 1;
			for(int i = (bl[r] - 1) * size + 1; i <= bl[r] * size; i++)
				maxn[bl[i]] = max(maxn[bl[i]], a[i]), sum[bl[i]] += a[i];
		}
		for(int i = 1; i <= bl[n]; i++)
			ans += sum[i];
		cout << ans << '\n';
	}
	return 0;
}