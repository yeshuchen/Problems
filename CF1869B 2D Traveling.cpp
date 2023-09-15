#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int T, n, m, s, t;
int x[N], y[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n >> m >> s >> t;
		for(int i = 1; i <= n; i++)
			cin >> x[i] >> y[i];
		int dis1 = 2e18, dis2 = 2e18;
		for(int i = 1; i <= m; i++)
		{
			dis1 = min(dis1, abs(x[s] - x[i]) + abs(y[s] - y[i]));
			dis2 = min(dis2, abs(x[t] - x[i]) + abs(y[t] - y[i]));
		}
		cout << min(dis1 + dis2, abs(x[s] - x[t]) + abs(y[s] - y[t])) << '\n';
	}
	return 0;
}