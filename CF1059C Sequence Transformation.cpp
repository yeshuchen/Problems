#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	if(n <= 3)
	{
		for(int i = 1; i < n; i++) cout << 1 << ' ';
		cout << n << ' ';
		return 0;
	}
	int p = 1, t = n;
	while(n > 3)
	{
		for(int i = 1; i <= (n + 1) / 2; i++) cout << p << ' ';
		p <<= 1;
		n >>= 1;
	}
	for(int i = 1; i < n; i++) cout << p << ' ';
	cout << n * p;
	return 0;
}