#include<bits/stdc++.h>
using namespace std;
int d[1005];
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        string s;
        cin >> s;
        d['R'] = d['S'] = d['P'] = 0;
        for(int i = 0; i < s.size(); i++)
            d[s[i]]++;
        int r = d['R'], S = d['S'], p = d['P'];
        if(r >= S && r >= p) for(int i = 0; i < s.size(); i++) cout << 'P';
        else if(S >= r && S >= p) for(int i = 0; i < s.size(); i++) cout << 'R';
        else for(int i = 0; i < s.size(); i++) cout << 'S';
        cout << '\n';
    }
    return 0;
}