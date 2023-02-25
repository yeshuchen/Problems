#include<bits/stdc++.h>
using namespace std;
int n, s, cnt;
double a[80][80];
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n + 1; j++)
			cin >> a[i][j];
	int nowline;
	for(int i = 1, pos = 1; i <= n; i++)
	{
		int maxn = pos;
		for(int j = pos + 1; j <= n; j++)
			if(fabs(a[j][i]) > fabs(a[maxn][i]))
				maxn = j;
		if(!a[maxn][i]) continue;
		for(int j = 1; j <= n + 1; j++)
			swap(a[pos][j], a[maxn][j]);
		for(int j = 1; j <= n; j++)
		{
			if(j == pos) continue;
			double temp = a[j][i] / a[pos][i]; 
			for(int k = i; k <= n + 1; k++)
				a[j][k] -= temp * a[pos][k];
		}
		nowline = ++pos;
	}
	if(nowline <= n)
	{
		for(int i = nowline; i <= n; i++)
			if(a[i][n + 1])
			{
				cout << -1;
				return 0;
			}
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= n; i++)
		printf("x%d=%.2lf\n", i, (a[i][n + 1] == 0 ? 0 : a[i][n + 1] / a[i][i]));
	return 0;
}