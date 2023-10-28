#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n, x;
int a[N];
vector<int> v;
bool check(int de, int num)
{
	vector<int> v;
	int res = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] & num)
		{
			v.push_back(a[i]);
			if(!res) res = a[i];
			else res &= a[i];
		}
	}
	if(!res) return false;
	for(int i = 0; i < de; i++)
		if(res & (1 << i)) return false;
	cout << v.size() << '\n';
	for(int x : v) cout << x << ' ';
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 30; i >= 0; i--)
		if(check(i, (1 << i)))
			return 0;
	return 0;
}