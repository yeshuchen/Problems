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
	int last = n;
	for(int i = 1; i <= m; i++)
	{
		int x;
		cin >> x;
		for(int j = last; j >= 0; j--)
		{
			if(minn[j] >= x)
			{
				last = j - 1;
				break;
			}
			if(j == 0) {cout << 0; return 0;}
		}
	}
	cout << last + 1;
	return 0;
}