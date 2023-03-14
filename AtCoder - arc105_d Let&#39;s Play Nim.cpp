#include<bits/stdc++.h>
using namespace std;
int T;
int a[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		int n;
		map<int, int> m;
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i], m[a[i]]++;
		if(n & 1) {cout << "Second\n"; continue;}
		for(int i = 1; i <= n; i++)
			if(m[a[i]] & 1)
			{
				cout << "First\n";
				goto end;
			}
		cout << "Second\n";
		end:;
	}
	return 0;
}