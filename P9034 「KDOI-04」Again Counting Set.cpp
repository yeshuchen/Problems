#include<bits/stdc++.h>
#define int long long
int T, n, k;
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int ans = 0;
		cin >> n >> k;
		if(k == 2) {cout << 1 << '\n'; continue;}
		if(n == 1)
		{
			if(k >= 4) cout << 1 << '\n';
			else cout << 0 << '\n';
			continue;
		}
		if(n == 2)
		{
			if(k >= 5) cout << 3 << '\n';
			else if(k == 4) cout << 2 << '\n';
			else cout << 0 << '\n';
			continue;
		}
		if(k == 2) ans = 1;
		if(k >= 4) ans += 2 * n - 3;
		if(k >= 5) ans += 2;
		cout << ans << '\n';
	}
	return 0;
}