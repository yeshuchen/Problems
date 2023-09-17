#include<bits/stdc++.h>
using namespace std;
int n, cnt;
map<string, int> m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int op;
		string name;
		cin >> op;
		if(op == 1)
		{
			int score;
			cin >> name >> score;
			if(!m[name]) cnt++;
			m[name] = score;
			cout << "OK\n";
		}
		if(op == 2)
		{
			cin >> name;
			if(m[name]) cout << m[name] << '\n';
			else cout << "Not found\n";
		}
		if(op == 3)
		{
			cin >> name;
			if(!m[name]) cout << "Not found\n";
			else m[name] = 0, cnt--, cout << "Deleted successfully\n";
		}
		if(op == 4) cout << cnt << '\n';
	}
	return 0;
}