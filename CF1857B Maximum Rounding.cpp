#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int T;
char s[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> s + 1;
		int len = strlen(s + 1);
		int pos = len + 1;
		s[0] = '0';
		for(int i = len; i; i--)
			if(s[i] >= '5') pos = i, s[i - 1]++;
		for(int i = pos; i <= len; i++) s[i] = '0';
		pos = (s[0] > '0' ? 0 : 1);
		for(int i = pos; i <= len; i++) cout << s[i];
		cout << '\n';
	}
	return 0;
}