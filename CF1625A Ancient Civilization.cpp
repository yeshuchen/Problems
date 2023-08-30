#include<bits/stdc++.h>
using namespace std;
int T, n, l;
int a[1005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int ans = 0;
		cin >> n >> l;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int k = 0; k < l; k++)
		{
			int cnt = 0;
			for(int i = 1; i <= n; i++)
				cnt += (bool)(a[i] & (1 << k));
			if(cnt > n - cnt) ans += (1 << k);
		}
		cout << ans << '\n';
	}
	return 0;
}