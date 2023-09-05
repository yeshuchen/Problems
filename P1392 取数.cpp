#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int a[805][805];
int s[805], t[805], p[805];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	for(int i = 1; i <= n; i++)
		sort(a[i] + 1, a[i] + m + 1);
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
	for(int cnt = 1; cnt < n; cnt++)
	{
		for(int i = 1; i <= k; i++)
		{
			s[i] = a[cnt][i];
			t[i] = a[cnt + 1][i];
			p[i] = 1;
			q.push(make_pair(s[i] + t[p[i]], i));
		}
		for(int i = 1; i <= k; i++)
		{
			int x = q.top().first, pos = q.top().second; q.pop();
			a[cnt + 1][i] = x; p[pos]++;
			q.push(make_pair(s[pos] + t[p[pos]], pos));
		}
		while(!q.empty()) q.pop();
	}
	for(int i = 1; i <= k; i++)
		cout << a[n][i] << ' ';
	return 0;
}