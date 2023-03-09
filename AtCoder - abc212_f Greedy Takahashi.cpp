#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
struct Edge{
	int a, b, s, t;
}bus[N];
int n, m, q;
vector< pair<int, int> > v[N];
int pos[N][20], belong[N];
inline bool cmp(Edge x, Edge y) {return x.s < y.s;}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	for(int i = 1; i <= m; i++)
		cin >> bus[i].a >> bus[i].b >> bus[i].s >> bus[i].t;
	sort(bus + 1, bus + m + 1, cmp);
	for(int i = 1; i <= m; i++)
		v[bus[i].a].push_back(make_pair(bus[i].s, i)), belong[i] = bus[i].a;
	for(int i = 1; i <= n; i++) sort(v[i].begin(), v[i].end());
	for(int i = 1; i <= m; i++)
	{
		int l = 1, r = v[bus[i].b].size(), p = -1;
		while(l <= r)
		{
			int mid = l + r >> 1;
			if(v[bus[i].b][mid - 1].first >= bus[i].t) r = (p = mid) - 1;
			else l = mid + 1;
		}
		if(p == -1) pos[i][0] = 0;
		else pos[i][0] = v[bus[i].b][p - 1].second;
	}
	/*
	for(int i = 1; i <= m; i++)
		cout << bus[i].a << ' ' << bus[i].b << ' ' << bus[i].s << ' ' << bus[i].t << '\n';
	for(int i = 1; i <= m; i++)
		cout << pos[i] << ' ';
	*/
	for(int j = 1; j <= 18; j++)
		for(int i = 1; i <= m; i++)
			pos[i][j] = pos[pos[i][j - 1]][j - 1];
	while(q--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		int l = 1, r = v[y].size(), p = -1;
		while(l <= r)
		{
			int mid = l + r >> 1;
			if(v[y][mid - 1].first >= x) r = (p = mid) - 1;
			else l = mid + 1;
		}
		if(p == -1) {cout << y << '\n'; continue;}
		y = v[y][p - 1].second;
		for(int i = 18; i >= 0; i--)
			if(bus[pos[y][i]].s < z && pos[y][i]) 
				y = pos[y][i];
		if(z <= bus[y].s) cout << belong[y] << '\n'; 
		else if(z <= bus[y].t) cout << bus[y].a << ' ' << bus[y].b << '\n';
		else cout << bus[y].b << '\n';
	}
	return 0;
}