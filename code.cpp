#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
struct Edge{
	int x, y, z;
}e[N];
struct kruskal_tree{
	int val, ls, rs;
}t[N];
inline bool cmp(Edge x, Edge y)
{
	return x.z < y.z;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++)
		cin >> h[i];
	for(int i = 1; i <= m; i++)
		cin >> e[i].x >> e[i].y >> e[i].z;
	sort(e + 1, e + n + 1, cmp);
	return 0;
}