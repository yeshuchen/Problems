#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int n, a[305];
bool check(int x)
{
	vector<int> v;
	for(int i = 2; i * i <= x; i++)
		if(x % i == 0)
		{
			int y = x / i;
			v.push_back(i);
			if(i == y) continue;
			v.push_back(y);
		}
	if(v.size() > n) return false;
	return true;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		int s = a[1] * a[n];
		for(int i = 2; i < n; i++)
			if(a[i] * a[n - i + 1] != s)
			{
				cout << -1 << '\n';
				goto end;
			}
		if(!check(s)) {cout << -1 << '\n';}
		else cout << s << '\n';
		end:;
	}
	return 0;
}