#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, k;
int dp[3005][3005];
inline int solve(int i, int j)
{
	if(i < j || !j) return 0;
	if(dp[i][j]) return dp[i][j];
	return (dp[i][j] = (solve(i - 1, j - 1) + solve(i, j * 2)) % mod);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) dp[i][i] = 1;
	cout << solve(n, k);
	return 0;
}