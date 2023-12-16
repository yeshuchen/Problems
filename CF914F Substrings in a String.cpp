#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
char s[N], t[N];
bitset<100001> c[26], f;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> s + 1;
	int len = strlen(s + 1);
	for(int i = 1; i <= len; i++)
		c[s[i] - 'a'][i] = 1;
	int T;
	cin >> T;
	while(T--)
	{
		char ch;
		int op, x, y;
		cin >> op;
		if(op == 2)
		{
			cin >> x >> y >> t;
			len = strlen(t);
			y = y - len + 1;
			f &= c[t[0] - 'a']; f |= c[t[0] - 'a'];
			for(int i = 1; i < len; i++)
				f &= (c[t[i] - 'a'] >> i);
			f <<= (100000 - y);
			f >>= (100000 - (y - x));
			cout << f.count() << '\n';
		}
		else
		{
			cin >> x >> ch;
			c[s[x] - 'a'][x] = 0;
			s[x] = ch;
			c[s[x] - 'a'][x] = 1;
		}
	}
	return 0;
}