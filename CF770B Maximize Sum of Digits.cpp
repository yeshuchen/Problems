#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int solve(int x)
{
	int res = 0;
	while(x) res += x % 10, x /= 10;
	return res;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int ans = solve(n), res = n;
	for(int i = 10; i <= n; i *= 10)
	{
		int tmp = n / i * i - 1;
		int val = solve(tmp);
		if(val > ans) ans = val, res = tmp;
	}
	cout << res;
	return 0;
}