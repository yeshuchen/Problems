#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct node {
	int d, x;
} d1[N], d2[N];
int n, tot;
int dep[N];
int ver[N << 1], nxt[N << 1], head[N];
inline bool cmp(node x, node y) {return x.d > y.d;}
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
int maxn;
inline void dfs(int x, int fa)
{
	dep[x] = dep[fa] + 1;
	if(dep[x] > dep[maxn]) maxn = x;
	for(int i = head[x]; i; i = nxt[i])
	{
		int y = ver[i];
		if(y != fa) dfs(y, x);
	}
}
int cnt, ans[N], f[N];
inline int find(int k) {return f[k] == k ? k : f[k] = find(f[k]);}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		add(x, y);
		add(y, x);
		f[i] = i;
	}
	int l, r, cnt = n;
	dfs(1, 0); l = maxn, maxn = 0;
	dfs(l, 0); r = maxn;
	for(int i = 1; i <= n; i++) d1[i] = (node) {dep[i], i};
	dfs(r, 0);
	for(int i = 1; i <= n; i++) d2[i] = (node) {dep[i], i};
	sort(d1 + 1, d1 + n + 1, cmp);
	sort(d2 + 1, d2 + n + 1, cmp);
	int p1 = 1, p2 = 1;
	for(int i = n; i >= 1; i--)
	{
		while(d1[p1].d > i && p1 <= n)
		{
			int fx = find(d1[p1].x), fy = find(l);
			if(fx != fy)
			{
				cnt--;
				f[fx] = fy;
			}
			p1++;
		}
		while(d2[p2].d > i && p2 <= n)
		{
			int fx = find(d2[p2].x), fy = find(r);
			if(fx != fy)
			{
				cnt--;
				f[fx] = fy;
			}
			p2++;
		}
		ans[i] = cnt;
	}
	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
}