#include<bits/stdc++.h>
using namespace std;
int T, n;
int main()
{
	cin >> T;
	while(T--)
	{
		cin >> n;
		int k = (1 << (int)(log2(n)));
		int tmp = n - k; queue<int> q;
		q.push(n);
		while(n > k)
		{
			n -= (tmp & -tmp);
			tmp -= (tmp & -tmp);
			q.push(n);
		}
		n /= 2;
		while(n)
		{
			q.push(n);
			n /= 2;
		}
		cout << q.size() << '\n';
		while(!q.empty()) cout << q.front() << ' ', q.pop();
		cout << '\n';
	}
	return 0;
}