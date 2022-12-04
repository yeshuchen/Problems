#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int T, n, x, y;
char c1[N], c2[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int ans = 0, res = 0;
		int p1 = 0, p2 = 0, f = 0;
		cin >> n >> x >> y;
		for(int i = 1; i <= n; i++)
			cin >> c1[i], p1 += (c1[i] & 1);
		for(int i = 1; i <= n; i++)
			cin >> c2[i], p2 += (c2[i] & 1);
		if(p1 % 2 != p2 % 2) {cout << -1 << '\n'; continue;}
		for(int i = 1; i <= n; i++)
			if(c1[i] != c2[i])
			{
				if(i < n && c1[i + 1] != c2[i + 1]) f = 1;
				res++;
			}
		if(res == 2 && f == 1) cout << min(x, 2 * y) << '\n';
		else cout << res / 2 * y << '\n';
	}
	return 0;
}