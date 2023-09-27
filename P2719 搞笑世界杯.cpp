#include<bits/stdc++.h>
using namespace std;
int n;
double f[2505][2505];
int main()
{
	cin >> n; n /= 2;
	f[n][n] = 1;
	for(int i = n; i >= 0; i--)
		for(int j = n; j >= 0; j--)
		{
			if(!i && !j) continue;
			if(!i) f[i][j - 1] += f[i][j];
			if(!j) f[i - 1][j] += f[i][j];
			if(i && j)
			{
				f[i - 1][j] += 0.5 * f[i][j],
				f[i][j - 1] += 0.5 * f[i][j];
			}
		}
	cout << fixed << setprecision(4) << f[2][0] + f[0][2];
	return 0;
}