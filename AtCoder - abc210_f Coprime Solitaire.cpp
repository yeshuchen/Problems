#include<bits/stdc++.h>
using namespace std;
const int N = 2e6;
int n, cnt_prime;
int a[N + 5];
bool vis[N + 5];
int prime[N + 5], min_prime[N + 5];
int tot;
int ver[4 * N + 5], nxt[4 * N + 5], head[N + 5];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
inline void lineshai()
{
	for(int i = 2; i <= N; i++)
	{
		if(!vis[i]) prime[++cnt_prime] = i, min_prime[i] = i;
		for(int j = 1; j <= cnt_prime && i * prime[j] <= N; j++)
		{
			vis[i * prime[j]] = 1; min_prime[i * prime[j]] = prime[j];
			if(i % prime[j] == 0) break;
		}
	}
}
vector<int> v[N + 5];
int res, top, cnt;
int dfn[N + 5], low[N + 5], scc[N + 5], stk[N + 5];
inline void tarjan(int x)
{
	dfn[x] = low[x] = ++res;
	stk[++top] = x; vis[x] = 1;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
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
			scc[stk[top]] = cnt;
			vis[stk[top--]] = 0;
		}
	}
}
inline int f(int x) {return x > n ? x - n : x + n;}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n; int point = 2 * n;
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> a[i + n];
	lineshai();
	for(int i = 1; i <= 2 * n; i++)
	{
		int tmp = a[i];
		while(tmp > 1)
		{
			while(tmp / min_prime[tmp] % min_prime[tmp] == 0) tmp /= min_prime[tmp];
			v[min_prime[tmp]].push_back(i); tmp /= min_prime[tmp];
		}
	}
	for(int i = 1; i <= cnt_prime; i++)
	{
		int t = prime[i];
		if(v[t].empty()) continue;
		for(int j = 0; j < v[t].size(); j++)
		{
			point++;
			add(point, f(v[t][j]));
			if(j > 0) add(v[t][j], point - 1), add(point, point - 1);
		}
		for(int j = v[t].size() - 1; j >= 0; j--)
		{
			point++;
			add(point, f(v[t][j]));
			if(j < v[t].size() - 1) add(v[t][j], point - 1), add(point, point - 1);
		}
	}
	for(int i = 1; i <= 2 * n; i++) vis[i] = 0;
	for(int i = 1; i <= 2 * n; i++)
		if(!dfn[i])
			tarjan(i);
	for(int i = 1; i <= n; i++)
		if(scc[i] == scc[i + n])
		{
			cout << "No\n";
			return 0;
		}
	cout << "Yes";
	return 0;
}