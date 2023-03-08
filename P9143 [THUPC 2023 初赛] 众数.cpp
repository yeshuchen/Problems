#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct node{
	int v, pos;
}a[100005];
int ans, sum;
int f[100005], temp[100005];
inline bool cmp(node x, node y) {return x.v > y.v;}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i].v, a[i].pos = i;
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++)
		temp[a[i].pos] = i;
	for(int i = n; i; i--)
		f[i] = f[i + 1] + a[i].v;
	int minn = n;
	for(int i = n; i; i--)
	{
		int p = temp[i];
		if(p > minn) continue;
		ans += (f[p] - f[minn + 1] + a[p].v * (p - 1) - sum * minn) * i;
		minn = p - 1; sum = a[p].v;
	}
	cout << ans;
	return 0;
}