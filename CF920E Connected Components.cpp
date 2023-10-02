#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m;
int no[N], tmp[N];
bool in[N], vis[N], book[N];
vector<int> v[N], ans;
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
		v[y].push_back(x);
	}
	for(int i = 1; i <= n; i++) sort(v[i].begin(), v[i].end());
	for(int i = 1; i <= n; i++)
	{
		if(!in[i])
		{
			int cnt = 0, res = 0;
			for(int j = 1; j <= n; j++) vis[j] = 0;
			for(int j = 0; j < v[i].size(); j++) vis[v[i][j]] = 1, no[++res] = v[i][j], book[res] = 0;
			queue<int> q;
			for(int j = 1; j <= n; j++)
				if(!vis[j])
					q.push(j);
			while(!q.empty())
			{
				int x = q.front(); q.pop(); cnt++; in[x] = 1;
				for(int j = 0; j < v[x].size(); j++)
				{
					int pos = lower_bound(no + 1, no + res + 1, v[x][j]) - no;
					if(pos <= res && no[pos] == v[x][j]) book[pos] = 1;
				}
				int ret = 0;
				for(int j = 1; j <= res; j++)
				{
					if(book[j]) tmp[++ret] = no[j], book[j] = 0;
					else q.push(no[j]);
				}
				for(int j = 1; j <= ret; j++) no[j] = tmp[j];
				res = ret;
			}
			ans.push_back(cnt);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for(auto i : ans) cout << i << ' ';
	return 0;
}