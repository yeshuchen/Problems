#include<bits/stdc++.h>
using namespace std;
int T, x, y, n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> x >> y >> n;
		if(y - x < n * (n - 1) / 2) {cout << -1 << '\n'; continue;}
		stack<int> s;
		for(int i = 1; i < n; i++) s.push(y), y -= i;
		s.push(x);
		while(!s.empty()) cout << s.top() << ' ', s.pop();
		cout << '\n';
	}
	return 0;
}