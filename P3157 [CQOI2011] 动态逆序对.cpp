#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, m;
int c[N], pos[N];
struct node {
	int v, pos, time;
} a[N];
int ans[N];
inline void add(int x, int v) {for(int i = x; i <= 50001; i += (i & -i)) c[i] += v;}
inline int ask(int x) {int res = 0; for(int i = x; i; i -= (i & -i)) res += c[i]; return res;}
inline bool cmpv(node x, node y) {return x.v > y.v;}
inline void cdq(int l, int r)
{
	if(l == r) return;
	int mid = l + r >> 1;
	cdq(l, mid); cdq(mid + 1, r);
	sort(a + l, a + mid + 1, cmpv);
	sort(a + mid + 1, a + r + 1, cmpv);
	int i = l, j = mid + 1;
	while(j <= r)
	{
		while(i <= mid && a[i].v > a[j].v) add(a[i].time, 1), i++;
		ans[a[j].time] += ask(50001) - ask(a[j].time);
		j++;
	}
	for(int k = l; k < i; k++) add(a[k].time, -1);
	reverse(a + l, a + mid + 1);
	reverse(a + mid + 1, a + r + 1);
	i = l; j = mid + 1;
	while(i <= mid)
	{
		while(j <= r && a[i].v >= a[j].v) add(a[j].time, 1), j++;
		ans[a[i].time] += ask(50001) - ask(a[i].time - 1);
		i++;
	}
	for(int k = mid + 1; k < j; k++) add(a[k].time, -1);
}
signed main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i].v, pos[a[i].v] = i, a[i].time = 50001;
	for(int i = 1; i <= m; i++)
	{
		int x;
		cin >> x;
		a[pos[x]].time = i;
	}
	cdq(1, n);
	for(int i = 50000; i; i--) ans[i] += ans[i + 1];
	for(int i = 1; i <= m; i++) cout << ans[i] << '\n';
	return 0;
}