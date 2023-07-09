#include<bits/stdc++.h>
using namespace std;
int n, m;
char c[2005][2005];
int p1[2005][2005], p2[2005][2005], p3[2005][2005], p4[2005][2005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> c[i][j];
	for(int i = 1; i <= n; i++)
	{
		p1[i][0] = p2[i][m + 1] = 0;
		for(int j = 1; j <= m; j++)
		{
			if(c[i][j] == '#') continue;
			if(!p1[i][j - 1]) p1[i][j] = j;
			else p1[i][j] = p1[i][j - 1];
		}
		for(int j = m; j; j--)
		{
			if(c[i][j] == '#') continue;
			if(!p2[i][j + 1]) p2[i][j] = j;
			else p2[i][j] = p2[i][j + 1];
		}
	}
	for(int j = 1; j <= m; j++)
	{
		p3[0][j] = p4[n + 1][j] = 0;
		for(int i = 1; i <= n; i++)
		{
			if(c[i][j] == '#') continue;
			if(!p3[i - 1][j]) p3[i][j] = i;
			else p3[i][j] = p3[i - 1][j];
		}
		for(int i = n; i; i--)
		{
			if(c[i][j] == '#') continue;
			if(!p4[i + 1][j]) p4[i][j] = i;
			else p4[i][j] = p4[i + 1][j];
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			if(c[i][j] == '#') continue;
			ans = max(ans, p2[i][j] - p1[i][j] + p4[i][j] - p3[i][j] + 1);
		}
	cout << ans;
	return 0;
}