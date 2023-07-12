#include<iostream>
using namespace std;
int r, n;
struct node
{
	int f, c, t;
	double w;
} num[1020];
int find()
{
	int mx = 0;
	for(int i = 1; i <= n; i++)
		if(i != r && num[i].w > num[mx].w)
			mx = i;
	return mx;	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	num[0].w = -1;
	while(cin >> n >> r)
	{
		int ans = 0;
		if(!n && !r) break;
		for(int i = 1; i <= n; i++)
		{
			cin >> num[i].c;
			num[i].w = num[i].c;
			num[i].t = 1;
			ans += num[i].c;
		}
		for(int i = 1; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			num[y].f = x;
		}
		for(int i = 1; i < n; i++)
		{
			int now = find(), fa;
			num[now].w = 0;
			fa = num[now].f;
			ans += num[now].c * num[fa].t;
			for(int j = 1; j <= n; j++)
				if(num[j].f == now)
					num[j].f = fa;
			num[fa].c += num[now].c;
			num[fa].t += num[now].t;
			num[fa].w = 1.0 * num[fa].c / num[fa].t;
		}
		cout << ans << '\n';
	}
	return 0;
}
