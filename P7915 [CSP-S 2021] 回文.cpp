#include<bits/stdc++.h>
using namespace std;
int T, n;
int a[1000006];
vector<int> g[1000006];
inline bool check(int t, int L, int R, int k)
{
    queue<int> q; stack<int> s;
    q.push(t); s.push(t);
    int l, r;
    if(k == 1) l = g[a[1]][1], r = g[a[1]][1];
    else l = g[a[2 * n]][0], r = g[a[2 * n]][0];
	cout << 1;
    for(int i = 1; i < n; i++)
    {
		cout << 1 << '\n';
        if(g[a[L]][1] == l - 1)
        {
            q.push(0);
            s.push(0);
            l--; L++;
            continue;
        }
        if(g[a[L]][1] == r + 1)
        {
            q.push(0);
            s.push(1);
            r++; L++;
            continue;
        }
        if(g[a[R]][0] == l - 1)
        {
            q.push(1);
            s.push(0);
            l--; R--;
            continue;
        }
        if(g[a[R]][0] == r + 1)
        {
            q.push(1);
            s.push(1);
            r++; R--;
            continue;
        }
	}
    if(q.size() + s.size() == 2 * n)
    {
        while(!q.empty()) cout << (q.front() ? 'R' : 'L'), q.pop();
        while(!s.empty()) cout << (s.top() ? 'R' : 'L'), s.pop();
        cout << '\n';
        return true;
    }
    return false;
}
int main()
{
    cin >> T;
    while(T--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++) g[i].clear();
        for(int i = 1; i <= 2 * n; i++)
            cin >> a[i], g[a[i]].push_back(i);
        if(check(0, 2, 2 * n, 1)) continue;
        if(check(1, 1, 2 * n - 1, n)) continue;
        cout << -1;
        cout << '\n';
    }
}