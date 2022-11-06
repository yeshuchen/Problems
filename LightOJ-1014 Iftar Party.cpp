#include<bits/stdc++.h>
using namespace std;
int T;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	for(int c = 1; c <= T; c++)
	{
		cout << "Case " << c << ": ";
		int n, k;
		cin >> n >> k;
		if(!n && !k) {cout << 1 << '\n'; continue;}
		n -= k;
		if(n <= k) cout << "impossible\n";
		else
		{
			vector<int> v;
			for(long long i = 1; i * i <= n; i++)
				if(n % i == 0)
				{
					int p = n / i;
					if(i > k) v.push_back(i);
					if(p == i) continue;
					if(p > k) v.push_back(p);
				}
			sort(v.begin(), v.end());
			for(int i = 0; i < v.size() - 1; i++)
				cout << v[i] << ' ';
            cout << v[v.size() - 1] << '\n';
		}
	}
	return 0;
}