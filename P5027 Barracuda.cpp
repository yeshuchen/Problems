#include<bits/stdc++.h>
using namespace std;
int n;
double c[205], p[205][205], a[205][205];
inline int guass(int x)
{
	for(int i = 1; i <= n; i++)
	{
		int max = i;
		for(int j = i; j <= n; j++)
			if(fabs(a[j][i]) > fabs(a[max][i]))
				max = j;
		if(!a[max][i])
			return 0;
		for(int j = i; j <= n + 1; j++)
			swap(a[i][j], a[max][j]);
		for(int j = 1; j <= n; j++)
		{
			if(j == i) continue;
			double t = a[j][i] / a[i][i];
			for(int k = i; k <= n + 1; k++)
				a[j][k] -= t * a[i][k];
		}
	}
	double maxn = 0;
	int cnt = 0, pos;
	for(int i = 1; i <= n; i++)
	{
		double x = a[i][n + 1] / a[i][i];
		if(x <= 0 || floor(x) != x) return 0;
		maxn = max(maxn, a[i][n + 1] / a[i][i]);
	}
	for(int i = 1; i <= n; i++)
		if(maxn == a[i][n + 1] / a[i][i])
			pos = i, cnt++;
	if(cnt > 1) return 0;
	return pos;
}
int main()
{
	cin >> n;
	for(int i = 1; i <= n + 1; i++)
	{
		cin >> c[i];
		for(int j = 1; j <= c[i]; j++)
		{
			int v;
			cin >> v;
			p[i][v] = 1;
		}
		cin >> p[i][n + 1];
	}	
	int cnt = 0, pos;
	for(int i = 1; i <= n + 1; i++)
	{
		for(int j = 1; j < i; j++)
			for(int k = 1; k <= n + 1; k++)
				a[j][k] = p[j][k];
		for(int j = i + 1; j <= n + 1; j++)
			for(int k = 1; k <= n + 1; k++)
				a[j - 1][k] = p[j][k];
		int P = guass(i);
		if(P)
			cnt++, pos = P;
	}
	if(cnt == 1) cout << pos;
	else cout << "illegal";
	return 0;
} 