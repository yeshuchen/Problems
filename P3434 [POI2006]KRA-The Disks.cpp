#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, m;
int a[N], minn[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;	
	int pos = 1;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] < a[pos]) pos = i;
		minn[i] = a[pos];
	}
	int x;
	for(int i = 1; i < m; i++)
	{
		cin >> x;
		int l = 1, r = n;
		while(l < r)
		{
			int mid = l + r >> 1;
			if(minn[mid] >= x) l = mid + 1;
			else r = mid;
		}
		if(a[l] >= x) n = l - 1;
		else n = l - 2;
	}
	cin >> x;
	if(n < 1 || minn[1] < x) {cout << 0; return 0;}
	int l = 1, r = n;
	while(l < r)
	{
		int mid = l + r >> 1;
		if(minn[mid] >= x) l = mid + 1;
		else r = mid;
	}
	if(minn[l] >= x) cout << l;
	else cout << l - 1;
	return 0;
}