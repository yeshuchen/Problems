#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int pos, node = 1;
string s;
int n, tot;
int l[N], r[N], f[N][3][2];
inline void build(int x)
{
	if(s[pos] == '0') {pos++; return;}
	if(s[pos] == '1') {pos++, l[x] = ++node, build(node); return;}
	if(s[pos] == '2') {pos++, l[x] = ++node, build(node), r[x] = ++node, build(node);}
}
inline void dfs(int x)
{
	if(l[x]) dfs(l[x]);
	if(r[x]) dfs(r[x]);
	if(!l[x] && !r[x])
	{
		f[x][0][1] = f[x][0][0] = 1;
		f[x][1][1] = f[x][1][0] = f[x][2][1] = f[x][2][0] = 0;
		return;
	}
	if(!r[x])
	{
		f[x][0][1] = max(f[l[x]][1][1], f[l[x]][2][1]) + 1;
		f[x][0][0] = min(f[l[x]][1][0], f[l[x]][2][0]) + 1;
		f[x][1][1] = max(f[l[x]][0][1], f[l[x]][2][1]);
		f[x][2][1] = max(f[l[x]][0][1], f[l[x]][1][1]);
		f[x][1][0] = min(f[l[x]][0][0], f[l[x]][2][0]);
		f[x][2][0] = min(f[l[x]][0][0], f[l[x]][1][0]);
		return;
	}
	f[x][0][1] = max(f[l[x]][1][1] + f[r[x]][2][1], f[l[x]][2][1] + f[r[x]][1][1]) + 1;
	f[x][0][0] = min(f[l[x]][1][0] + f[r[x]][2][0], f[l[x]][2][0] + f[r[x]][1][0]) + 1;
	f[x][1][1] = max(f[l[x]][0][1] + f[r[x]][2][1], f[l[x]][2][1] + f[r[x]][0][1]);
	f[x][2][1] = max(f[l[x]][0][1] + f[r[x]][1][1], f[l[x]][1][1] + f[r[x]][0][1]);
	f[x][1][0] = min(f[l[x]][0][0] + f[r[x]][2][0], f[l[x]][2][0] + f[r[x]][0][0]);
	f[x][2][0] = min(f[l[x]][0][0] + f[r[x]][1][0], f[l[x]][1][0] + f[r[x]][0][0]);

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s;
	build(1);
	dfs(1);
	cout << max({f[1][0][1], f[1][1][1], f[1][2][1]}) << ' ' << min({f[1][0][0], f[1][1][0], f[1][2][0]});
	return 0;
}