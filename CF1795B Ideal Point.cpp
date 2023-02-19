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
		int n, k, f1 = 0, f2 = 0;
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
		{
			int l, r;
			cin >> l >> r;
			if(l == k) f1 = 1; 
			if(r == k) f2 = 1;
		}
		if(f1 + f2 < 2) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}