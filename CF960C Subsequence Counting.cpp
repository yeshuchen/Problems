#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int ans, p = 1;
vector<int> v;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 29; i >= 1; i--)
	{
		while(n >= (1 << i) - 1)
		{
			n -= ((1 << i) - 1);
			for(int j = 1; j <= i; j++) v.push_back(p);
			p += m;
		}
	}
	cout << v.size() << '\n';
	for(int x : v) cout << x << ' ';
	return 0;
}