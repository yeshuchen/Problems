#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[15], dp[10005];
int spt[15] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++) cin >> a[i];
	sort(a + 1, a + m + 1);
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for(int i = 1; i <= m; i++)
		for(int j = spt[a[i]]; j <= n; j++)
			dp[j] = max(dp[j], dp[j - spt[a[i]]] + 1);
	int i = n;
	while(i)
	{
		for(int j = m; j; j--)
			if(i >= spt[a[j]] && dp[i - spt[a[j]]] + 1 == dp[i])
			{
				i -= spt[a[j]];
				cout << a[j];
				break;
			}
	}
	return 0;
}