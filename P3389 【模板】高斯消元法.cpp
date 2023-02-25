#include<bits/stdc++.h>
using namespace std;
int n;
double a[205][205];
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n + 1; j++)
			cin >> a[i][j];
	for(int i = 1; i <= n; i++)
	{
		int max = i;
		for(int j = i + 1; j <= n; j++)
			if(fabs(a[j][i]) > fabs(a[max][i]))
				max = j;
		for(int j = 1; j <= n + 1; j++)
			swap(a[i][j], a[max][j]);
		if(!a[i][i])
		{
			cout << "No Solution";
			return 0;
		}
		for(int j = 1; j <= n; j++)
		{
			if(j == i) continue;
			double t = a[j][i] / a[i][i];
			for(int k = i + 1; k <= n + 1; k++)
				a[j][k] -= t * a[i][k];
		}
	}
	for(int i = 1; i <= n; i++)
		printf("%.2lf\n", a[i][n + 1] / a[i][i]);
	return 0;
}