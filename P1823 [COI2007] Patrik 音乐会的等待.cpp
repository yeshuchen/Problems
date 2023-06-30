#include<bits/stdc++.h>
using namespace std;
long long n, ans;
stack< pair<int, int> > s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int h;
		cin >> h;
		pair<int, int> p(h, 1);
		while(!s.empty() && s.top().first <= h)
		{
			ans += s.top().second;
			if(s.top().first == h) p.second += s.top().second;
			s.pop();
		}
		if(!s.empty()) ans++;
		s.push(p);
	}
	cout << ans;
	return 0;
}