#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int a[N];
int n, c, ans;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], a[i] += a[i - 1];
	if(a[n] % 3 != 0) {cout << 0; return 0;}
	for(int i = 1; i < n; i++)
	{
		if(a[i] == a[n] / 3 * 2) ans += c;
		if(a[i] == a[n] / 3) c++;
	}
	cout << ans;
	return 0;
}