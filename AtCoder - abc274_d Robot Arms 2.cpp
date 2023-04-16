#include<bits/stdc++.h>
using namespace std;
int n, x, y;
int a[2005], sum[2], f[2][10005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> x >> y;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i & 1] += a[i];
	}
	f[0][0] = f[1][a[1]] = 1;
	for(int i = 2; i <= n; i++)
		for(int k = 10000; k >= a[i]; k--)
			f[i & 1][k] |= f[i & 1][k - a[i]];
	bool f1 = 0, f2 = 0;
	for(int i = 0; i <= 10000; i++)
	{
		if(f[0][i] && 2 * i - sum[0] == y) f2 = 1;
		if(f[1][i] && 2 * i - sum[1] == x) f1 = 1;
	}
	if(!f1 || !f2) cout << "No";
	else cout << "Yes";
	return 0;
}