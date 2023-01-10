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
		int ans = INT_MAX, sum = 0;
		cin >> n;
		for(int i = 1, v; i <= n; i++)
		{
			int cnt = 0;
			cin >> v; sum += v;
			bool f = v % 2;
			while(v % 2 == f)
				v /= 2, cnt++;
			ans = min(ans, cnt);
		}
		if(sum % 2 == 0) ans = 0;
		cout << ans << '\n';
	}
	return 0;
}