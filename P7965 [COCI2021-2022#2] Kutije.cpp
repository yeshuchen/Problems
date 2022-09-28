#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int n, m, q, tot;
int f[N];
inline int find(int k){return f[k] == k ? k : f[k] = find(f[k]);}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) f[i] = i;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        {
            int p;
            cin >> p;
            f[find(j)] = find(p);
        }
    for(int i = 1; i <= q; i++)
    {
        int a, b;
        cin >> a >> b;
        if(find(a) == find(b)) cout << "DA\n";
        else cout << "NE\n";
    }
    return 0;
}