#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, k;
int a[1000005], sum[1000005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = k + 1; i <= n; i++)
		a[i] += a[i - k];
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i], cout << sum[i] << ' ';
	return 0;
}