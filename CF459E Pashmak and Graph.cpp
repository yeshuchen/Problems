#include<bits/stdc++.h>
using namespace std;
const int N = 6e5 + 5;
int n, m;
struct node {
	int x, y, z;
} e[N];
int f[N], tmp[N];
bool cmp(node x, node y) {return x.z > y.z;}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
		cin >> e[i].x >> e[i].y >> e[i].z;
	sort(e + 1, e + m + 1, cmp);
	int last = 1;
	for(int i = 1; i <= m; i++)
		if(e[i].z != e[i + 1].z || i == m)
		{
			for(int j = last; j <= i; j++)
				f[e[j].x] = max(f[e[j].x], tmp[e[j].y] + 1);
			for(int j = last; j <= i; j++)
				tmp[e[j].x] = f[e[j].x];
			// for(int i = 1; i <= n; i++)
			// 	cout << f[i] << ' ';
			// cout << '\n';
			last = i + 1;
		}
	int ans = 0;
	for(int i = 1; i <= n; i++) ans = max(ans, f[i]);
	cout << ans;
	return 0;
}