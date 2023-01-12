#include<bits/stdc++.h>
using namespace std;
int n, m;
const int N = 1e6 + 5;
vector<int> E[N], V[N], p;
struct Edge{
	int x, y, z, w, pos;
}e[N];
int top, cnt, res;
int vis[N], stk[N], ins[N], dfn[N], low[N];
inline void tarjan(int x)
{
	dfn[x] = low[x] = ++res;
	stk[++top] = x; vis[x] = 1;
	for(int i = 0; i < E[x].size(); i++)
	{
		int y = E[x][i];
		if(!dfn[y])
		{
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
		else if(vis[y]) low[x] = min(low[x], dfn[y]);
	}
	if(low[x] == dfn[x])
	{
		cnt++;
		while(stk[top + 1] != x)
		{
			ins[stk[top]] = cnt;
			vis[stk[top--]] = 0;
		}
	}
}
int TOT;
int pre[N][2];
Edge temp[N];
inline bool cmp(Edge x, Edge y) {return x.z < y.z;}
inline void work()
{
	TOT = 2 * m;
	for(int i = 1; i <= n; i++)
	{
		int size = V[i].size();
		for(int j = 0; j < size; j++)
		{
			int x = V[i][j];
			pre[x][0] = ++TOT;
			pre[x][1] = ++TOT;
			E[x].push_back(pre[x][0]);
			E[pre[x][1]].push_back(x + m);
		}
		for(int j = 1; j < size; j++)
		{
			int p1 = V[i][j - 1], p2 = V[i][j];
			E[pre[p1][0]].push_back(p2 + m);
			E[pre[p1][0]].push_back(pre[p2][0]);
			E[pre[p2][1]].push_back(pre[p1][1]);
			E[p2].push_back(pre[p1][1]);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		int size = V[i].size();
		for(int j = 0; j < size; j++)
			temp[j + 1] = e[V[i][j]];
		sort(temp + 1, temp + size + 1, cmp);
		for(int j = 1; j <= size; j++)
		{
			if(temp[j].z != temp[j - 1].z)
			{
				for(int k = 0; k < p.size(); k++)
				{
					int x = p[k];
					pre[x][0] = ++TOT;
					pre[x][1] = ++TOT;
					E[x + m].push_back(pre[x][1]);
					E[pre[x][0]].push_back(x);
				}
				for(int k = 1; k < p.size(); k++)
				{
					int p1 = p[k - 1], p2 = p[k];
					E[pre[p1][1]].push_back(pre[p2][1]);
					E[pre[p2][0]].push_back(pre[p1][0]);
					E[pre[p1][1]].push_back(p2);
					E[p2 + m].push_back(pre[p1][0]);
				}
				p.clear();
			}
			p.push_back(temp[j].pos);
		}
		for(int k = 0; k < p.size(); k++)
			{
				int x = p[k];
				pre[x][0] = ++TOT;
				pre[x][1] = ++TOT;
				E[x + m].push_back(pre[x][1]);
				E[pre[x][0]].push_back(x);
			}
			for(int k = 1; k < p.size(); k++)
			{
				int p1 = p[k - 1], p2 = p[k];
				E[pre[p1][1]].push_back(pre[p2][1]);
				E[pre[p2][0]].push_back(pre[p1][0]);
				E[pre[p1][1]].push_back(p2);
				E[p2 + m].push_back(pre[p1][0]);
			}
		p.clear();
	}
}
inline void init(int line)
{
	for(int i = 1; i <= m; i++)
		if(e[i].w > line)
			E[i].pop_back();
}
inline bool check(int line)
{
	for(int i = 1; i <= m; i++)
		if(e[i].w > line)
			E[i].push_back(i + m);
	for(int i = 1; i <= TOT; i++)
		dfn[i] = 0;
	cnt = res = 0;
	for(int i = 1; i <= TOT; i++)
		if(!dfn[i])
			tarjan(i);
	init(line);
	for(int i = 1; i <= m; i++)
		if(ins[i] == ins[i + m])
			return false;
	return true;
}
int main()
{
	int l = 0, r = 0;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> e[i].x >> e[i].y >> e[i].z >> e[i].w, r = max(r, e[i].w);
		e[i].pos = i;
		V[e[i].x].push_back(i);
		V[e[i].y].push_back(i);
	}
	work();
	while(l < r)
	{
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	if(!check(l))
	{
		cout << "No";
		return 0;
	}
	int cans = 0;
	vector<int> ans;
	cout << "Yes\n";
	for(int i = 1; i <= m; i++)
		if(ins[i] < ins[i + m])
			cans++, ans.push_back(i);
	cout << l << ' ' << cans << '\n';
	for(int i = 0; i < cans; i++)
		cout << ans[i] << ' ';
	return 0;
}