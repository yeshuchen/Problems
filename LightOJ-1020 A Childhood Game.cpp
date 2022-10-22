#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin >> T;
	for(int i = 1; i <= T; i++)
	{
		int a; string n;
		cin >> a >> n;
		cout << "Case " << i << ':' << ' ';
		if(n == "Alice")
		{
			if(a % 3 == 1) cout << "Bob\n";
			else cout << "Alice\n";
		}
		else
		{
			if(a % 3 == 0) cout << "Alice\n";
			else cout << "Bob\n";
		}
	}
	return 0;
}