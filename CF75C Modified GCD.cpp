#include<bits/stdc++.h>
using namespace std;
int a, b, n;
vector<int> v;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> a >> b >> n;
	int x = __gcd(a, b);
	for(int i = 1; i * i <= x; i++)
	{
		if(x % i != 0) continue;
		v.push_back(i);
		if(i != x / i) v.push_back(x / i);
	}
	sort(v.begin(), v.end());
	for(int i = 1; i <= n; i++)
	{
		int l, r;
		cin >> l >> r;
		for(int j = v.size() - 1; j >= 0; j--)
			if(v[j] >= l && v[j] <= r)
			{
				cout << v[j] << '\n';
				goto here;
			}
		cout << -1 << '\n';
		here:;
	}
	return 0;
}