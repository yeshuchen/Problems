#include<bits/stdc++.h>
using namespace std;
int n;
unsigned ans;
int a[5005], s[5005][5005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			s[a[j]][a[i]] += a[i] / a[j];
	for(int i = 1; i <= 5000; i++)
		for(int j = 1; j <= 5000; j++)
			s[i][j] += s[i][j - 1];
	for(int i = 2; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			for(int l = a[j]; l <= 5000; l += a[j])
			{
				int r = min(l + a[j] - 1, 5000), k = l / a[j];
				ans += k * (s[a[i]][r] - s[a[i]][l - 1]) * (a[i] / a[j]);
			}
	cout << ans;
	return 0;
}