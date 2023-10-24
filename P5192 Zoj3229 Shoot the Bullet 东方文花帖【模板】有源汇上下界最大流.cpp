#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, inf = 2e9;
int n, m;
int tot = 1;
int w[N], cur[N];
struct Edge {
	int y, z, nxt;
} e[N];
int head[N];
void add(int x, int y, int z)
{
	e[++tot] = {y, z, head[x]};
	head[x] = tot;
}
void addedge(int x, int y, int down, int up)
{
	w[x] -= down; w[y] += down;
	add(x, y, up - down);
	add(y, x, 0);
}
int S, T;
int dep[N];
bool bfs()
{
	memset(dep, 0, (T + 1) * sizeof(int));
	dep[S] = 1; queue<int> q;
	q.push(S);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for(int i = head[x]; i; i = e[i].nxt)
		{
			int y = e[i].y;
			if(e[i].z && !dep[y])
			{
				dep[y] = dep[x] + 1;
				q.push(y);
			}
		}
	}
	return dep[T];
}
int dfs(int x, int flow)
{
	int res = 0;
	if(x == T || !flow) return flow;
	for(int i = cur[x]; i; i = e[i].nxt)
	{
		cur[x] = i;
		int y = e[i].y, v;
		if(dep[y] == dep[x] + 1 && (v = dfs(y, min(flow - res, e[i].z))))
		{
			res += v;
			e[i].z -= v;
			e[i ^ 1].z += v;
			if(res == flow) return res;
		}
	}
	return res;
}
int SS, TT;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while(cin >> n >> m)
	{
		tot = 1;
		memset(head, 0, (TT) * 2 * sizeof(int));
		SS = n + m + 1; TT = SS + 1;
		for(int i = 1; i <= m; i++)
		{
			int x;
			cin >> x;
			addedge(i + n, TT, x, inf);
		}
		for(int i = 1; i <= n; i++)
		{
			int C, D;
			cin >> C >> D;
			addedge(SS, i, 0, D);
			for(int j = 1; j <= C; j++)
			{
				int opt, l, r;
				cin >> opt >> l >> r;
				addedge(i, opt + n + 1, l, r);
			}
		}
		int ans = 0;
		S = TT + 1; T = S + 1;
		for(int i = 1; i <= TT; i++)
		{
			if(w[i] < 0) add(i, T, -w[i]), add(T, i, 0);
			if(w[i] > 0) add(S, i, w[i]), add(i, S, 0), ans += w[i];
			w[i] = 0;
		}
		addedge(TT, SS, 0, inf);
		// cout << ans << '\n';
		while(bfs())
		{
			memcpy(cur + 1, head + 1, T * sizeof(int));
			ans -= dfs(S, inf);
		}
		// cout << ans << '\n';
		if(ans) {cout << -1 << "\n\n"; continue;}
		S = SS; T = TT; ans = e[head[S]].z;
		head[S] = e[head[S]].nxt; head[T] = e[head[T]].nxt;
		while(bfs())
		{
			memcpy(cur + 1, head + 1, T * sizeof(int));
			ans += dfs(S, inf);
		}
		cout << ans << "\n\n";
	}
	return 0;
}