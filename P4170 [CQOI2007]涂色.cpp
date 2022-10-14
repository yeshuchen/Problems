#include<bits/stdc++.h>
using namespace std;
long long f[75][75];
char s[75];
int main()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for(int i = 1; i <= n; i++)
		f[i][i] = 1;
	for(int len = 2; len <= n; len++)
		for(int i = 1; i <= n; i++)
		{
			int j = i + len - 1;
			if(j > n) break;
			if(len == 2)
			{
				if(s[i] == s[j]) f[i][j] = 1;
				else f[i][j] = 2;
				continue;
			}
			f[i][j] = min(f[i + 1][j] + (s[i + 1] != s[i]), f[i][j - 1] + (s[j - 1] != s[j]));
			if(s[i] == s[j])
				f[i][j] = min(f[i][j], f[i + 1][j - 1] + (s[i] != s[i + 1]));
			for(int k = i; k < j; k++)
			{
				if(s[i] == s[k]) 
					f[i][j] = min(f[i][j], f[i + 1][k - 1] + f[k][j]);
			}
		}
	cout << f[1][n];
	return 0;
}