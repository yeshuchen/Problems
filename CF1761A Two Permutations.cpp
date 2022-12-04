#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if(a == b && c == a || b + c <= a - 2) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}