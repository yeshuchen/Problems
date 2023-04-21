#include<bits/stdc++.h>
using namespace std;
int n, m, x;
int a[2005], b[2005];
int d[4000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i], a[i] += a[i - 1];
	for(int i = 1; i <= m; i++)
		cin >> b[i], b[i] += b[i - 1];
	cin >> x;
	for(int len = m; len; len--)
	{
		int k = INT_MAX;
		for(int i = 1; i + len - 1 <= m; i++)
			k = min(k, b[i + len - 1] - b[i - 1]);
		d[k] = len;
	}
	for(int i = 1; i <= 4000000; i++)
	{
		if(d[i]) continue;
		d[i] = d[i - 1];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j++)
			ans = max(ans, (j - i + 1) * d[min(x / (a[j] - a[i - 1]), 4000000)]); 
	cout << ans;
	return 0;

}