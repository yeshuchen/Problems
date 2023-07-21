#include<bits/stdc++.h>
using namespace std;
struct node {
	int l, r, id;
} t[1000005];
int a[100005];
int n, q, res, sz;
int cnt[100005], ans[1000005];
inline bool cmp(node x, node y) {return (x.l / sz == y.l / sz ? x.r < y.r : x.l < y.l);}
inline void add(int x)
{
	cnt[a[x]]++;
	if(!(cnt[a[x]] & 1)) res++;
}
inline void del(int x)
{
	if(!(cnt[a[x]] & 1)) res--;
	cnt[a[x]]--;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n; sz = sqrt(n);
	for(int i = 1; i <= n; i++) cin >> a[i];
	cin >> q;
	for(int i = 1; i <= q; i++)
		cin >> t[i].l >> t[i].r, t[i].id = i;
	sort(t + 1, t + q + 1, cmp);
	int l = 1, r = 0;
	for(int i = 1; i <= q; i++)
	{
		while(l < t[i].l) del(l++);
		while(l > t[i].l) add(--l);
		while(r < t[i].r) add(++r);
		while(r > t[i].r) del(r--);
		ans[t[i].id] = res;
	}
	for(int i = 1; i <= q; i++) cout << ans[i] << '\n';
	return 0;
}