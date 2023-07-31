#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
struct node {
	int s, d;
} a[N];
int n, p, ans;
inline bool cmp(node x, node y)
{
	if(max(x.d, x.s) == max(y.d, y.s)) return x.s < y.s;
	else return max(x.d, x.s) < max(y.d, y.s);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> p;
	for(int i = 1; i <= n; i++)
		cin >> a[i].s >> a[i].d;
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++)
	{
		if(a[i].s < p) continue;
		ans++; p = max(p, a[i].d);
	}
	cout << ans;
	return 0;
}