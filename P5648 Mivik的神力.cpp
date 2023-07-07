#include<bits/stdc++.h>
using namespace std;
int n, m;
long long a[1000005];
long long f[500005][20], sum[500005][20];
stack<int> s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		while(!s.empty() && a[s.top()] < a[i])
		{
			f[s.top()][0] = i;
			sum[s.top()][0] = (i - s.top()) * a[s.top()];
			s.pop();
		}
		s.push(i);
	}
	for(int j = 1; j < 20; j++)
		for(int i = 1; i <= n; i++)
		{
			f[i][j] = f[f[i][j - 1]][j - 1];
			sum[i][j] = sum[i][j - 1] + sum[f[i][j - 1]][j - 1];
		}
	long long lastans = 0;
	for(int i = 1; i <= m; i++)
	{
		long long ans = 0;
		int u, v, l, r;
		cin >> u >> v;
		l = 1 + (u ^ lastans) % n, r = 1 + (v ^ (lastans + 1)) % (n - l + 1);
		r = l + r;
		for(int j = 19; j >= 0; j--)
		{
			if(f[l][j] <= r && f[l][j])
				ans += sum[l][j], l = f[l][j];
		}
		ans += a[l] * (r - l);
		lastans = ans;
		cout << ans << '\n';
	}
	return 0;
}