#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	set<int> s;
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int op, x;
		cin >> op >> x;
		if(op == 1)
		{
			if((*s.lower_bound(x)) == x) cout << "Already Exist\n";
			else s.insert(x);
		}
		else
		{
			if(s.empty()) {cout << "Empty\n"; continue;}
			auto it = s.lower_bound(x);
			int t1 = INT_MAX, t2;
			if(it != s.end()) t1 = *it;
			if(it != s.begin()) it--;
			t2 = *it;
			if(abs(x - t2) <= abs(x - t1)) cout << t2 << '\n', s.erase(it);
			else cout << t1 << '\n', s.erase(++it);
		}
	}
	return 0;
}