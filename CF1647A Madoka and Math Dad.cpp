#include<bits/stdc++.h>
using namespace std;
int T;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		if(n % 3 == 1) cout << 1;
		for(int i = 1; i <= n / 3; i++) cout << 21;
		if(n % 3 == 2) cout << 2;
		cout << '\n';
	}
	return 0;
}