#include<bits/stdc++.h>
using namespace std;
int T, n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		set<int> s;
		map< int, vector<int> > m;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			int l, r;
			cin >> l >> r;
			m[l].push_back(r);
			s.insert(l);
		}
		s.insert(1000000007);
		int i = (*s.begin()), flag = 1;
		priority_queue< int, vector<int>, greater<int> > q;
		while(i <= 1000000000)
		{
			for(int j = 0; j < m[i].size(); j++) q.push(m[i][j]);
			int x = q.top(); q.pop();
			if(q.empty()) {i = (*s.lower_bound(i + 1));}
			else
			{
				if(q.top() <= i) {flag = false; break;}
				i++;
			}
		}
		if(!q.empty()) flag = false;
		if(flag) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}