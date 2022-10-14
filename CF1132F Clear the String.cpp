#include<bits/stdc++.h>
using namespace std;
int n;
char s[505];
int f[505][505];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	for(int i = 1; i <= n; i++)
		f[i][i] = 1;
	for(int len = 2; len <= n; len++)
		for(int i = 1; i <= n; i++)
		{
			int j = i + len - 1;
			if(j > n) break;
			f[i][j] = min(f[i + 1][j] + (s[i] != s[i + 1]), f[i][j - 1] + (s[j] != s[j - 1]));
			if(len == 2) continue;
			if(s[i] == s[j]) f[i][j] = f[i + 1][j - 1] + (s[i] != s[i + 1]);
			for(int k = i + 1; k < j; k++)
				if(s[k] == s[i])
					f[i][j] = min(f[i][j], f[i + 1][k - 1] + f[k][j]);
		}
	cout << f[1][n];
	return 0;
}