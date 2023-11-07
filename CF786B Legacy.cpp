#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e6 + 5;
int tot, res;
int ls[N], rs[N], id[N], rt[2];
int ver[N], val[N], nxt[N], head[N];
void add(int x, int y, int z)
{
	ver[++tot] = y;
	val[tot] = z;
	nxt[tot] = head[x];
	head[x] = tot;
}
int build1(int l, int r)
{
	int nt = ++res, mid = l + r >> 1;
	if(l == r)
	{
		id[l] = nt;
		return nt;
	}
	ls[nt] = build1(l, mid);
	rs[nt] = build1(mid + 1, r);
	add(nt, ls[nt], 0);
	add(nt, rs[nt], 0); 
	return nt;
}
int build2(int l, int r)
{
	int nt = ++res, mid = l + r >> 1;
	if(l == r)
	{
		add(id[l], nt, 0);
		add(nt, id[l], 0);
		return nt;
	}
	ls[nt] = build2(l, mid);
	rs[nt] = build2(mid + 1, r);
	add(ls[nt], nt, 0);
	add(rs[nt], nt, 0); 
	return nt;
}
void addedge(int p, int l, int r, int L, int R, int x, int z, int opt)
{
	if(L <= l && r <= R)
	{
		if(opt == 0) add(x, p, z);
		else add(p, x, z);
		return;
	}
	int mid = l + r >> 1;
	if(L <= mid) addedge(ls[p], l, mid, L, R, x, z, opt);
	if(R > mid) addedge(rs[p], mid + 1, r, L, R, x, z, opt);
}
int dis[N];
signed main()
{
	int n, Q, s;
	cin >> n >> Q >> s;
	rt[0] = build1(1, n);
	rt[1] = build2(1, n);
	for(int i = 1; i <= Q; i++)
	{
		int opt, x, y, z, xx;
		cin >> opt >> x >> y;
		if(opt == 1)
		{
			cin >> z;
			add(id[x], id[y], z);
		}
		if(opt == 2)
		{
			cin >> xx >> z;
			addedge(rt[0], 1, n, y, xx, id[x], z, 0);
		}
		if(opt == 3)
		{
			cin >> xx >> z;
			addedge(rt[1], 1, n, y, xx, id[x], z, 1);
		}
	}
	memset(dis, -1, sizeof(dis));
	priority_queue< pair<int, int> > q;
	q.push(make_pair(0, id[s]));
	dis[id[s]] = 0;
	while(!q.empty())
	{
		int x = q.top().second; q.pop();
		for(int i = head[x]; i; i = nxt[i])
		{
			int y = ver[i], z = val[i];
			if(!~dis[y] || dis[x] + z < dis[y])
			{
				dis[y] = dis[x] + z;
				q.push(make_pair(-dis[y], y));
			}
		}
	}	
	for(int i = 1; i <= n; i++) cout << dis[id[i]] << ' ';
	return 0;
}