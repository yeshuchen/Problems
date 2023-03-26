#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int p[505];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		vector<int> v;
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> p[i];
		for(int i = 1; i < n - 2; i++)
		{
			int pos;
			for(int j = 1; j <= n; j++)
				if(p[j] == i)
				{
					pos = j - 1;
					break;
				}
			if(pos == i - 1) continue;
			if(pos + v.size() + 1 & 1)
			{
				if(pos != n - 1)
				{
					v.push_back(pos + 1), swap(p[pos + 1], p[pos + 2]);
					v.push_back(pos); swap(p[pos], p[pos + 1]);
					pos++;
				}
				else
				{
					v.push_back(pos - 1);
					swap(p[pos - 1], p[pos]);
				}
			}
			for(int j = pos; j >= i; j--) v.push_back(j), swap(p[j], p[j + 1]);
		}
		while(p[n - 2] != n - 2 || p[n - 1] != n - 1 || p[n] != n)
		{
			if(v.size() + n & 1) v.push_back(n - 2), swap(p[n - 2], p[n - 1]);
			else v.push_back(n - 1), swap(p[n - 1], p[n]);
		} 
		cout << v.size() << '\n';
		for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';
		cout <<'\n';
	}
	return 0;
}