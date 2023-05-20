#include<bits/stdc++.h>
#define int long long
const int N = 3e5 + 5;
using namespace std;
int n, q, x, y;
int aa[N], bb[N], f[N];
inline int exgcd(int a, int b)
{
	if(a % b == 0) {x = 0, y = 1; return b;}
	int gcd = exgcd(b, a % b);
	int t = x;
	x = y; y = t - a / b * y;
	return gcd;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> aa[i] >> bb[i]; aa[i] = aa[i] - bb[i];
		f[0] += bb[i];
	}
	sort(aa + 1, aa + n + 1);
	for(int i = n; i; i--)
		f[n - i + 1] = f[n - i] + aa[i];
	int mx = 0;
	for(int i = 1; i <= n; i++)
		if(f[i] > f[mx]) mx = i;
	cin >> q;
	while(q--)
	{
		int a, b;
		cin >> a >> b;
		int gcd = exgcd(a, b);
		if(n % gcd != 0) {cout << -1 << '\n'; continue;}
		int lcm = a * b / gcd; x = x * (n / gcd), y = y * (n / gcd);
		int xmin = (x % (b / gcd) + b / gcd) % (b / gcd);
		int ymax = (n - xmin * a) / b;
		int ymin = (y % (a / gcd) + a / gcd) % (a / gcd);
		int xmax = (n - ymin * b) / a;
		if(ymax < 0) {cout << -1 << '\n'; continue;}
		if(xmax * a <= mx) cout << f[xmax * a] << '\n';
		else if(xmin * a >= mx) cout << f[xmin * a] << '\n';
		else
		{
			int l = xmin * a + (mx - xmin * a) / lcm * lcm;
			int r = l + lcm;
			cout << max(f[l], f[r]) << '\n';
		}
	}
	return 0;
}