#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n, a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		int ans = 0, cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			if(a[i] != a[i - 1]) ans = max(ans, cnt), cnt = 0;
			cnt++;
		}
		ans = max(ans, cnt);
		int res = n - ans;
		while(ans < n)
			ans *= 2, res++;
		cout << res << '\n';
	}
	return 0;
}