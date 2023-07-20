#include<bits/stdc++.h>
using namespace std;
int n, m;
struct node {
	int a, c;
} t[100005];
inline bool cmp(node x, node y) {return x.c < y.c;}
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
		cin >> t[i].a >> t[i].c;
	sort(t + 1, t + m + 1, cmp);
	long long ans = 0;
	for(int i = 1; i <= m; i++)
	{
		ans += 1ll * (n - __gcd(n, t[i].a)) * t[i].c;
		n = __gcd(n, t[i].a);
		if(n == 1) break;
	}
	if(n > 1) cout << -1;
	else cout << ans;
	return 0;
}