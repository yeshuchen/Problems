#include<bits/stdc++.h>
using namespace std;
int T, n;
string s[100005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--)
    {
        bool flag = 0;
        cin >> n;
        map<string, int> m;
        for(int i = 1; i <= n; i++)
        {
            cin >> s[i]; m[s[i]] = i;
            if(s[i].size() == 1) flag = 1;
        }
        if(flag)
        {
            cout << "YES\n";
            continue;
        }
        for(int i = 1; i <= n; i++)
        {
            string t = "";
            for(int j = s[i].size() - 1; j >= 0; j--)
                t += s[i][j];
            if(m[t])
            {
                cout << "YES\n";
                goto end;
            }
            if(s[i].size() == 2)
            {
                for(int j = 0; j < 26; j++)
                {
                    string te = "";
                    te = (char)(j + 'a') + t;
                    if(m[te] && m[te] >= i)
                    {
                        cout << "YES\n";
                        goto end;
                    }
                    te = t + (char)(j + 'a');
                    if(m[te] && m[te] <= i)
                    {
                        cout << "YES\n";
                        goto end;
                    }
                }
            }
        }
        cout << "NO\n";
        end:;
    }
    return 0;
}