#include<bits/stdc++.h>
using namespace std;
int n;
struct node {
	int l, r;
} t[100005];
int l[100005], r[100005], vis[100005];
inline bool cmp(node x, node y) {return (x.r == y.r ? x.l < y.l : x.r < y.r);}
inline bool check(int w)
{
	int maxpos = 0;
	for(int i = 1; i <= n; i++) l[i] = t[i].l, r[i] = t[i].r, vis[i] = 0;
	int dep = 2e4;
	while(dep--)
	{
		bool ismove = 0;
		for(int i = 1; i <= n; i++)
		{
			if(vis[i]) continue;
			if(l[i] - maxpos > w || r[i] < maxpos - w) continue;
			ismove = 1, vis[i] = 1;
			if(maxpos <= l[i] + w) maxpos += (r[i] - l[i]);
			else maxpos = r[i] + w;
		}
		if(!ismove || maxpos >= 20000) break;
	}
	if(maxpos < 20000) return false;
	return true;
}
int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> t[i].l >> t[i].r, t[i].l *= 2, t[i].r *= 2;
	sort(t + 1, t + n + 1, cmp);
	int L = 0, R = 20000, ans;
	while(L <= R)
	{
		double mid = (L + R) / 2;
		if(check(mid)) R = (ans = mid) - 1;
		else L = mid + 1;
	}
	cout << ans / 2;
	if(ans & 1) cout << ".5";
	return 0;
}