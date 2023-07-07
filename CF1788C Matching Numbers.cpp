#include<bits/stdc++.h>
using namespace std;
int T, n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		if(n & 1)
		{
			cout << "Yes\n";
			for(int i = (n + 1) / 2, j = n + 1; i; i--, j += 2)
				cout << i << ' ' << j << '\n';
			for(int i = n, j = n + 2; i > (n + 1) / 2; i--, j += 2)
				cout << i << ' ' <<  j << '\n';
		}
		else cout << "No\n";
	}	
	return 0;
} 
