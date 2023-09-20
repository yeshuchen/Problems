#include<bits/stdc++.h>
using namespace std;
int n, len;
int a[50], f[50];
inline int dfs(int pos, bool lead0, bool limit)
{
	if(!pos) return 1;
	int up = limit ? a[pos] : 9, res = 0;
	if(!lead0 && !limit && f[pos]) return f[pos];
	for(int i = 0; i <= up; i++)
	{
		if(lead0 && i == 0) res = max(res, dfs(pos - 1, 1, 0));
		else res = max(res, i * dfs(pos - 1, 0, limit && i == up));
	}
	if(!lead0 && !limit) f[pos] = res;
	return res;
}
inline int solve(int x)
{
	while(x)
	{
		a[++len] = x % 10;
		x /= 10;
	}
	return dfs(len, 1, 1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	cout << solve(n);
	return 0;
}