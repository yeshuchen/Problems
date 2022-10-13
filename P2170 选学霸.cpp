#include<bits/stdc++.h>
using namespace std;
int d[20005];
int f[20005], dp[55005];
inline int find(int k){return f[k] == k ? k : f[k] = find(f[k]);}
int n, m, k;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	if(k == 0)
	{
		cout << min(n, m);
		return 0;
	}
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= k; i++)
	{
		int x, y;
		cin >> x >> y;
		if(find(x) != find(y))
			f[find(x)] = find(y);
	}
	for(int i = 1; i <= n; i++)
	{
		int fx = find(i);
		d[fx]++;
	}
	dp[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		if(!d[i]) continue;
		int st = min(2 * m, n);
		for(int j = st; j >= d[i]; j--)
			dp[j] = max(dp[j], dp[j - d[i]]);
	}
	int minn = m, ans = 0;
	for(int i = 1; i <= 2 * m; i++)
		if(dp[i] && abs(i - m) < minn)
			minn = abs(i - m), ans = i;
	cout << ans;
	return 0;
}