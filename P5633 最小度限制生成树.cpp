#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int n, m, s, k;
struct edge {
	int x, y, z;
} e[N];
int f[N], vis[N], ans;
vector<edge> v1, v2;
int find(int k) {return f[k] == k ? k : f[k] = find(f[k]);}
int check(int w)
{
	ans = 0; int cnt = 0;
	int p1 = 0, p2 = 0, num = 0;
	for(int i = 1; i <= m; i++) vis[i] = 0;
	while(p1 < v1.size() && p2 < v2.size())
	{
		if(v1[p1].z + w <= v2[p2].z)
		{
			num++;
			e[num] = v1[p1++];
			e[num].z += w; vis[num] = 1;
		}
		else e[++num] = v2[p2++];
	}
	while(p1 < v1.size()) num++, e[num] = v1[p1++], e[num].z += w, vis[num] = 1;
	while(p2 < v2.size()) e[++num] = v2[p2++];
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= m; i++)
	{
		int x = find(e[i].x), y = find(e[i].y);
		if(x == y) continue;
		f[y] = x;
		ans += e[i].z;
		cnt += vis[i];
	}
	return cnt;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> s >> k;
	for(int i = 1; i <= m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		if(x == s || y == s) v1.push_back({x, y, z});
		else v2.push_back({x, y, z});
	}
	sort(v1.begin(), v1.end(), [](edge x, edge y) {return x.z < y.z;});
	sort(v2.begin(), v2.end(), [](edge x, edge y) {return x.z < y.z;});
	int l = -1e9, r = 1e9, pos;
	if(check(l) < k || check(r) > k) {cout << "Impossible"; return 0;}
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(check(mid) < k) r = mid - 1;
		else l = (pos = mid) + 1;
	}
	int cnt = check(pos);
	cout << ans - k * pos;
	return 0;
}