#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
int T;
char s[1000005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> s + 1;
		int ans = 1, res = 0, cnt = 0;
		int len = strlen(s + 1);
		for(int i = 1; i <= len; i++)
		{
			cnt++;
			if(i == len || s[i] != s[i + 1])
			{
				ans = ans * cnt % mod;
				res += cnt - 1;
				cnt = 0;
			}
		}
		for(int i = 1; i <= res; i++) ans = ans * i % mod;
		cout << res << ' ' << ans << '\n';
	}
	return 0;
}