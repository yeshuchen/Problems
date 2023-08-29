#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n;
struct node {
	int a, b;
} t[N];
bool cmp(node x, node y) {return x.b < y.b;}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> t[i].a >> t[i].b;
	sort(t + 1, t + n + 1, cmp);
	int l = 1, res = 0, ans = 0;
	for(int i = n; i >= l; i--)
	{
		if(res >= t[l].b)
		{
			res += t[l].a;
			ans += t[l++].a; i++;
			continue;
		}
		if(res + t[i].a >= t[l].b)
		{
			ans += (t[l].b - res) * 2;
			t[i].a = t[i].a - (t[l].b - res);
			res = t[l].b + t[l].a; ans = ans + t[l].a;
			l++; i++;
		}
		else res += t[i].a, ans += t[i].a * 2;
	}
	cout << ans;
	return 0;
}