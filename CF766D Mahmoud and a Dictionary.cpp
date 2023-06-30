#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
string s;
int n, m, q, tot;
int f[N];
map<string, int> a;
inline int find(int k) {return f[k] == k ? k : f[k] = find(f[k]);}
inline void merge(int x, int y)
{
	int fx = find(x), fy = find(y);
	if(fx == fy) return;
	f[fx] = fy;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	for(int i = 1; i <= 2 * n; i++) f[i] = i;
	for(int i = 1; i <= n; i++)
		cin >> s, a[s] = ++tot;
	for(int i = 1; i <= m; i++)
	{
		int op;
		string s1, s2;
		cin >> op >> s1 >> s2;
		if(op == 1)
		{
			if(find(a[s1]) == find(a[s2] + n)) {cout << "NO\n"; continue;}
			merge(a[s1], a[s2]);
			merge(a[s1] + n, a[s2] + n);
			cout << "YES\n";
		}
		else
		{
			if(find(a[s1]) == find(a[s2])) {cout << "NO\n"; continue;}
			merge(a[s1] + n, a[s2]);
			merge(a[s1], a[s2] + n);
			cout << "YES\n";
		}
	}
	for(int i = 1; i <= q; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		if(find(a[s1]) == find(a[s2])) cout << 1 << '\n';
		else if(find(a[s1] + n) == find(a[s2])) cout << 2 << '\n';
		else cout << 3 << '\n';
	}
	return 0;
}