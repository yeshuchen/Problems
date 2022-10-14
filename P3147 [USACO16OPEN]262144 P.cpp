#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, ans;
int f[61][N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int val;
		cin >> val;
		f[val][i] = i + 1;
	}
	for(int i = 1; i <= 60; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(f[i - 1][j]) f[i][j] = f[i - 1][f[i - 1][j]];
			if(f[i][j]) ans = max(ans, i);
		}
	}
	cout << ans;
	return 0;
}