#include<bits/stdc++.h>
using namespace std;
int n, k, T;
int a[505], d[505];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int ans = 0;
		cin >> n >> k; k--;
		for(int i = 1; i <= n; i++)
			cin >> a[i], d[i] = abs(a[i] - a[i - 1]), ans += d[i];
		ans -= d[1];
		sort(d + 2, d + n + 1);
		for(int i = n; i && k; i--, k--)
			ans -= d[i];
		cout << ans << '\n';
	}
	return 0;
}