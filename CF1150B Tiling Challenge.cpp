#include<bits/stdc++.h>
using namespace std;
int n;
char c[1005][1005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> c[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(c[i][j] == '.' && c[i][j - 1] == '.' && c[i][j + 1] == '.' && c[i - 1][j] == '.' && c[i + 1][j] == '.')
				c[i][j] = c[i][j + 1] = c[i][j - 1] = c[i + 1][j] = c[i - 1][j] = '#';
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(c[i][j] == '.')
			{
				cout << "NO\n";
				return 0;
			}
	cout << "YES\n";
	return 0;
}