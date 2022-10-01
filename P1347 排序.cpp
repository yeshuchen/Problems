#include<bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
int n, m, tot;
int d[N], du[N];
int ver[N], nxt[N], head[N];
inline void add(int x, int y)
{
    ver[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
inline bool topo(int step)
{
    int cnt = 0, sum = 0;
    bool flag = 0;
    queue<int> q; vector<int> ans;
    for(int i = 1; i <= n; i++)
        if(!du[i])
            q.push(i), cnt++, sum++, ans.push_back(i);
    if(cnt > 1) flag = 1;
    while(!q.empty())
    {
        int x = q.front(); q.pop();
        cnt = 0;
        for(int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i];
            du[y]--;
            if(!du[y]) q.push(y), cnt++, sum++, ans.push_back(y);
        }
        if(cnt > 1) flag = 1;
    }
    if(sum < n) return false;
    if(flag) return true;
    if(sum == n)
    {  
        cout << "Sorted sequence determined after " << step << " relations: ";
        for(int i = 0; i < ans.size(); i++)
            cout << (char)(ans[i] + 'A' - 1);
        cout << '.';
        exit(0);
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        char x, y, op;
        cin >> x >> op >> y;
        int X = x - 'A' + 1, Y = y - 'A' + 1;
        add(X, Y);
        d[Y]++;
        memcpy(du, d, sizeof(du));
        if(!topo(i))
        {
            cout << "Inconsistency found after " << i << " relations.";
            return 0;
        }
    }
    cout << "Sorted sequence cannot be determined.";
    return 0;
}