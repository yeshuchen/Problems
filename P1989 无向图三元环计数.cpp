#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n, m;
int x[N], y[N];
int in[N], vis[N];
vector<int> e[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> x[i] >> y[i];
		in[x[i]]++; in[y[i]]++;
	}
	for(int i = 1; i <= m; i++)
	{
		if(in[x[i]] > in[y[i]]) swap(x[i], y[i]);
		else if(in[x[i]] == in[y[i]] && x[i] > y[i])
			swap(x[i], y[i]);
		e[x[i]].push_back(y[i]);
	}
	int ans = 0;
	for(int u = 1; u <= n; u++)
	{
		for(auto i : e[u]) vis[i] = u;
		for(auto v : e[u])
			for(auto w : e[v])
				ans += (vis[w] == u);
	}
	cout << ans;
	return 0;
}