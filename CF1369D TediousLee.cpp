#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int T, n, f[2000005];
int main()
{
	cin >> T; f[3] = 4;
	for(int i = 4; i <= 2000000; i++) f[i] = (2ll * f[i - 2] + f[i - 1] + (i % 3 == 0) * 4) % mod;
	while(T--)
	{
		cin >> n;
		cout << f[n] << '\n';
	}
	return 0;
}