#include<bits/stdc++.h>
#define lcm(x, y) (x * y / __gcd(x, y))
#define int long long
using namespace std;
const int N = 1e6 + 5;
int l, r;
struct node{
	int x, y, val;
	bool operator < (const node &y) const{
		return val > y.val;
	}
};
int f[N], ans;
inline int find(int k) {return f[k] == k ? k : f[k] = find(f[k]);}
priority_queue<node> q;
inline void Kruskal()
{
	while(!q.empty())
	{
		node x = q.top(); q.pop();
		int fx = find(x.x), fy = find(x.y);
		if(fx == fy) continue;
		f[fx] = fy;
		ans += x.val;
	}
	cout << ans;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> l >> r;
	for(int i = l; i <= r; i++) f[i] = i;
	for(int i = 2; i <= r; i++)
	{
		int cnt = 0, minn = 0;
		for(int j = i; j <= r; j += i)
		{
			if(!minn && j >= l) minn = j;
			if(j >= l) q.push((node){minn, j, lcm(minn, j)});
		}
		if(i >= l) q.push((node){i, l, lcm(i, l)});
	}
	Kruskal();
	return 0;
}