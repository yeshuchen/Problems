#include<bits/stdc++.h>
const int N = 4e5 + 5;
using namespace std;
int n, T;
int vis[N], temp[N];
int a[N];
vector<int> g[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--)
    {
        int tot = 0;
        cin >> n;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i <= n; i++) g[i].clear();
        for(int i = 1; i <= n; i++)
            cin >> a[i], g[a[i]].push_back(i);
        int MEX = 0;
        for(int i = 1; i <= n; i++)
        {
            vis[a[i]] = 1;
            while(vis[MEX]) MEX++;
            if(g[MEX].empty())
            {
                temp[++tot] = MEX; 
                for(int j = 0; j <= MEX; j++)
                    vis[j] = 0;
                MEX = 0;
                continue;
            }
            int p = upper_bound(g[MEX].begin(), g[MEX].end(), i) - g[MEX].begin();
            if(p < g[MEX].size()) continue;
            temp[++tot] = MEX; 
            for(int j = 0; j <= MEX; j++)
                vis[j] = 0;
            MEX = 0;
        }
        cout << tot << '\n';
        for(int i = 1; i <= tot; i++)
            cout << temp[i] << ' ';
        cout << '\n';
    }
    return 0;
}