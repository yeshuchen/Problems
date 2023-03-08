#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node{
	int v, pos;
}a[100005];
int ans;
int f[100005], temp[100005];
inline bool cmp(node x, node y) {return x.v < y.v;}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i].v, a[i].pos = i;
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++)
		temp[a[i].pos] = i,
		f[i] = f[i - 1] + a[i].v;
	int maxn = 0;
	for(int i = n; i; i--)
	{
		int p = temp[i];
		if(p < maxn) continue;
		ans += (f[p] - f[maxn - 1] + a[p].v * (n - p) - a[maxn - 1].v * (n - maxn + 1)) * a[p].pos;
		maxn = p + 1;
	}
	cout << ans;
	return 0;
}