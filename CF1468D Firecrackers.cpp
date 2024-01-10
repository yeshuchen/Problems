#include<bits/stdc++.h>
using namespace std;
int T, n, m, a, b;
int A[200005];
bool check(int x)
{
	int nb = b;
	if(b < a)
	{
		nb += x;
		if(nb >= a) return false;
		for(int i = x; i; i--)
		{
			if(n - b < A[i] + (x - i + 1)) return false;
		}
	}
	if(b > a)
	{
		nb -= x;
		if(nb <= a) return false;
		for(int i = x; i; i--)
			if(b - 1 < A[i] + (x - i + 1))
				return false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int ans = 0;
		cin >> n >> m >> a >> b;
		for(int i = 1; i <= m; i++)
			cin >> A[i];
		sort(A + 1, A + m + 1);
		int l = 1, r = m;
		while(l <= r)
		{
			int mid = l + r >> 1;
			if(check(mid)) l = (ans = mid) + 1;
			else r = mid - 1;
		}
		cout << ans << '\n'; 
	}
	return 0;
}