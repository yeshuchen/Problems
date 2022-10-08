#include<bits/stdc++.h>
#define int long long
using namespace std;
int X, Y;
inline int exgcd(int a, int b)
{
	if(a % b == 0)
	{
		X = 0; Y = 1;
		return b;
	}
	int gcd = exgcd(b, a % b);
	int z = X; X = Y; Y = z - Y * (a / b);
	return gcd;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int x, y, m, n, l;
	cin >> x >> y >> m >> n >> l;
	int a = n - m, b = l, c = x - y;
	if(a < 0) a = -a, c = -c;
	int gcd = exgcd(a, b);
	if(c % gcd != 0) cout << "Impossible";
	else cout << ((X * (c / gcd)) % (b / gcd) + (b / gcd)) % (b / gcd);
	return 0;
}