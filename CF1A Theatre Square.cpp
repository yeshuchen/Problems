#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, a;
	cin >> n >> m >> a;
	cout << 1ll * ((n + a - 1) / a) * ((m + a - 1) / a);
	return 0;
}