#include<bits/stdc++.h>
using namespace std;
int T, n, s1, s2;
struct node {
	int r, id;
} a[200005];
inline bool cmp(node x, node y) {return x.r > y.r;}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int w1 = 0, w2 = 0;
		vector<int> v[3];
		cin >> n >> s1 >> s2;
		for(int i = 1; i <= n; i++)
			cin >> a[i].r, a[i].id = i;
		sort(a + 1, a + n + 1, cmp);
		for(int i = 1; i <= n; i++)
		{
			w1 += s1; w2 += s2;
			if(w1 <= w2) v[1].push_back(a[i].id), w2 -= s2;
			else v[2].push_back(a[i].id), w1 -= s1;
		}
		cout << v[1].size() << ' ';
		for(int i = 0; i < v[1].size(); i++) cout << v[1][i] << ' ';
		cout << '\n';
		cout << v[2].size() << ' ';
		for(int i = 0; i < v[2].size(); i++) cout << v[2][i] << ' ';
		cout << '\n';
	}
	return 0;
}