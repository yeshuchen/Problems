#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
int n;
int a[100005];
ll dp[1000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	dp[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		vector<int> g;
		for(int j = 1; j * j <= a[i]; j++)
		{
			if(a[i] % j == 0)
			{
				int x1 = j, x2 = a[i] / j;
				g.push_back(x1);
				if(x1 == x2) continue;
				g.push_back(x2);
			}
		}
		sort(g.begin(), g.end());	
		for(int j = g.size() - 1; j >= 0; j--) dp[g[j]] = (dp[g[j]] + dp[g[j] - 1]) % mod;
	}
	ll ans = 0;
	for(int i = 1; i <= 1000000; i++)
		ans = (ans + dp[i]) % mod;
	cout << ans;
	return 0;
}