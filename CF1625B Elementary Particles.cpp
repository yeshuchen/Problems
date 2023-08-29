#include<bits/stdc++.h>
using namespace std;
int T, n, a[300005], p[300005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if(p[a[i]]) ans = max(ans, p[a[i]] + n - i);
			p[a[i]] = i;
		}
		for(int i = 1; i <= n; i++) p[a[i]] = 0;
		if(!ans) ans = -1;
		cout << ans << '\n';
	}
	return 0;
}