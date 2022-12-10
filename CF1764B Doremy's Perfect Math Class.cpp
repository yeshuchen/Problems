#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int T, n, a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int gcd = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i], gcd = __gcd(gcd, a[i]);
		cout << a[n] / gcd << '\n';
		here:;
	}
	return 0;
}