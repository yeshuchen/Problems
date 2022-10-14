#include<bits/stdc++.h>
using namespace std;
int n, nxt[10000005];
string s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	cin >> s;
	for(int i = 2; i <= n; i++)
	{
		string t;
		cin >> t;
		int lens = s.size(), lent = t.size();
		string ss = " " + t + "#$%^&*(!*#!&$@*!LWXAKIOI_AND_NOI" + s.substr(max(lens - lent, 0));
		nxt[1] = 0;
		for(int i = 2; i < ss.size(); i++) 
		{
			int p = i - 1;
			while(ss[i] != ss[nxt[p] + 1] && p) p = nxt[p];
			if(ss[nxt[p] + 1] == ss[i]) nxt[i] = nxt[p] + 1;
			else nxt[i] = 0;
		}
		for(int i = nxt[ss.size() - 1]; i < t.size(); i++)
			s += t[i];	
	}
	cout << s;
	return 0;
}