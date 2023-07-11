#include<bits/stdc++.h>
using namespace std;
int T;
int m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		string s, s1, s2;
		cin >> s;
		cin >> m;
		cin >> s1 >> s2;
		int last = 0;
		for(int i = 0; i < m; i++)
		{
			int maxn = 0;
			for(int j = s1[i]; j <= s2[i]; j++)
			{
				int pos = s.find(j, last);
				if(pos > s.size())
				{
					cout << "YES\n";
					goto end;
				}
				maxn = max(pos, maxn);
			}
			last = maxn + 1;
		}
		cout << "NO\n";
		end:;
	}
	return 0;
}