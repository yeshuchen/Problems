#include<bits/stdc++.h>
#define int __int128
using namespace std;
int x, y;
long long n, a[200005], b[200005];
inline int exgcd(int a, int b)
{
	if(a % b == 0)
	{
		x = 0, y = 1;
		return b;
	}
	int gcd = exgcd(b, a % b);
	int z = x;
	x = y;
	y = z - y * (a / b);
	return gcd;
}
inline void write(int x)
{
	if(x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
signed main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> b[i];
	int m = a[1];
	int ans = b[1] % a[1];
	for(int i = 2; i <= n; i++)
	{
		int gcd = exgcd(m, a[i]);
		int t = m; m = m / gcd * a[i];
		ans += t * x % m * (b[i] - ans) / gcd;
		ans %= m;
	}
	write((ans % m + m)% m);
    return 0;
}