#include<bits/stdc++.h>
using namespace std;
int n, maxn;
int p[100005], f[100005];
int v[100005], in[100005];
vector<int> g[100005];
inline void dfs(int x, int dep)
{
	p[x] = dep;
	if(p[x] > p[maxn]) maxn = x;
	for(int i = 0; i < g[x].size(); i++)
	{
		int y = g[x][i];
		if(in[y] > 1) continue;
		f[y] = x;
		dfs(y, dep + 1);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> v[i];
	for(int i = 1, x; i <= n; i++)
	{
		cin >> x;
		if(x)
			g[i].push_back(x), in[x]++;
	}
	for(int i = 1; i <= n; i++)
		if(v[i])
			dfs(i, 1);
	queue<int> q;
	while(maxn)
	{
		q.push(maxn);
		maxn = f[maxn];
	}
	cout << q.size() << '\n';
	while(!q.empty()) cout << q.front() << ' ', q.pop();
	return 0;
}