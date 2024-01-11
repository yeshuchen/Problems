#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
const double eps = 1e-15;
int n, c[N];
double p[N], a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n; int m = (1 << n);
	for(int i = 0; i < m; i++)
	{
		cin >> p[i];
		if(p[i] < eps) {cout << "INF"; return 0;}
	}
	for(int i = 0; i < m; i++) a[i] = p[i];
	for(int o = 2, k = 1; o <= m; o <<= 1, k <<= 1)
	{
		for(int i = 0; i < m; i += o)
			for(int j = 0; j < k; j++)
				a[i + j + k] += a[i + j];
	}
	for(int i = 1; i < m; i++)
		c[i] = c[i - (i & -i)] + 1;
	double ans = 0;
	for(int i = 1; i < m; i++)
	{
		int f;
		if(c[i] & 1) f = 1;
		else f = -1;
		ans = (ans + f * 1.0 / (1 - a[m - i - 1]));
		// cout << ans << ' ';
	}
	cout << fixed << setprecision(10) << ans;
	return 0;
}