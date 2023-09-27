#include<bits/stdc++.h>
using namespace std;
int T, n;
inline void ask(int t, int l, int r, int v) {cout << "? " << t << ' ' << l << ' ' << r << ' ' << v << endl << endl;}
int ans[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int pos = 0;
		cin >> n;
		for(int i = 1; i < n; i += 2)
		{
			int x;
			ask(2, i, i + 1, 1);
			cin >> x;
			if(x == 1) {pos = i; break;}
			if(x == 2) 
			{
				ask(2, i + 1, i, 1);
				cin >> x;
				if(x == 1) {pos = i + 1; break;}
			}
		}
		if(!pos) pos = n;
		ans[pos] = 1;
		for(int i = 1; i <= n; i++)
			if(i ^ pos)
				ask(1, pos, i, n - 1), cin >> ans[i];
		cout << "! ";
		for(int i = 1; i <= n; i++)
			cout << ans[i] << ' ';
		cout << endl << endl;
	}
	return 0;
}