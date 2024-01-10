#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, sum;
int mx[N], mx2[N];
struct node {
	int w, dis;
} a[N];
bool cmp(node x, node y) {return x.w > y.w;}
signed main()
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i].dis;
	for(int i = 1; i <= n; i++) cin >> a[i].w;
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i++) mx[i] = max(mx[i - 1], 2 * a[i].dis);
	for(int i = n; i; i--) mx2[i] = max(mx2[i + 1], 2 * a[i].dis + a[i].w);
	for(int i = 1; i <= n; i++)
	{
		cout << max(sum + mx2[i], sum + a[i].w + mx[i]) << '\n';
		sum += a[i].w;
	}
	return 0;
}