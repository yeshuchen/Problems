#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 605;
int n, mod;
ll a[N][N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> mod;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> a[i][j], a[i][j] %= mod;
	bool flag = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			while(a[i][i])
			{
				ll q = a[j][i] / a[i][i];
				for(int k = i; k <= n; k++) a[j][k] = ((a[j][k] - q * a[i][k]) % mod + mod) % mod;
				swap(a[i], a[j]); flag ^= 1;
			}
			swap(a[i], a[j]); flag ^= 1;
		}
	}
	ll ans = 1;
	for(int i = 1; i <= n; i++) ans = ans * a[i][i] % mod;
	cout << (flag ? (mod - ans) % mod : ans);
	return 0;
}