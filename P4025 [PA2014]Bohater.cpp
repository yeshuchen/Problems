#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
struct node{
	int id, d, a;
}a[N];
int n, m;
vector<int> ans;
inline bool cmp(node x, node y)
{
	if((x.a - x.d) * (y.a - y.d) < 0) return x.a - x.d > 0;
	if(x.a - x.d < 0) return x.a > y.a;
	return x.d < y.d;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		a[i].id = i;
		cin >> a[i].d >> a[i].a;
	}
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++)
	{
		m -= a[i].d;
		ans.push_back(a[i].id);
		if(m <= 0) {cout << "NIE"; return 0;}
		m += a[i].a;
	}
	cout << "TAK\n";
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	return 0;
}