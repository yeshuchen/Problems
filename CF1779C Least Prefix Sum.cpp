#include<bits/stdc++.h>
using namespace std;
int T, n, m;
int a[300005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int ans = 0; long long sum = 0;
		priority_queue<int> q;
		priority_queue< int, vector<int>, greater<int> > q1;
		cin >> n >> m;
		for(int i = 1; i <= n; i++)	cin >> a[i];
		if(a[m] > 0 && m > 1) ans++, a[m] = -a[m];
		for(int i = m - 1; i; i--)
		{
			q.push(a[i + 1]); sum += a[i + 1];
			if(sum > 0)
			{
				int x = q.top(); q.pop();
				sum -= 2 * x; ans++;
			}
		}
		sum = 0;
		for(int i = m + 1; i <= n; i++)
		{
			q1.push(a[i]); sum += a[i];
			if(sum < 0)
			{
				int x = q1.top(); q1.pop();
				sum -= 2 * x; ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}