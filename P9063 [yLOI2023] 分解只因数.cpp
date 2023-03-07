#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		long long v;
		cin >> v;
		cout << ((v & 1) ? "Yes" : "No") << '\n';
	}
	return 0;
}