#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
int n;
char c[200005];
ll f[1005][11][11][2][2];
// f[i][j][k][l][z] dp到第i位，前一位填的数是j，前两位填的数是k，是否达到上限，是否有前导0的非萌数个数	
inline int dfs(int s, int l1, int l2, bool zero, bool lim)
{
	ll res = 0;
	if(s > n) return 1;
	if(~f[s][l1][l2][zero][lim]) return f[s][l1][l2][zero][lim];
	for(int i = zero; i <= 9; i++)
	{
		if(i == l1 || i == l2) continue;
		if(lim && i > c[s] - '0') break; 
		res = (res + dfs(s + 1, i, l1, 0, (lim && i == c[s] - '0'))) % mod;
	}
	return (f[s][l1][l2][zero][lim] = res);
}
inline int solve(string x)
{
	memset(f, -1, sizeof(f));
	int ans = 0;
	memset(c, '\0', sizeof(c));
	for(int i = 0; i < x.size(); i++)
		c[i + 1] = x[i];
	n = strlen(c + 1);
	for(int i = 1; i <= n; i++)
		ans = (1ll * ans * 10 + (c[i] - '0')) % mod;
	ans = ((ans - dfs(1, 10, 10, 1, 1)) % mod + mod) % mod;
	for(int i = 2; i <= n; i++)
		ans = ((ans - dfs(i, 10, 10, 1, 0)) % mod + mod) % mod;
	return ans;
}
inline bool check(string x)
{
	for(int i = 1; i < x.size(); i++)
		if(x[i] == x[i - 1] || i > 1 && x[i] == x[i - 2])
			return true;
	return false;
}
int main()
{
	string l, r;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> l >> r;
	cout << ((solve(r) - solve(l) + check(l)) % mod + mod) % mod;	
	return 0;
}