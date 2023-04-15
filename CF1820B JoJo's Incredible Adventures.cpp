#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
char s[800005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int cnt = 0;
		int ans = 0;
		cin >> s + 1;
		int n = strlen(s + 1);
		for(int i = n + 1; i <= 2 * n; i++)
			s[i] = s[i - n];
		n <<= 1;
		for(int i = 1; i <= n; i++)
		{
			if(s[i] == '0') ans = max(ans, cnt), cnt = 0;
			else cnt++;
		}
		ans = max(ans, cnt);
		cnt = min(ans, n / 2);
		ans = 0;
		if(cnt == n / 2) {cout << cnt * cnt << '\n'; continue;}
		for(int i = 1; i <= cnt; i++)
			ans = max(ans, i * (cnt - i + 1));
		cout << ans << '\n';
	}
	return 0;
}