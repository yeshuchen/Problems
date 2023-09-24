#include<bits/stdc++.h>
using namespace std;
int a[15];
int f[15][2];
inline int dfs(int len, bool limit, bool lead0, bool _6)
{
	if(!len) return 1;
	if(!limit && !lead0 && f[len][_6]) return f[len][_6];
	int up = limit ? a[len] : 9, res = 0;
	for(int i = 0; i <= up; i++)
	{
		if(_6 && i == 2 || i == 4) continue;
		res += dfs(len - 1, limit && i == up, lead0 && i == 0, i == 6);
	}
	if(!limit && !lead0) f[len][_6] = res;
	return res;
}
inline int solve(int x)
{
	int len = 0;
	while(x)
	{
		a[++len] = x % 10;
		x /= 10;
	}
	return dfs(len, 1, 1, 0);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int l, r;
	while(cin >> l >> r)
	{
		if(!l && !r) break;
		cout << solve(r) - solve(l - 1);
	}
	return 0;
}