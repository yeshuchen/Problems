#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, k;
int a[N], ans;
vector<int> v[N];
int main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = n; i; i--)
		v[a[i] % k].push_back(a[i]);
	for(int x = 0; x < k; x++)
		for(int y = 0; y < k; y++)
		{
			int i = x, j = y;
			int K = (2 * k - i - j) % k;
			if(i < j) swap(i, j);
			if(i < K) swap(i, K);
			if(j < K) swap(j, K);
			if(i == j && j == K && v[i].size() >= 3) ans = max(ans, v[i][0] + v[i][1] + v[i][2]);			
			if(i == j && j > K && v[i].size() >= 2 && !v[K].empty()) ans = max(ans, v[i][0] + v[i][1] + v[K][0]);
			if(i > j && j == K && !v[i].empty() && v[j].size() >= 2) ans = max(ans, v[i][0]  + v[j][0] + v[j][1]);
			if(i > j && j > K && !v[i].empty() && !v[j].empty() && !v[K].empty()) ans = max(ans, v[i][0] + v[j][0] + v[K][0]);
		}
	cout << ans;
	return 0;
}

