#include<bits/stdc++.h>
using namespace std;
int T;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		long long n, rx, ans = 0;
		cin >> n;
		for(long long x = 1; x <= n; x = rx + 1)
		{
			rx = (n / (n / x) > n ? n : n / (n / x));
			ans += (rx - x + 1) * (n / x);
		}
		cout << ans << '\n';
	}
	return 0;
}