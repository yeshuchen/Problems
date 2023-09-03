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
		int n, a, l;
		bool flag = 0;
		cin >> n >> a >> l; int mx = a;
		if(a >= n) flag = 1;
		for(int i = 1; i <= l; i++)
		{
			char ch;
			cin >> ch;
			if(ch == '-') a--;
			if(ch == '+') a++, mx++;
			if(a >= n) flag = 1;
		}
		if(mx >= n)
		{
			if(!flag) cout << "MAYBE\n";
			else cout << "YES\n";
		}
		else cout << "NO\n";
	}
	return 0;
}