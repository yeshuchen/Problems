#include<bits/stdc++.h>
using namespace std;
int T;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		long long a, b, c, d, ans = 0;
		cin >> a >> b >> c >> d; a *= c;
		for(int y = 1; y < c * d; y++)
		{
			long long res = c * d - b * y;
			if(res <= 0) break;
			int down = y, up = res;
			int gcd = __gcd(down, up);
			down /= gcd; up /= gcd;
			if(up % a == 0 && (up % (down / a)) == 0 || a % up == 0)
				ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}