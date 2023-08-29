#include<bits/stdc++.h>
#define int long long
using namespace std;
int T, m, k, a1, ak;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> m >> k >> a1 >> ak;
		int maxv = k * ak, nd;
		maxv = min(maxv, m / k * k);
		nd = m - maxv;
		if(a1 > nd) {cout << 0 << '\n'; continue;}
		if(a1 <= nd % k)
			cout << nd / k + (nd % k - a1) << '\n';
		else
		{
			nd -= a1;
			if(nd % k == 0) cout << nd / k << '\n';
			else cout << nd / k + 1 << '\n';
		}
	}
	return 0;
}