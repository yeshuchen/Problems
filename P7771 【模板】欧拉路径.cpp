#include<bits/stdc++.h>
#define mk(x, y) make_pair(x, y)
using namespace std;
const int N = 2e5 + 5;
int n, m;
stack<int> stk;
int del[N], deg[N];
vector<int> v[N];
void dfs(int x)
{
	for(int i = del[x]; i < v[x].size(); i = del[x])
	{
		del[x] = i + 1;
		dfs(v[x][i]);
	}
	stk.push(x);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		deg[y]++;
	}
	int st = 0;
	for(int i = 1; i <= n; i++)
	{
		sort(v[i].begin(), v[i].end());
		if(abs((int)v[i].size() - deg[i]) > 1) {cout << "No"; return 0;}
		if(v[i].size() > deg[i])
		{
			if(st) {cout << "No"; return 0;}
			st = i;
		}
	}
	dfs(st ? st : 1);
	while(!stk.empty()) cout << stk.top() << ' ', stk.pop();
	return 0;
}