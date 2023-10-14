#include<bits/stdc++.h>
using namespace std;
int n, m;
long long ans, a[500005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m; m--;
	for(int i = 1; i <= n; i++)	
		cin >> a[i];
	for(int i = n; i; i--)
		a[i] += a[i + 1];
	ans += a[1];
	sort(a + 2, a + n + 1);
	for(int i = n - m + 1; i <= n; i++)
		ans += a[i];
	cout << ans;
	return 0;
}