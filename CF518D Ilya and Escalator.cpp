#include<bits/stdc++.h>
using namespace std;
int n, t;
double f[2005][2005];
double p[10005], ans;
int main()
{
	cin >> n >> p[1] >> t;
	f[0][0] = 1;
	for(int i = 1; i <= t; i++)
		for(int j = 0; j <= min(i, n); j++)
		{
			if(j == n) f[i][j] += f[i - 1][j];
			else f[i][j] += f[i - 1][j] * (1 - p[1]);
			if(j > 0) f[i][j] += f[i - 1][j - 1] * p[1];
		}
	for(int i = 1; i <= n; i++)
		ans += i * f[t][i];
	printf("%.10lf", ans);
	return 0;
}