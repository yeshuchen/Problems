#include<bits/stdc++.h>
#define int long long
using namespace std;
int T, n, k, g;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n >> k >> g;
		int tot = k * g, spend = 0;
		tot -= (g - 1 >> 1) * (n - 1);
		spend = tot / g * g;
		if(tot % g >= (g + 1) / 2) spend += g;
		cout << k * g - max(spend, 0ll) << '\n';	
	}
	return 0;
}