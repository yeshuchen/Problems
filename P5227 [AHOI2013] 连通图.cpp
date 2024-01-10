#include<bits/stdc++.h>
#define ls (p << 1)
#define rs (p << 1 | 1)
using namespace std;
const int N = 4e5 + 5;
vector<int> t[N << 2];
int n, m, k;
struct edge {
	int x, y;
} e[N], stk[N];
int pos[N], ret;
int f[N], sz[N], top;
int find(int k) {return f[k] == k ? k : find(f[k]);}
void merge(int x, int y)
{
	ret--;
	x = find(x); y = find(y);
	if(sz[x] < sz[y]) swap(x, y);
	f[y] = x; sz[x] += sz[y];
	stk[++top] = {x, y};
}
void update(int p, int l, int r, int L, int R, int v)
{
	if(L > R) return;
	if(L <= l && r <= R) {t[p].push_back(v); return;}
	int mid = l + r >> 1;
	if(L <= mid) update(ls, l, mid, L, R, v);
	if(R > mid) update(rs, mid + 1, r, L, R, v);
}
void solve(int p, int l, int r)
{
	int mid = l + r >> 1, last = top;
	for(int i : t[p])
	{
		int x = find(e[i].x), y = find(e[i].y);
		if(x == y) continue;
		merge(x, y);
	}
	if(l == r) cout << (ret == 1 ? "Connected" : "Disconnected") << '\n';
	else
	{
		solve(ls, l, mid);
		solve(rs, mid + 1, r);
	}
	while(top > last)
	{
		f[stk[top].y] = stk[top].y;
		sz[stk[top].x] -= sz[stk[top].y];
		top--; ret++;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	ret = n;
	for(int i = 1; i <= m; i++)
		cin >> e[i].x >> e[i].y;
	cin >> k;
	for(int i = 1; i <= k; i++)
	{
		int num;
		cin >> num;
		for(int j = 1; j <= num; j++)
		{
			int x;
			cin >> x;
			update(1, 1, k, pos[x] + 1, i - 1, x);
			pos[x] = i;
		}
	}
	for(int i = 1; i <= m; i++) update(1, 1, k, pos[i] + 1, k, i);
	for(int i = 1; i <= n; i++) f[i] = i, sz[i] = 1;
	solve(1, 1, k);
	return 0;
}