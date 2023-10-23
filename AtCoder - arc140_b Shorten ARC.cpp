#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n;
char s[N];
bool vis[N];
int res1, res2;
multiset<int> st;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	s[0] = '@'; s[n + 1] = '#';
	for(int i = 1; i <= n; i++)
	{
		if(s[i] != 'R') continue;
		int p = 1;
		while(s[i - p] == 'A' && s[i + p] == 'C') p++;
		if(p - 1) st.insert(p - 1);
	}
	int cnt = 0;
	while(!st.empty())
	{
		cnt++;
		if(cnt & 1)
		{
			auto it = st.end(); it--;
			st.erase(it);
			int x = *it; x--;
			if(x) st.insert(x);
		}
		else st.erase(st.begin());
	}
	cout << cnt;
	return 0;
}