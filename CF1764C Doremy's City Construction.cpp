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
		long long ans = INT_MIN;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		for(int i = 2; i <= n; i++)
			if(a[i] != a[i - 1])
				ans = max(ans, 1ll * (i - 1) * (n - i + 1));
		if(ans == INT_MIN) ans = n / 2;
		cout << ans << '\n';
	}
	return 0;
}