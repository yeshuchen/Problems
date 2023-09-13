#include<bits/stdc++.h>
using namespace std;
int T, n, k;
inline int ask(int pos)
{
	cout << "? " << pos << endl;
	int x; cin >> x;
	return x;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n >> k;
		int pos, res = 0;
		for(pos = 1; n - pos + 1 >= 2 * k; pos += k)
			res ^= ask(pos);
		if(n - pos + 1 == k) {res ^= ask(pos); cout << "! " << res << endl; continue;}
		int y = (n - pos + 1 - k) / 2;
		res ^= ask(pos);
		res ^= ask(pos + y);
		res ^= ask(pos + 2 * y);
		cout << "! " << res << endl;
	}
	return 0;
}