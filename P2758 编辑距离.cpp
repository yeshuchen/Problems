#include<bits/stdc++.h>
using namespace std;
char s1[2005],s2[2005];
int f[2005][2005];
int main()
{
	scanf("%s", s1 + 1);
	scanf("%s", s2 + 1);
	int n = strlen(s1 + 1);
	int m = strlen(s2 + 1);
	for(int i = 1; i <= n; i++)
		f[i][0] = i;
	for(int i = 1; i <= m; i++)
		f[0][i] = i;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			if(s1[i] == s2[j])
			{
				f[i][j] = f[i - 1][j - 1];
				continue;
			}
			f[i][j] = min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1;
		}
	cout << f[n][m];
	return 0;
}