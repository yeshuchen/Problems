#include<bits/stdc++.h>
using namespace std;
struct node{
	int x, y;
}p[100005];
int ans[200005];
inline bool cmp(node x, node y) {return (x.x == y.x ? x.y < y.y : x.x < y.x);}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> p[i].x >> p[i].y;
		if(p[i].x > p[i].y) swap(p[i].x, p[i].y);
	}
	sort(p + 1, p + m + 1, cmp);
	if(n == 1) {cout << "NO\n"; return 0;}
	if(n > 500 || n * (n - 1) / 2 != m)
	{
		cout << "YES\n";
		int l = 1, r = 2;
		for(int i = 1; i <= m; i++)
		{
			if(p[i].x == l && p[i].y == r) r++;
			else break;
			if(r > n) l++, r = l + 1;
		}
		int pos = 2;
		ans[l] = 1; ans[r] = 2;
		for(int i = 1; i <= n; i++)
			if(!ans[i]) ans[i] = ++pos;
		for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
		cout << '\n'; ans[r] = 1;
		for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
	}
	else cout << "NO\n";
	return 0;
}