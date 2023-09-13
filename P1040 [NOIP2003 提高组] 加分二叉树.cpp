#include<bits/stdc++.h>
#define int long long
const int N = 35;
using namespace std;
int n, v[N];
int dp[N][N], pos[N][N], ls[N][N], rs[N][N];
inline void print(int l, int r)
{
	cout << pos[l][r] << ' ';
	if(ls[l][r]) print(l, pos[l][r] - 1);
	if(rs[l][r]) print(pos[l][r] + 1, r);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> v[i];
	for(int i = 1; i <= n; i++) dp[i][i] = v[i], pos[i][i] = i;
	for(int len = 2; len <= n; len++)
		for(int i = 1; i + len - 1 <= n; i++)
		{
			int j = i + len - 1;
			for(int k = i; k <= j; k++)
			{
				int res = max(dp[i][k - 1], 1ll) * max(dp[k + 1][j], 1ll) + v[k];
				if(dp[i][j] < res) pos[i][j] = k, ls[i][j] = pos[i][k - 1], rs[i][j] = pos[k + 1][j], dp[i][j] = res;
			}
		}
	cout << dp[1][n] << '\n';
	print(1, n);
	return 0;
}