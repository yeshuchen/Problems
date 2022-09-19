#include<bits/stdc++.h>
using namespace std;
int n, T;
char s[1000005];
char c[1000005];
int cnt[200];
vector<int> g[205];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
        g[s[i]].push_back(i);
    }
    cin >> T;
    while(T--)
    {
        int maxn = 0;
        scanf("%s", c + 1);
        int n = strlen(c + 1);
        for(int i = 1; i <= 150; i++)
            cnt[i] = 0;
        for(int i = 1; i <= n; i++)
            cnt[c[i]]++;
        for(int i = 1; i <= 150; i++)
            if(cnt[i])
                maxn = max(maxn, g[i][cnt[i] - 1]);
        cout << maxn << '\n';
    }
    return 0;
}