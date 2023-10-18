#include<bits/stdc++.h>
#define int long long
using namespace std;
int p, b, n;
map<int, int> mp;
signed main()
{
	cin >> p >> b >> n;
	int sz = sqrt(p);
	int base = n;
	for(int i = 0; i < sz; i++)
	{
		mp[base] = i;
		base = base * b % p;
	}
	int tmp = 1; base = 1;
	for(int i = 0; i < sz; i++) tmp = tmp * b % p;
	for(int i = sz; i <= p; i += sz)
	{
		base = base * tmp % p;
		if(mp[base]) {cout << i - mp[base]; return 0;}
	}
	cout << "no solution";
}