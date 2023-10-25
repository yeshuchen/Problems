#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
char s[N];
int dep[N];
int p, f[N][21];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s + 1;
	int len = strlen(s + 1);
	for(int i = 2; i <= len; i++)
	{
		int p = f[i - 1][0];
		while(p && s[p + 1] != s[i]) p = f[p][0];
		if(s[p + 1] == s[i]) f[i][0] = p + 1;
		dep[i] = dep[f[i][0]] + 1;
		for(int j = 1; j <= 20; j++) f[i][j] = f[f[i][j - 1]][j - 1];
	}
	int q;
	cin >> q;
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		x = f[x][0]; y = f[y][0];
		if(dep[x] < dep[y]) swap(x, y);
		int tmp = dep[x] - dep[y];
		for(int i = 20; i >= 0; i--)
			if(tmp & (1 << i)) x = f[x][i];
		if(x == y) {cout << x << '\n'; continue;}
		for(int i = 20; i >= 0; i--)
			if(f[x][i] != f[y][i])
				x = f[x][i], y = f[y][i];
		cout << f[x][0] << '\n';
	}
	return 0;
}