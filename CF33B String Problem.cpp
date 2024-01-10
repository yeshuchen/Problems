#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, inf = 1e9;
int n, m;
int f[50][50];
char s[N], t[N];
int main()
{
	cin >> s + 1 >> t + 1;
	if(strlen(s + 1) != strlen(t + 1)) {cout << -1; return 0;}
	n = strlen(s + 1);
	cin >> m;
	for(int i = 0; i < 26; i++)
		for(int j = 0; j < 26; j++)
			f[i][j] = (i == j ? 0 : 1e9);
	for(int i = 1; i <= m; i++)
	{
		char c1, c2;
		int v;
		cin >> c1 >> c2 >> v;
		c1 -= 'a'; c2 -= 'a';
		f[c1][c2] = min(f[c1][c2], v);
	}
	for(int k = 0; k < 26; k++)
		for(int i = 0; i < 26; i++)
			for(int j = 0; j < 26; j++)
				if(f[i][k] != 1e9 && f[k][j] != 1e9)
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		long long res = 0;
		int n1 = s[i] - 'a', n2 = t[i] - 'a';
		for(int j = 0; j < 26; j++)
			if(f[n1][res] + f[n2][res] > f[n1][j] + f[n2][j])
				res = j;
		if(f[n1][res] + f[n2][res] >= 1e9) {cout << -1; return 0;}
		ans += f[n1][res] + f[n2][res];
		s[i] = res + 'a';
	}
	cout << ans << '\n' << s + 1;
	return 0;
}