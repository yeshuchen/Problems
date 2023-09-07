#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n;
int a[N], f[N], val[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i], a[i] += a[i - 1], f[i] = 2e9;
	for(int i = 1; i <= n; i++)
		for(int j = i - 1; j >= 0; j--)
			if(a[i] - a[j] >= val[j] && f[i] > f[j] + 1)
			{
				f[i] = f[j] + 1;
				val[i] = a[i] - a[j];
				break;
			}
	cout << n - f[n];
	return 0;
}