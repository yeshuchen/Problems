#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int n, pos;
int a[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 2; i <= n; i += 2) cin >> a[i];
	for(int i = 1; i <= n; i += 2)
	{
		int x = a[i + 1], tmp = -1, res = -1;
		for(int j = 1; j * j <= x; j++)
		{
			if(x % j) continue;
			int k = x / j;
			if((j + k) & 1) continue;
			int ed = j + k >> 1;
			int st = ed - j;
			if(st > pos) tmp = st, res = ed;
		}
		if(!~tmp) {cout << "No"; return 0;}
		a[i] = tmp * tmp - pos * pos;
		pos = res;
	}
	cout << "Yes\n";
	for(int i = 1; i <= n; i++) cout << a[i] << ' ';
	return 0;
}