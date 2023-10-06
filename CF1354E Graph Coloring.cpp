#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, n1, n2, n3, res;
int col[N], v[N];
vector<int> g[N], p[N];
bool ok = 1;
inline void dfs(int x, int color)
{
	col[x] = color;
	p[res + color].push_back(x);
	for(int y : g[x])
	{
		if(col[y])
		{
			if(col[y] == col[x])
			{
				ok = 0;
				return;
			}
			continue;
		}
		dfs(y, 3 - color);
	}
}
int f[N], pos[N], ans[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	cin >> n1 >> n2 >> n3;
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i = 1; i <= n; i++)
	{
		if(!col[i])
		{
			dfs(i, 1);
			res++; v[res] = p[res].size();
			res++; v[res] = p[res].size();
		}
		if(!ok) {cout << "NO"; return 0;}
	}
	memset(f, -1, sizeof(f));
	f[0] = 0; res /= 2; int cnt = 0;
	for(int i = 1; i <= res; i++)
	{
		if(v[i * 2 - 1] + v[i * 2] == 1) {cnt++; continue;}
		for(int j = n2; j >= 0; j--)
		{
			if(f[j] != i - cnt - 1) continue;
			if(v[i * 2 - 1] && j + v[i * 2 - 1] <= n2)
			{
				f[j + v[i * 2 - 1]] = i - cnt;
				pos[j + v[i * 2 - 1]] = i * 2 - 1;
			}
			if(v[i * 2] && j + v[i * 2] <= n2)
			{
				f[j + v[i * 2]] = i - cnt;
				pos[j + v[i * 2]] = i * 2;
			}
		}
	}
	int cost = 0;
	for(int i = n2; i >= max(n2 - cnt, 0); i--)
		if(f[i] == res - cnt)
		{
			cost = i;
			break;
		}
	n2 -= cost;
	// cerr << cost << '\n';
	if(!cost && cnt != res) {cout << "NO"; return 0;}
	cout << "YES\n";
	while(cost)
	{
		// cerr << cost << ' ';
		for(int x : p[pos[cost]])
			ans[x] = 2;
		cost -= v[pos[cost]];
	}
	// for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
	for(int i = 1; i <= n; i++)
	{
		if(!ans[i])
		{
			if(!g[i].size())
			{
				if(n2) ans[i] = 2, n2--;
				else if(n1) ans[i] = 1, n1--;
				else ans[i] = 3, n3--;
			}
			else
			{
				if(n1) ans[i] = 1, n1--;
				else ans[i] = 3, n3--;
			}
		}
		cout << ans[i];
	}
	return 0;
}