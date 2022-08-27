#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
struct Edge{
	int x, y, z;
}e[N];
struct kruskal_tree{
	int val, ls, rs, L, R;
}t[N];
int n, m, q, cnt, res;
int h[N], ft[N], ary[N];
int f[N][21];
inline bool cmp(Edge x, Edge y)
{
	return x.z < y.z;
}
int find(int k){return ft[k] == k ? ft[k] : ft[k] = find(ft[k]);}
void dfs(int x, int fa)
{
	f[x][0] = fa;
	for(int i = 1; i <= 20; i++)
		f[x][i] = f[f[x][i - 1]][i - 1];
	if(!t[x].val)
	{
		ary[++res] = h[x];
		t[x].L = t[x].R = res;
		return;
	}
	dfs(t[x].ls, x);
	dfs(t[x].rs, x);
	t[x].L = t[t[x].ls].L;
	t[x].R = t[t[x].rs].R;
}
int root[N];
/*
int clone(int v)
{
	a[++res] = a[v];
	return res;
}
int build(int node,int l,int r)
{
    node=++res;
    a[node].val=0;
    if(l==r)return node;
    int mid=l+r>>1;
    a[node].ls=build(0,l,mid);
    a[node].rs=build(0,mid+1,r);
    return node;
}
int change(int v,int l,int r,int d,int k)
{
    int node=clone(v);
    if(l==r)
    {
        a[node].val+=k;
        return node;
    }
    int mid=l+r>>1;
    if(d<=mid)a[node].ls=change(a[node].ls,l,mid,d,k);
    else a[node].rs=change(a[node].rs,mid+1,r,d,k);
    a[node].val=a[a[node].ls].val+a[a[node].rs].val;
    return node;
}
*/
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m >> q;
	cnt = n;
	for(int i = 1; i <= n; i++)
		cin >> h[i];
	for(int i = 1; i <= 2 * n; i++)
		ft[i] = i;
	for(int i = 1; i <= m; i++)
		cin >> e[i].x >> e[i].y >> e[i].z;
	sort(e + 1, e + m + 1, cmp);
	for(int i = 1; i <= m; i++)
	{
		int fx = find(e[i].x), fy = find(e[i].y);
		cout << fx << ' ' << fy << '\n';
		if(fx != fy)
		{
			cnt++;
			t[cnt].ls = fx;
			t[cnt].rs = fy;
			t[cnt].val = e[i].z;
			ft[fx] = ft[fy] = cnt;
		}
	}
	dfs(cnt, 0);
	res = 0;
	// root[0] = build(0, 1, n);
	for(int i = 1; i <= n; i++)
		cout << ary[i];
	// for(int i = 1; i <= n; i++)
	// 	root[i] = change(root[i - 1], 1, n, ary[i], 1);
	// while(q--)
	// {
	// 	int v, x, k;
	// 	cin >> v >> x >> k;
	// 	for(int i = 20; i >= 0; i--)
	// 		if(t[f[v][i]].val <= x)
	// 			v = f[v][i];
	// 	if(t[v].R - t[v].L + 1 < k)
	// 	{
	// 		cout << -1 << '\n';
	// 		continue;
	// 	}
	// 	cout << query(root[t[v].R], root[t[v].L - 1])
	// }
	return 0;
}
