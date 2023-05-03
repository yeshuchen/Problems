#include<bits/stdc++.h>
using namespace std;
long long n, m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	if(m % 2 != n % 2 || n > m) {cout << -1; return 0;}
	if(n == m)
	{
		if(!n) cout << 0;
		else cout << 1 << '\n' << n;
	}
	else
	{
		long long del = (m - n) / 2;
		if(!(del & n)) cout << 2 << '\n' << (del ^ n) << ' ' << del;
		else cout << 3 << '\n' << n << ' ' << del << ' '<< del;
	}
	return 0;
}