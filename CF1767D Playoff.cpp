#include<bits/stdc++.h>
using namespace std;
int n, l = 1, r = 1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		char c;
		cin >> c;
		if(c == '1') l *= 2;
		else r *= 2;
	}
	for(int i = l; i <= (1 << n) - r + 1; i++)
		cout << i << ' ';
	return 0;
}