#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, k;
char a[4005][4005];
int f[4005], l[4005], r[4005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while(cin >> n >> m)
	{
		if(!n && !m) break;
		cin >> k; int ans = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				cin >> a[i][j], f[j] = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if(a[i][j] == 'C') f[j] = 0;
				else f[j]++;
			}
			stack<int> s;
			for(int j = 1; j <= m; j++)
			{
				while(!s.empty() && f[s.top()] > f[j]) r[s.top()] = j - 1, s.pop();
				s.push(j);
			}
			while(!s.empty()) r[s.top()] = m, s.pop();
			for(int j = m; j; j--)
			{
				while(!s.empty() && f[s.top()] > f[j]) l[s.top()] = j + 1, s.pop();
				s.push(j);
			}
			while(!s.empty()) l[s.top()] = 1, s.pop();
			for(int j = 1; j <= m; j++) ans = max(ans, f[j] * (r[j] - l[j] + 1));
		}
		cout << ans * k << '\n';
	}
	return 0;
}