#include<bits/stdc++.h>
using namespace std;
char c[7][7];
char ans[7][7];
vector<char> g;
bool vis[10];
int to[255];
bool check()
{
    char temp[10];
    for(int i = 1; i <= 6; i++) vis[i] = 0;
    for(int i = 1; i <= 3; i++)
    {
        bool flag = 0;
        for(int j = 1; j <= 3; j++) temp[j] = ans[i][j];
        for(int j = 1; j <= 6; j++)
        {
            if(vis[j]) continue;
            if(temp[1] != c[j][1] || temp[2] != c[j][2] || temp[3] != c[j][3]/* && temp[1] != c[j][3] || temp[2] != c[j][2] && temp[3] != c[j][1]*/) continue;
            vis[j] = 1; flag = 1;
            break;
        }
        if(!flag) return false;
    }
    for(int i = 1; i <= 3; i++)
    {
        bool flag = 0;
        for(int j = 1; j <= 3; j++) temp[j] = ans[j][i];
        for(int j = 1; j <= 6; j++)
        {
            if(vis[j]) continue;
            if(temp[1] != c[j][1] || temp[2] != c[j][2] || temp[3] != c[j][3]/* && temp[1] != c[j][3] || temp[2] != c[j][2] && temp[3] != c[j][1]*/) continue;
            vis[j] = 1; flag = 1;
            break;
        }
        if(!flag) return false;
    }
    return true;
}
string s = "ZZZZZZZZZ";
int te[7] = {0, 1, 2, 3, 4, 5, 6};
int main()
{
    int cnt = 0;
    for(int i = 1; i <= 6; i++)
        scanf("%s", c[i] + 1);
    do
    {
        for(int i = 1; i <= 3; i++)
            for(int j = 1; j <= 3; j++)
                ans[i][j] = c[te[i]][j];
        if(check())
        {
            string t = "";
            for(int i = 1; i <= 3; i++)
                for(int j = 1; j <= 3; j++)
                    t = t + ans[i][j];
            if(t < s) s = t;
        }  
    }while(next_permutation(te + 1, te + 7));
    if(s == "ZZZZZZZZZ") cout << 0;
    else
    {
        for(int i = 1; i <= 3; i++)
        {
            for(int j = 1; j <= 3; j++)
                cout << s[(i - 1) * 3 + j - 1];
            cout << '\n';
        }
    }
}