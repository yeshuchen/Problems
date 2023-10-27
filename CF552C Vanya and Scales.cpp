#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int len, tmp[25];
map<int, int> mp;
void dfs1(int s, int v)
{
	if(s > len / 2)
	{
		mp[v] = 1;
		return;
	}
	dfs1(s + 1, v - tmp[s]);
	dfs1(s + 1, v + tmp[s]);
	dfs1(s + 1, v);
}
void dfs2(int s, int v)
{
	if(s > len)
	{
		if(mp[m - v]) cout << "YES", exit(0);
		return;
	}
	dfs2(s + 1, v - tmp[s]);
	dfs2(s + 1, v + tmp[s]);
	dfs2(s + 1, v);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	if(n <= 3) 
	{
		cout << "YES\n";
		return 0;
	}
	int base = 1;
	for(int i = 1; i; i++)
	{
		tmp[++len] = base;
		if(base >= m) break;
		base *= n;
	}
	// for(int i = 1; i <= len; i++) cout << tmp[i] << ' ';
	// cout << '\n';
	dfs1(1, 0);
	dfs2(len / 2 + 1, 0);
	cout << "NO";
	return 0;
}