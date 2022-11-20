#include<bits/stdc++.h>
using namespace std;
int n;
long long res = 1;
vector<int> v;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		if(__gcd(i, n) == 1)
		{
			v.push_back(i);
			res *= i;
			res %= n;
		}
	if(res > 1) cout << v.size() - 1 << '\n';
	else cout << v.size() << '\n';
	for(int i = 0; i < v.size(); i++)
		if(v[i] != res || res == 1)
			cout << v[i] << ' ';
	return 0;
}