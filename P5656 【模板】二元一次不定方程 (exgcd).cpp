#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int x, y;
inline int exgcd(int a, int b)
{
	if(a % b == 0)
	{
		x = 0; y = 1;
		return b;
	}
	int gcd = exgcd(b, a % b);
	int z = x; x = y; y = z - a / b * y;
	return gcd;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int gcd = exgcd(a, b);
		if(c % gcd != 0)
		{
			cout << -1 << '\n';
			continue;
		}
		x *= c / gcd; y *= c / gcd;
		int A = a, B = b;
		b /= gcd; a /= gcd;
		int minx = (x % b + b) % b, miny = (y % a + a) % a;
		if(minx == 0) minx = b;
		if(miny == 0) miny = a;
		int maxx = (c - miny * B) / A, maxy = (c - minx * A) / B;
		if(maxy > 0)
			cout << (maxx - minx) / b + 1 << ' ' << minx << ' ' << miny << ' ' << maxx << ' ' << maxy << '\n';
		else
			cout << minx << ' ' << miny << '\n';
	}
	return 0;
}