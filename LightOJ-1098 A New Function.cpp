#include<bits/stdc++.h>
using namespace std;
int T;
long long n;
int main()
{
	cin >> T;
	for(int c = 1; c <= T; c++)
	{
		scanf("%lld", &n);
		if(n == 0) {cout << "Case " << c << ": " << 0 << '\n'; continue;}
		long long ans = 0, w = sqrt(n);
		for(long long i = 2; i <= w; i++)
		{
			long long p = n / i;
			ans += (p - 1) * i;
			long long q = p;
			p = w + 1;
			if(q < p) continue;
			ans += (q - p + 1) * (p + q) / 2;
		}
		printf("Case %d: %lld\n", c, ans);
	}
	return 0;
}