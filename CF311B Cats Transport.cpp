#include<bits/stdc++.h>
#define ls (p << 1)
#define rs (p << 1 | 1)
#define ll long long
using namespace std;
const int N = 2e6 + 5;
int n, m, p;
ll d[N], a[N], s[N], dp[105][200005];
struct line {
	ll x, y;
} ln[N];
double calc(int x, int y) {return 1.0 * (ln[x].y - ln[y].y) / (ln[x].x - ln[y].x);}
int q[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> p;
	for(int i = 2; i <= n; i++) cin >> d[i], d[i] += d[i - 1];
	for(int i = 1; i <= m; i++)
	{
		int x, t;
		cin >> x >> t;
		a[i] = t - d[x];
	}
	sort(a + 1, a + m + 1);
	for(int i = 1; i <= m; i++)
		s[i] = s[i - 1] + a[i], dp[0][i] = 1e18;
	for(int i = 1; i <= p; i++)
	{
		int hd = 1, tl = 0;
		q[++tl] = 0;
		for(int j = 1; j <= m; j++)
		{
			while(tl - hd > 0 && calc(q[hd], q[hd + 1]) < a[j]) hd++;
			ln[j] = {j, dp[i - 1][j] + s[j]};
			while(tl - hd > 0 && calc(q[tl - 1], q[tl]) > calc(q[tl - 1], j)) tl--;
			q[++tl] = j;
			dp[i][j] = dp[i - 1][q[hd]] + a[j] * (j - q[hd]) - (s[j] - s[q[hd]]);
		}
	}
	cout << dp[p][m];
	return 0;
}