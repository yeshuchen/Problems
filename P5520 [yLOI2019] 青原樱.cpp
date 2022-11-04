#include<bits/stdc++.h>
using namespace std;
int tp, n, m, p;
long long ans = 1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> tp >> n >> m >> p;
	n = n - m + 1;
	for(int i = n - m + 1; i <= n; i++)
		ans = ans * i % p;
	cout << ans;
	return 0;
}