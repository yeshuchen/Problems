#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int T, n;
int a[N], b[N], id[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i], id[i] = i;
		for(int i = 1; i <= n; i++)
			cin >> b[i], b[i] = a[i] - b[i];
		sort(id + 1, id + n + 1, [](int x, int y) {
			return b[x] == b[y] ? x < y : b[x] > b[y];
		});
		int pos = 0;
		for(int i = 1; i <= n; i++)
			if(b[id[i]] != b[id[i + 1]] || i == n)
			{
				pos = i;
				break;
			}
		cout << pos << '\n';
		for(int i = 1; i <= pos; i++)
			cout << id[i] << ' ';
		cout << '\n';
	}
	return 0;
}