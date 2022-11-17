#include<bits/stdc++.h>
using namespace std;
int T;
int check(int x) {return 2 * x - (x & 1);}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int n, m;
		cin >> n >> m;
		if(n > m) swap(n, m);
		if(n == 1 && m > 2) {cout << -1 << '\n'; continue;}
		if(n == 1) {cout << m - 1 << '\n'; continue;}
		cout << check(m - n) + 2 * (n - 1) << '\n';
	}
	return 0;
}