#include<bits/stdc++.h>
using namespace std;
int dp[40000][5];
int main()
{
	dp[0][0] = 1;
	for(int i = 1; i * i <= 32768; i++)
		for(int j = i * i; j <= 32768; j++)
			for(int k = 1; k <= 4; k++)
				dp[j][k] += dp[j - i * i][k - 1];
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4] << '\n';
	}
	return 0;
}