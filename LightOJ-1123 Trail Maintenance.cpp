#include<bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
struct node{
	int x, y, z;
}e[N];
int n, m, res;
int f[N];
inline int find(int k) {return f[k] == k ? k : f[k] = find(f[k]);}
inline bool cmp(node x, node y) {return x.z < y.z;}
inline void init()
{
	for(int i = 1; i <= n; i++)
		f[i] = i;
}
inline int kruskal()
{
	int cnt = 0, ans = 0, pos = -1;
	init();
	sort(e + 1, e + res + 1, cmp);
	for(int i = 1; i <= res; i++)
	{
		int x = e[i].x, y = e[i].y;
		int fx = find(x), fy = find(y);
		if(fx == fy) {pos = i; continue;}
		cnt++; ans += e[i].z;
		f[fx] = fy;
	}
	if(pos != -1) e[pos] = e[res--];
	if(cnt == n - 1) return ans;
	else return -1;
}
int main()
{
	int T;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	for(int op = 1; op <= T; op++)
	{
		res = 0;
		cout << "Case " << op << ":\n";
		cin >> n >> m;
		for(int i = 1; i <= m; i++)
		{
			res++;
			cin >> e[res].x >> e[res].y >> e[res].z;
			cout << kruskal() << '\n';
		}
	}
	return 0;
}