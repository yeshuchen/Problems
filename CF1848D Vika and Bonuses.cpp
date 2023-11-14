#include<bits/stdc++.h>
#define int long long
using namespace std;
int T, s, k;
int g(int x) {return (s + x * 20) * (k - 4 * x);}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> s >> k;
		if(s % 10 == 0) {cout << s * k << '\n'; continue;}
		if(s % 10 == 5) {cout << max((s + 5) * (k - 1), s * k) << '\n'; continue;}
		int ans = s * k;
		s += s % 10; k--;
		int l = 1, r = k / 4, pos = 0;
		while(l <= r)
		{
			int mid = l + r >> 1;
			if(g(mid) >= g(mid - 1)) l = (pos = mid) + 1;
			else r = mid - 1;
			ans = max({ans, g(mid), g(mid - 1)});
		}
		for(int i = 0; i <= 3; i++)
		{
			ans = max(ans, (s + pos * 20) * (k - 4 * pos - i));
			if(pos) ans = max(ans, (s + (pos - 1) * 20) * (k - 4 * pos - i + 4));
			s += (s % 10);
		}
		cout << ans << '\n';
	}
	return 0;
}