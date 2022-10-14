#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n, m;
int dp[500005];
int v[65], p[65], q[65];
vector<int> g[75];
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> v[i] >> p[i] >> q[i];
		if(!q[i]) g[i].insert(g[i].begin(), i);
		else g[q[i]].push_back(i);
	}
	for(int i = 1; i <= m; i++)
	{
		int temp[7], tw[7];
		if(g[i].empty()) continue;
		int num = pow(2, g[i].size() - 1);
		if(g[i].size() >= 1) temp[1] = v[g[i][0]], tw[1] = v[g[i][0]] * p[g[i][0]];
		if(g[i].size() >= 2) temp[2] = v[g[i][0]] + v[g[i][1]], tw[2] = v[g[i][0]] * p[g[i][0]] + v[g[i][1]] * p[g[i][1]];
		if(g[i].size() == 3) temp[3] = v[g[i][0]] + v[g[i][2]], temp[4] = v[g[i][0]] + v[g[i][1]] + v[g[i][2]], tw[3] = v[g[i][0]] * p[g[i][0]] + v[g[i][2]] * p[g[i][2]], tw[4] = v[g[i][0]] * p[g[i][0]] + v[g[i][1]] * p[g[i][1]] + v[g[i][2]] * p[g[i][2]];
		for(int j = n; j; j--)
		{
			for(int k = 1; k <= num; k++)
			{
				if(temp[k] > j) continue;
				dp[j] = max(dp[j], dp[j - temp[k]] + tw[k]);
			}
		}
	}
	cout << dp[n];
	return 0;
}