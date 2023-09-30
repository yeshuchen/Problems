#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m;
struct node {
	int a, b;
} t[N];
int ans[N];
inline bool cmp(node x, node y) {return x.a < y.a;}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> t[i].a >> t[i].b;
	sort(t + 1, t + n + 1, cmp);
	int pos = 1, minn = INT_MAX, maxn = 0;
	for(int i = 1; i <= m; i++)
	{
		while(i > t[pos].a && pos <= n)
		{
			minn = min(minn, t[pos].b);
			maxn = max(maxn, t[pos].b);
			pos++;
		}
		if(i > minn) break;
		ans[max(t[n].a, maxn) - i + 1]++;
		ans[m - i + 2]--;
	}
	for(int i = 1; i <= m; i++)
		ans[i] += ans[i - 1], cout << ans[i] << ' ';
	return 0;
}