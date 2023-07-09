#include<bits/stdc++.h>
#define int long long
const int mod = 1e9 + 7;
using namespace std;
char c[100005];
int p[100005], f[100005];
vector<int> v;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> c + 1;
	int n = strlen(c + 1);
	p[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		p[i] = p[i - 1] * 3 % mod;
		if(c[i] == '1') v.push_back(i);
	}
	f[v.size()] = 1;
	for(int i = v.size() - 1; i >= 0; i--)
	{
		int x = v[i];
		f[i] = (p[n - x] + 2 * f[i + 1]) % mod;
	}
	cout << f[0];
	return 0;
}