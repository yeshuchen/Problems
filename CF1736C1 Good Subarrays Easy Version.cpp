#include<bits/stdc++.h>
using namespace std;
int T, n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int now = 1;
		long long ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			int val;
			cin >> val;
			now = max(now, i + 1 - val);
			ans += i - now + 1;
		}
		cout << ans << '\n';
	}
	return 0;
}