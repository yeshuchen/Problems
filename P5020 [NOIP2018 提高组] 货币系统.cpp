#include<bits/stdc++.h>
using namespace std;
int T, a[105];
int f[25005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int n, ans = 0;
		memset(f, 0, sizeof(f));
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		f[0] = 1;
		for(int i = 1; i <= n; i++)
		{
			if(f[a[i]]) continue;
			ans++;
			for(int j = a[i]; j <= 25000; j++)
				f[j] = max(f[j], f[j - a[i]]);
		}
		cout << ans << '\n';
	}
	return 0;
}