#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m;
set<int> s;
int a[N], f[N];
int sz[N], nxt[N];
vector<int> v[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i], f[i] = -1;
	for(int i = 1; i <= n; i++)
	{
		auto it = s.lower_bound(a[i]);
		if(it == s.end()) s.insert(a[i]), sz[a[i]] = 1;
		else
		{
			sz[a[i]] = sz[*it] + 1;
			nxt[a[i]] = *it;
			s.erase(it); s.insert(a[i]);
		}
		if(sz[a[i]] == m)
		{
			int p = a[i];
			while(p)
			{
				f[p] = i;
				p = nxt[p];
			}
			it = s.lower_bound(a[i]);
			s.erase(it);
		}
	}
	for(int i = 1; i <= n; i++) cout << f[i] << '\n';
	return 0;
}