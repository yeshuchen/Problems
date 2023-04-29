#include<bits/stdc++.h>
using namespace std;
int T, n, m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		if(__gcd(n, m) == 1) {cout << 1 << '\n' << n << ' ' << m << '\n'; continue;}
		else
		{
			cout << 2 << '\n';
			cout << 1 << ' ' << m - 1 << '\n';
			cout << n << ' ' << m << '\n';
		}
	}
	return 0;
}