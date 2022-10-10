#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int n, m, k;
char s[1005], t[1005];
int f[1005][205][2];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i <= n; i++)
		f[i][0][0] = 1;
	for(int i = 1; i <= n; i++) cin >> s[i];
	for(int i = 1; i <= m; i++) cin >> t[i];
	for(int l = 1; l <= k; l++)
	{
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
			{
				if(i < j) continue;
				f[i][j][1] = f[i - 1][j][1];
				for(int p = j; p; p--)
				{
					if(s[i - j + p] != t[p]) break;
					f[i][j][1] += f[i - j + p - 1][p - 1][0];
					f[i][j][1] %= mod;
				}
			}
		for(int i = 0; i <= n; i++)
			for(int j = 0; j <= m; j++)
				f[i][j][0] = f[i][j][1];
	}
	cout << f[n][m][0] % mod;
	return 0;
}
/*
显然，有方程
s[i] == t[j] s[i - 1][j] + 1; 能与一整个子串匹配时
s[i] != t[j] s[i - 1][j];
考虑从此向多个子串递推，如果我能匹配到前面这么多位
*/