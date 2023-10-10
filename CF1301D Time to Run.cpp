#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, k, cnt;
int x = 1, y = 1;
struct node {
	int len;
	char op;
} t[N];
inline void move(int dis, int op)
{
	if(!dis) return;
	dis = min(dis, k); cnt++;
	if(op == 1) t[cnt].len = dis, t[cnt].op = 'R', y++;
	if(op == 2) t[cnt].len = dis, t[cnt].op = 'L', y--;
	if(op == 3) t[cnt].len = dis, t[cnt].op = 'U', x--;
	if(op == 4) t[cnt].len = dis, t[cnt].op = 'D', x++;
	k -= dis;
	if(!k)
	{
		cout << cnt << '\n';
		for(int i = 1; i <= cnt; i++)
			cout << t[i].len << ' ' << t[i].op << '\n';
		exit(0);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	int s = (m - 1) * 2 * n + (n - 1) * 2 * m;
	if(k > s) {cout << "NO"; return 0;}
	cout << "YES\n";
	while(1)
	{
		if(x < n)
		{
			move(m - 1, 1);
			move(m - 1, 2);
			move(1, 4);
		}
		else if(y < m)
		{
			move(1, 1);
			move(n - 1, 3);
			move(n - 1, 4);
		}
		else
		{
			move(m - 1, 2);
			move(n - 1, 3);
		}
	}
	return 0;
}