#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T, n;
struct node {
	int x, y, z;
};
ll a[100005];
vector<node> ans;
void option(int x, int y, int z)
{
	ans.push_back({x, y, z});
	a[x] -= x * z; a[y] += x * z;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while(T--)
	{
		cin >> n; ll sum = 0; ans.clear();
		for(int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
		if(sum % n) {cout << -1 << '\n'; goto end;}
		sum /= n;
		for(int i = 2; i <= n; i++)
		{
			option(1, i, (a[i] + i - 1) / i * i - a[i]);
			option(i, 1, a[i] / i);
		}
		for(int i = 2; i <= n; i++)
			option(1, i, sum);
		cout << ans.size() << '\n';
		for(auto x : ans)
			cout << x.x << ' ' << x.y << ' ' << x.z << '\n';
		end:;
	}
	return 0;
}