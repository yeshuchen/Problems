#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 4;
int n, tot;
int d[N];
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
	ver[++tot] = y;
	nxt[tot] = head[x];
	head[x] = tot;
}
string s[N];
vector<int> v;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	for(int i = 1; i < n; i++)
	{
		string a = s[i], b = s[i + 1];
		int len = min(a.size(), b.size());
		for(int j = 0; j <= len; j++)
		{
			if(j == len)
			{
				if(a.size() > b.size())
				{
					cout << "Impossible\n";
					return 0;
				}
				break;
			}
			if(a[j] != b[j])
			{
				add(a[j] - 'a' + 1, b[j] - 'a' + 1), d[b[j] - 'a' + 1]++;
				break;
			}
		}
	}
	queue<int> q;
	for(int i = 1; i <= 26; i++)
		if(!d[i])
			q.push(i);
	int cnt = 0;
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		v.push_back(x); cnt++;
		for(int i = head[x]; i; i = nxt[i])
		{
			int y = ver[i];
			d[y]--;
			if(!d[y]) q.push(y);
		}
	}
	if(cnt < 26) {cout << "Impossible"; return 0;}
	for(int i = 0; i < v.size(); i++)
		cout << (char)(v[i] + 'a' - 1);
	return 0;
}