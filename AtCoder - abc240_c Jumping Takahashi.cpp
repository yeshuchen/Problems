#include<bits/stdc++.h>
using namespace std;
int n, x, sum;
int dp[50005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> x; dp[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		if(a < b) swap(a, b);
		sum += b;
		for(int j = x; j >= a - b; j--)
			dp[j] |= dp[j - (a - b)];
	}
	if(x < sum) {cout << "No"; return 0;}
	cout << (dp[x - sum] ? "Yes" : "No");
	return 0;
}