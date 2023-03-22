#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005], f[100005], pre[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	stack<int> s;
	for(int i = n; i; i--)
	{
		while(!s.empty() && a[i] > a[s.top()]) f[s.top()] = i, s.pop();
		s.push(i);
	}
	for(int i = 1; i <= n; i++) pre[i] = pre[f[i]] + 1;
	for(int i = 1; i <= n; i++)
		cout << pre[i - 1] << '\n';
	return 0;
}