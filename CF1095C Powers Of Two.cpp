#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, cnt = 0;
	cin >> n >> m;
	for(int i = 0; i <= 30; i++)
		if(n & (1 << i))
			cnt++;
	if(cnt <= m && m <= n)
	{
		cout << "YES\n";
		vector<int> v;
		for(int i = 0; i <= 30; i++)
			if(n & (1 << i))
				v.push_back(1 << i);
		for(int i = 30; i >= 0; i--)
		{
			if(n & (1 << i))
			{
				if((1 << i) - 1 <= m - cnt)
				{
					for(int j = 1; j <= (1 << i); j++)
						cout << 1 << ' ';
					cnt += (1 << i) - 1;
					v.pop_back();
				}
				else
				{
					n = (1 << i); m = m - cnt + 1;
					int t = n;
					while(n / t < m)
						t /= 2;
					int num = n / t;
					for(int i = 1; i <= 2 * m - num; i++)
						cout << t << ' ';
					for(int i = 1; i <= num - m; i++)
						cout << t * 2 << ' ';
					v.pop_back();
					break;
				}
			}
		}
		for(int i = 0; i < v.size(); i++)
			cout << v[i] << ' ';
		return 0;
	}
	cout << "NO";
	return 0;
}