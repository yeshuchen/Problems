#include<bits/stdc++.h>
using namespace std;
int T, n;
int a[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + n + 1);
		for(int i = 1; i < n - 1; i++) ans = max(ans, a[n] + a[i + 1] - 2 * a[i]);
		for(int i = n; i > 2; i--) ans = max(ans, 2 * a[i] - a[i - 1] - a[1]);
		cout << ans << '\n';
	}
	return 0;
}