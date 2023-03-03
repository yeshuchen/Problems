#include<queue>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
struct node{
	int l, p, s;
}a[100005];
int n, k;
int f[205][20000];
inline bool cmp(node x, node y) {return x.s < y.s;}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= k; i++)
		cin >> a[i].l >> a[i].p >> a[i].s;
	sort(a + 1, a + k + 1, cmp);
	for(int i = 1; i <= k; i++)
	{
		priority_queue< pair<int, int> > q;
		for(int j = max(a[i].s - a[i].l, 0ll); j < a[i].s; j++)
			q.push(make_pair(f[i - 1][j] - a[i].p * j, j));
		for(int j = 1; j <= n; j++)
		{
			f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			if(j < a[i].s) continue;
			while(!q.empty() && q.top().second < j - a[i].l) q.pop();
			if(q.empty()) continue;
			f[i][j] = max(f[i][j], q.top().first + a[i].p * j); 
		}
	}
	cout << f[k][n];
	return 0;
} 