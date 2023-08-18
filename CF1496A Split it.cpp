#include<bits/stdc++.h>
using namespace std;
int T, n, s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		char c[105];
		cin >> n >> s;
		int l = 1;
		for(int i = 1; i <= n; i++) cin >> c[i];
		if(n - 2 * s == 0) {cout << "NO\n"; continue;}
		while(l <= n / 2 && c[l] == c[n - l + 1]) l++; l--;
		cout << (l >= s ? "YES\n" : "NO\n");
	}
	return 0;
}