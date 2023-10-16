#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int T, n, m;
long long s[N];
struct node {
	int x, y;
} t[N];
bool cmp(node x, node y) {return x.x > y.x;}
int main()
{
	cin >> T;
	while(T--)
	{
		long long ans = 0;
		cin >> n >> m;
		for(int i = 1; i <= m; i++)
			cin >> t[i].x >> t[i].y;
		sort(t + 1, t + m + 1, cmp);
		for(int i = 1; i <= m; i++) s[i] = s[i - 1] + t[i].x;
		for(int i = 1; i <= m; i++)
		{
			int l = 1, r = m, pos = 0;
			while(l <= r)
			{
				int mid = l + r >> 1;
				if(t[mid].x >= t[i].y) l = (pos = mid) + 1;
				else r = mid - 1;
			}
			if(pos >= n) ans = max(ans, s[n]);
			else if(pos >= i) ans = max(ans, s[pos] + 1ll * (n - pos) * t[i].y);
			else ans = max(ans, s[pos] + t[i].x + 1ll * (n - pos - 1) * t[i].y);
		}
		cout << ans << '\n';
	}
	return 0;
}