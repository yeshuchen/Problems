#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T, n;
int dis[N], ans[N];
int get(int x, int y)
{
	cout << "? " << x << ' ' << y << endl;
	int res = 0;
	cin >> res;
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int mx = 1;
		cin >> n;
		ans[1] = n;
		for(int i = 2; i <= n; i++)
		{
			if(i & 1) ans[i] = n - ans[i - 1];
			else ans[i] = n - ans[i - 1] + 1;
		}
		cout << "+ " << n + 1 << endl;
		cin >> mx;
		cout << "+ " << n << endl;
		cin >> mx;
		dis[1] = 0;
		for(int i = 2; i <= n; i++)
		{
			dis[i] = get(1, i);
			if(dis[mx] < dis[i]) mx = i;
		}
		dis[mx] = 0;
		for(int i = 1; i <= n; i++)
			if(mx ^ i)
				dis[i] = get(mx, i);
		cout << "! ";
		for(int i = 1; i <= n; i++)
			cout << ans[dis[i] + 1] << ' ';
		for(int i = 1; i <= n; i++)
			cout << ans[n - dis[i]] << ' ';
		cout << endl;
		cin >> mx;
	}
	return 0;
}
/*
2
6
1 4 2 5 3 6
2
1 2
*/