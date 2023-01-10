#include<bits/stdc++.h>
using namespace std;
long long n;
long long ans, w;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n; w = n * (n - 1);
	if(n == 1 || n == 2) {cout << n; return 0;}
	ans = max(ans, w * (n - 3) / __gcd(n - 3, w));
	if(n & 1) ans = max(ans, n * (n - 1) * (n - 2));
	else ans = max(ans, (n - 1) * (n - 2) * (n - 3));
	cout << ans;
	return 0;
}