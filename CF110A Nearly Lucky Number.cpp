#include<bits/stdc++.h>
using namespace std;
long long n, res, cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	while(n)
	{
		int x = n % 10;
		res += (x == 4 || x == 7);
		cnt++; n /= 10;
	}
	if(!res) {cout << "NO\n"; return 0;}
	n = res; res = cnt = 0;
	while(n)
	{
		int x = n % 10;
		res += (x == 4 || x == 7);
		cnt++; n /= 10;
	}
	if(res == cnt) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}