#include<bits/stdc++.h>
using namespace std;
int T;
char c[1000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> c + 1;
		int n = strlen(c + 1);
		for(int i = 1; i <= n; i++)
		{
			if(i & 1) cout << (c[i] == 'a' ? 'b' : 'a');
			else cout << (c[i] == 'z' ? 'y' : 'z');
		}
		cout << '\n';
	}
	return 0;
}