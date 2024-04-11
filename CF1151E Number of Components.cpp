#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n, a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n; long long ans = 0;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) ans += 1ll * a[i] * (n - a[i] + 1);
	for(int i = 1; i < n; i++) ans -= 1ll * min(a[i], a[i + 1]) * (n - max(a[i], a[i + 1]) + 1);
	cout << ans << '\n';
	return 0;
}