#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, ans = 0;
	cin >> n;
	for(int i = 3; i <= n; i++)
		ans += i * (i - 1);
	cout << ans;
	return 0;
}