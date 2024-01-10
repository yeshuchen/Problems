#include<bits/stdc++.h>
using namespace std;
int n, res;
char s[55], num[605];
int fail[605], vis[605][5000];
int tr[605][26], ed[605];
struct node {
	int pi, vis;
} pos[605][5000];
void insert(char* S, int id)
{
	int len = strlen(S + 1), x = 0;
	for(int i = 1; i <= len; i++)
	{
		if(!tr[x][S[i] - 'A']) tr[x][S[i] - 'A'] = ++res;
		x = tr[x][S[i] - 'A']; num[x] = S[i];
	}
	ed[x] |= (1 << id - 1);
}
void build()
{
	queue<int> q;
	for(int i = 0; i < 26; i++)
		if(tr[0][i]) q.push(tr[0][i]);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for(int i = 0; i < 26; i++)
		{
			if(tr[x][i])
			{
				fail[tr[x][i]] = tr[fail[x]][i];
				ed[x] |= ed[fail[tr[x][i]]];
				ed[tr[x][i]] |= ed[x];
				q.push(tr[x][i]);
			}
			else tr[x][i] = tr[fail[x]][i];
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> s + 1;
		insert(s, i);
	}
	build();
	queue<node> q;
	q.push((node){0, 0});
	vis[0][0] = 1;
	while(!q.empty())
	{
		node t = q.front(); q.pop();
		if(t.vis == (1 << n) - 1)
		{
			stack<char> stk;
			while(t.pi) stk.push(num[t.pi]), t = pos[t.pi][t.vis];
			while(!stk.empty()) cout << stk.top(), stk.pop();
			return 0;
		}
		for(int i = 0; i < 26; i++)
		{
			int y = tr[t.pi][i];
			if(!vis[y][t.vis | ed[y]])
			{
				vis[y][t.vis | ed[y]] = 1;
				pos[y][t.vis | ed[y]] = (node){t.pi, t.vis};
				q.push((node){y, t.vis | ed[y]});
			}
		}
	}
	return 0;
}