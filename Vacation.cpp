#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005][3], f[100005][3];
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < 3; j++)
			for(int k = 0; k < 3; k++)
			{
				if(j == k) continue;
				f[i][j] = max(f[i][j], f[i - 1][k] + a[i][j]);
			}
	cout << max(f[n][0], max(f[n][1], f[n][2]));
	return 0;
}