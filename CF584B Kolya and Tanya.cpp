#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long n, c1 = 1, c2 = 1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		c1 = c1 * 27 % mod, c2 = c2 * 7 % mod;
	cout << ((c1 - c2) % mod + mod) % mod;
	return 0;
}