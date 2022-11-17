#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long b[5005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	long long ans = LONG_LONG_MAX;
	for(int i = 1; i <= n; i++)
	{
		long long res = 0;
		memset(b, 0, sizeof(b));
		for(int j = i - 1; j >= 1; j--)
			b[j] += (b[j + 1] / a[j] + 1) * a[j], res += (b[j + 1] / a[j] + 1);
		for(int j = i + 1; j <= n; j++)
			b[j] += (b[j - 1] / a[j] + 1) * a[j], res += (b[j - 1] / a[j] + 1);
		ans = min(ans, res);
	}
	cout << ans;
	return 0;
}