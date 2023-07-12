#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int a, b, ans;
		cin >> a >> b;
		if(a == 1 && b == 2) ans = 3;
		else if(a == 1) ans = 2;
		else ans = 1;
		cout << ans << '\n';
	}
	return 0;
}