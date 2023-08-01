#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, tot;
int a[N], head[N], nxt[N], ver[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
multiset<int> f[N];
multiset<int>::iterator it;
inline void merge(int x, int y)
{
	if(f[x].size() < f[y].size()) swap(f[x], f[y]);
	for(it = f[y].begin(); it != f[y].end(); it++) f[x].insert(*it);
}
inline void dfs(int x)
{
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		dfs(y);
		merge(x, y);
	}
	f[x].insert(a[x]);
	it = f[x].lower_bound(a[x]);
	if(it != f[x].begin()) f[x].erase(--it);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		add(x, i);
	}
	dfs(1);
	cout << f[1].size();
	return 0;
}