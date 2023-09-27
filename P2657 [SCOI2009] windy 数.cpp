#include<bits/stdc++.h>
using namespace std;
int a[700];
int f[700][20];
inline int dfs(int pos, bool limit, bool lead0, int last)
{
	if(!pos) return 1;
	if(last != 15 && !limit && ~f[pos][last]) return f[pos][last];
	int up = (limit ? a[pos] : 9), res = 0;
	for(int i = 0; i <= up; i++)
	{
		if(lead0) res += dfs(pos - 1, limit && i == up, lead0 && i == 0, i == 0 ? last : i);
		else if(abs(last - i) >= 2) res += dfs(pos - 1, limit && i == up, false, i);
	}
	// cout << pos << ' ' << limit << ' ' << last << ' ' << res << '\n';
	if(!limit && last != 15) f[pos][last] = res;
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
	return dfs(len, 1, 1, 15);
}
int main()
{
	memset(f, -1, sizeof(f));
	int l, r;
	cin >> l >> r;
	cout << solve(r) - solve(l - 1);
	return 0;
}