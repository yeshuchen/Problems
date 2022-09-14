#include<bits/stdc++.h>
using namespace std;
bool vis[500005];
int a[500005];
vector<int> g[500005];
int T;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) g[i].clear(), vis[i] = 0;
        for(int i = 1; i <= n; i++)
            cin >> a[i], g[a[i]].push_back(i);
        vis[n + 1] = 1; vis[g[1][0]] = 1;
        for(int i = 2; i <= n; i++)
        {
            if(g[i][0] != g[i - 1][0] + 1 && !vis[g[i - 1][0] + 1])
            {
                cout << "No\n";
                goto end;
            }
            vis[g[i][0]] = 1;
        }
        cout << "Yes\n";
        end:;
    }
    return 0;
}