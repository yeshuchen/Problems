#include<bits/stdc++.h>
using namespace std;
int n, p, maxn;
int v[15];
int dp[1000005];
int pos[1000005];
int main()
{
	cin >> n;
	for(int i = 1; i <= 9; i++) cin >> v[i];
	for(int i = 1; i <= 9; i++)
		for(int j = v[i]; j <= n; j++)
		{
			if(dp[j - v[i]] + 1 >= dp[j])
			{
				dp[j] = dp[j - v[i]] + 1;
				pos[j] = i;
			}
		}
	if(!dp[n]) {cout << -1; return 0;}
	int id = n;
	for(int i = 1; i <= dp[n]; i++)
	{
		cout << pos[id];
		id = id - v[pos[id]];
	}
}