#include<bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int n, m, tot;
int deg[N], deg2[N];
int f[N][2], pos[N][2];
int ok, vis[N];
vector<int> g[N], ans;
void dfs(int x, bool fl)
{
	if(ok == 2) return;
	vis[x] = 1;
	ans.push_back(x);
	f[x][fl] = 1;
	for(int y : g[x])
	{
		if(vis[y] == 1) ok = max(ok, 1);
		if(f[y][fl ^ 1]) continue;
		if(!g[y].size() && !fl && ok != 2)
		{
			ok = 2;
			ans.push_back(y);
		}
		dfs(y, fl ^ 1);
	}
	if(ok != 2) ans.pop_back();
	vis[x] = 2;
}
int main()	
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;
		for(int j = 1; j <= num; j++)
		{
			int x;
			cin >> x;
			g[i].push_back(x);
		}
	}
	int s, cnt = 0;
	cin >> s;
	f[s][0] = 1;
	dfs(s, 0);
	if(ok == 2)
	{
		cout << "Win\n";
		for(int i : ans)
			cout << i << ' ';
	}
	if(ok == 1) cout << "Draw";
	if(!ok) cout << "Lose";
	return 0;
}