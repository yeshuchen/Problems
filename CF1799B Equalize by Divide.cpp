#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int T, n;
struct po {
	int v, id;
} a[N];
struct node {
	int x, y;
} p[N];
inline bool cmp(po x, po y) {return x.v < y.v;}
inline bool check()
{
	sort(a + 1, a + n + 1, cmp);
	return a[1].v == a[n].v;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int tot = 0;
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i].v, a[i].id = i;
		sort(a + 1, a + n + 1, cmp);
		if(a[1].v == 1 && a[n].v != a[1].v) {cout << -1 << '\n'; continue;}
		if(a[1].v == a[n].v)
		{
			cout << 0 << '\n';
			continue;
		}
		while(!check())
		{
			for(int i = 2; i <= n; i++)
				while(a[i].v > a[1].v)
					p[++tot] = {a[i].id, a[1].id}, a[i].v = (a[i].v + a[1].v - 1) / a[1].v;
		}
		cout << tot << '\n';
		for(int i = 1; i <= tot; i++)
			cout << p[i].x << ' ' << p[i].y << '\n';
	}
	return 0;
}