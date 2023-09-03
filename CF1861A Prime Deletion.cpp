#include<bits/stdc++.h>
using namespace std;
int T;
char s[10];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> s + 1;
		for(int i = 1; i <= 9; i++)
			if(s[i] == '3' || s[i] == '7')
				cout << s[i];
		cout << '\n';
	}
	return 0;
}