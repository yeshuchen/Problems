#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int d, m;
char l[2005], r[2005];
int a[2005], p[2005], f[2005][5005];
inline bool check(char *c)
{
	int len = strlen(c + 1), res = 0;
	for(int i = 1; i <= len; i++)
	{
		res = res + (c[i] - '0') * p[len - i]; res %= m;
		if((i & 1) ^ ((c[i] - '0') != d)) return false;
	}
	return res == 0;
}
inline int dfs(int pos, int len, bool limit, bool lead0, int remain)
{
	if(!pos) return remain == 0;
	if(!limit && !lead0 && ~f[pos][remain]) return f[pos][remain];
	int up = limit ? a[pos] : 9;
	if(len - pos & 1)
	{
		if(limit && d > up) return 0;
		return dfs(pos - 1, len, limit && d == up, 0, ((remain - d * p[pos - 1]) % m + m) % m);
	}
	int res = 0;
	for(int i = lead0; i <= up; i++)
	{
		if(i == d) continue;
		res += dfs(pos - 1, len, limit && i == up, 0, ((remain - i * p[pos - 1]) % m + m) % m); res %= mod;
	}
	if(!lead0 && !limit) f[pos][remain] = res;
	return res;
}
inline int solve(char *c)
{
	int len = strlen(c + 1); p[0] = 1;
	for(int i = 1; i <= len; i++) p[i] = p[i - 1] * 10 % m;
	for(int i = 1; i <= len; i++)
		a[i] = c[len - i + 1] - '0';
	return dfs(len, len, 1, 1, 0);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    memset(f, -1, sizeof(f));
	cin >> m >> d;
	cin >> l + 1;
	cin >> r + 1;
	cout << ((solve(r) - solve(l) + check(l)) % mod + mod) % mod;
	return 0;
}
		   		     	   	 		  	    		