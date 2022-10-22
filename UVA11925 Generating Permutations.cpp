#include<bits/stdc++.h>
using namespace std;
const int N =  1e6 + 5;
int n, a[N], q[N];
int main()
{
	while(cin >> n)
	{
		int head = 1, tail = 0;
		vector<int> v; bool flag = 1;
		if(!n) break;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i < n; i++)
			for(int j = n; j >= 1; j--)
			{
				v.push_back(2);
				if(j != n && a[j + 1] < a[j])
					swap(a[j], a[j + 1]), v.push_back(1);
			}
		reverse(v.begin(), v.end());
		for(int i = 0; i < v.size(); i++) cout << v[i];
		cout << '\n';
	}
}