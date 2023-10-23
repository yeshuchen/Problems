#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, res;
int p[N], f[N], g[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= 200000; i++)
	{
		if(i * (i - 1) / 2 > n) break;
		p[i] = i * (i - 1) / 2;
		res = i;
	}
	for(int i = 1; i <= n; i++)
	{
		f[i] = INT_MAX;
		for(int j = 2; j <= res; j++)	
		{
			if(p[j] > i) break;
			if(f[i - p[j]] + j < f[i]) f[i] = f[i - p[j]] + j, g[i] = g[i - p[j]] + j * f[i - p[j]];
			if(f[i - p[j]] + j == f[i]) g[i] = max(g[i], g[i - p[j]] + j * f[i - p[j]]);
		}
	}
	cout << f[n] << ' ' << g[n];
	return 0;
}