#include<bits/stdc++.h>
using namespace std;
double p[20][20], a[20][20];
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n + 1; i++)
		for(int j = 1; j <= n; j++)
			cin >> p[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			a[i][j] = 2 * (p[i][j] - p[i + 1][j]), a[i][n + 1] += p[i][j] * p[i][j] - p[i + 1][j] * p[i + 1][j];
	for(int i = 1; i <= n; i++)
	{
		int max = i;
		for(int j = i + 1; j <= n; j++)
			if(fabs(a[j][i]) > fabs(a[max][i]))
				max = j;		
		for(int j = i; j <= n + 1; j++)
			swap(a[i][j], a[max][j]);
		for(int j = 1; j <= n; j++)
		{
			if(j == i) continue;
			double temp = a[j][i] / a[i][i];
			for(int k = i; k <= n + 1; k++)
				a[j][k] -= temp * a[i][k];
		}
	}
	for(int i = 1; i <= n; i++)
		printf("%.3lf ", a[i][n + 1] / a[i][i]);
	return 0;
} 