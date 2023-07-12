#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, sz;
int a[N], bl[N], tag[N];
vector< pair<int, int> > v[1005];
inline int find(int p, int l, int r, int x)
{
	int pos = 0;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(v[p][mid].first < x) l = mid + 1;
		else r = (pos = mid) - 1; 
	}
	return pos;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	sz = sqrt(n);
	for(int i = 1; i <= n; i++)
		cin >> a[i], bl[i] = (i - 1) / sz + 1;
	for(int i = 1; i <= n; i++)
		v[bl[i]].push_back(make_pair(a[i], i));
	for(int i = 1; i <= bl[n]; i++)
		sort(v[i].begin(), v[i].end());
	for(int i = 1; i <= m; i++)
	{
		char op; int l, r, x;
		cin >> op >> l >> r >> x;
		if(op == 'A')
		{
			int res = 0;
			for(int i = bl[l] + 1; i < bl[r]; i++)
			{
				int tmp = x - tag[i];
				if(tmp > v[i][v[i].size() - 1].first) continue;
				int pos = find(i, 0, v[i].size() - 1, tmp);
				res += (v[i].size() - pos);
			}
			int tmp = x - tag[bl[l]];
			for(int i = 0; i < v[bl[l]].size(); i++)
				if(v[bl[l]][i].second >= l && v[bl[l]][i].second <= r && v[bl[l]][i].first >= tmp)
					res++;
			tmp = x - tag[bl[r]];
			if(bl[l] != bl[r])
			{
				for(int i = 0; i < v[bl[r]].size(); i++)
					if(v[bl[r]][i].second >= l && v[bl[r]][i].second <= r && v[bl[r]][i].first >= tmp)
						res++;
			}
			cout << res << '\n';
		}
		else
		{
			for(int i = bl[l] + 1; i < bl[r]; i++)
				tag[i] += x;
			for(int i = 0; i < v[bl[l]].size(); i++)
				if(v[bl[l]][i].second >= l && v[bl[l]][i].second <= r)
					v[bl[l]][i].first += x;
			sort(v[bl[l]].begin(), v[bl[l]].end());
			if(bl[l] != bl[r])
			{
				for(int i = 0; i < v[bl[r]].size(); i++)
					if(v[bl[r]][i].second >= l && v[bl[r]][i].second <= r)
						v[bl[r]][i].first += x;
				sort(v[bl[r]].begin(), v[bl[r]].end());
			}
		}
	}
	return 0;
}