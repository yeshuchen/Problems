#include<bits/stdc++.h>
using namespace std;
int n, flag;
int nxt[1000005];
char c[1000005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while(cin >> n)
	{
		if(flag) cout << '\n';
		if(!n) break; flag++;
		cout << "Test case #" << flag << '\n';
		memset(nxt, 0, sizeof(nxt));
		for(int i = 1; i <= n; i++)
			cin >> c[i];
		nxt[1] = 0;
		for(int i = 2; i <= n; i++)
		{
			int p = i - 1;
			while(c[nxt[p] + 1] != c[i] && p) p = nxt[p];
			if(c[nxt[p] + 1] == c[i]) nxt[i] = nxt[p] + 1;
			else nxt[i] = 0;
		}
		for(int i = 1; i <= n; i++)
		{
			if(!nxt[i]) continue;
			if(i % (i - nxt[i]) == 0) cout << i << ' ' << i / (i - nxt[i]) << '\n';
		}
	}
	return 0;
}