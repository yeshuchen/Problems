#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int T, n;
struct node {
	int v, id;
} a[N];
long long ans[N];
inline bool cmp(node x, node y) {return x.v < y.v;}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i].v, a[i].id = i;
		sort(a + 1, a + n + 1, cmp);
		for(int i = 1; i <= n; i++)
			ans[a[1].id] += a[i].v - a[1].v + 1;
		for(int i = 2; i <= n; i++)
		{
			ans[a[i].id] = ans[a[i - 1].id];
			ans[a[i].id] -= 1ll * (n - i + 1) * (a[i].v - a[i - 1].v);
			ans[a[i].id] += 1ll * (i - 1) * (a[i].v - a[i - 1].v);
		}
		for(int i = 1; i <= n; i++)
			cout << ans[i] << ' ', ans[i] = 0;
		cout << '\n';
	}
	return 0;
}