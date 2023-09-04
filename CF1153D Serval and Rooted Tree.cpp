#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, d[N];
int op[N], in[N];
vector<int> v[N];
inline void dfs(int x)
{
	int res = INT_MAX;
	if(!in[x]) d[x] = 1;
	for(int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];
		dfs(y);
		if(op[x] == 0) d[x] += d[y];
		else res = min(res, d[y]);
	}
	if(res != INT_MAX) d[x] = res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n; int ans = 0;
	for(int i = 1; i <= n; i++) cin >> op[i];
	for(int i = 2, f; i <= n; i++) cin >> f, v[f].push_back(i), in[f]++;
	for(int i = 1; i <= n; i++)
		ans += (!in[i]);
	dfs(1);
	cout << ans - d[1] + 1;
	return 0;
}