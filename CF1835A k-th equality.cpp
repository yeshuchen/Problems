#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		bool flag = 0;
		int a, b, c, k;
		cin >> a >> b >> c >> k;
		if(max(a, b) > c) {cout << -1 << '\n'; continue;}
		int amin = pow(10, a - 1), amax = pow(10, a) - 1;
		int bmin = pow(10, b - 1), bmax = pow(10, b) - 1;
		int cmin = pow(10, c - 1), cmax = pow(10, c) - 1;
		if(amin + bmin > cmax) {cout << -1 << '\n'; continue;}
		for(int i = amin; i <= amax; i++)
		{
			int l, r;
			l = max(cmin, i + bmin);
			r = min(cmax, i + bmax);
			if(l > r) continue;
			if(k <= r - l + 1) {cout << i << " + " << l - i + k - 1 << " = " << l + k - 1 << '\n'; flag = 1; break;}
			else k -= (r - l + 1);
		}
		if(!flag) cout << -1 << '\n';
	}
	return 0;
}