#include<bits/stdc++.h>
using namespace std;
int n, m, need;
struct node{
	int x, y, z, col;
} e[200005], tmp[200005];
int sum, f[200005];
inline int find(int k) {return f[k] == k ? k : f[k] = find(f[k]);}
inline bool cmp(node x, node y) {return (x.z == y.z ? x.col < y.col : x.z < y.z);}
inline int check(int w)
{
	int res = 0, cnt = 0; sum = 0;
	for(int i = 1; i <= n + 1; i++) f[i] = i;
	for(int i = 1; i <= m; i++) tmp[i] = e[i];
		for(int i = 1; i <= m; i++)
			if(!tmp[i].col)
				tmp[i].z += w;
	sort(tmp + 1, tmp + m + 1, cmp);
	for(int i = 1; i <= m; i++)
	{
		int fx = find(tmp[i].x), fy = find(tmp[i].y);
		if(fx == fy) continue;
		f[fx] = fy;
		cnt++;
		sum += tmp[i].z;
		res += (tmp[i].col == 0);
		if(cnt == n - 1) break;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> need;
	for(int i = 1; i <= m; i++)
	{
		cin >> e[i].x >> e[i].y >> e[i].z >> e[i].col;
		e[i].x++; e[i].y++;
	}
	int l = -111, r = 111, ans = 0;
	while(l <= r)
	{
		int mid = l + r >> 1;
		
		int fc = check(mid);
		if(fc >= need)
		{
			ans = sum - need * mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans;
	return 0;
}
