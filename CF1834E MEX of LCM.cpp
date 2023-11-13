#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int T, n;
int a[N];
long long lcm(int x, int y) {return 1ll * x / __gcd(x, y) * y;}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		set<int> s, ans;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = n; i; i--)
		{
			set<int> tmp;
			for(int x : s)
			{
				if(lcm(x, a[i]) > 1e9) continue;
				tmp.insert(lcm(x, a[i]));
			}
			tmp.insert(a[i]); s.clear();
			for(int x : tmp) s.insert(x), ans.insert(x);
		}
		int pos = 1;
		for(int x : ans)
		{
			if(x == pos) pos++;
			else break;
		}
		cout << pos << '\n';
	}
	return 0;
}