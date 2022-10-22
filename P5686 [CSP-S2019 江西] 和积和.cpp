#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, mod = 1e9 + 7;
int n;
long long x[N], y[N];
long long sumx, sumy;
long long sum, ans[N];
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> x[i];
	for(int i = 1; i <= n; i++) cin >> y[i];
	for(int i = 1; i <= n; i++)
	{
		ans[i] = (ans[i - 1] + x[i] * sumy % mod + y[i] * sumx % mod + i * x[i] % mod * y[i] % mod) % mod;
		sum += ans[i]; sum %= mod;
		sumx += i * x[i], sumy += i * y[i];
		sumx %= mod; sumy %= mod;
	}
	cout << sum;
	return 0;
}