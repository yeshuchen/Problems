#include<bits/stdc++.h>
using namespace std;
struct DLXnode{
    int row, col;
    int left, right, down, up;
};
DLXnode node[100005];
int cnt;
int a[10][10];
int row[100005], ans[505], lcnt[100005];
void init()
{
    for(int i = 0; i <= 324; i++)
    {
        node[i].left = i - 1;
        node[i].right = i + 1;
        node[i].up = node[i].down = i;
    }
    node[0].left = 324;
    node[324].right = 0;
    cnt = 324;
}
void add(int r, int c)
{
    lcnt[c]++;
    node[++cnt].up = node[c].up;
    node[cnt].down = c;
    node[cnt].row = r;
    node[cnt].col = c;
    node[c].up = node[node[cnt].up].down = cnt;
    if(!row[r])
    {
        node[cnt].left = node[cnt].right = cnt;
        row[r] = cnt;
    }
    else
    {
        node[cnt].left = node[row[r]].left;
        node[cnt].right = row[r];
        node[row[r]].left = node[node[cnt].left].right = cnt;
    }
}
void remove(int c)
{
    for(int i = node[c].down; i != c; i = node[i].down)
        for(int j = node[i].right; j != i; j = node[j].right)
        {
            node[node[j].up].down = node[j].down;
            node[node[j].down].up = node[j].up;
            lcnt[node[j].col]--;
        }
    node[node[c].left].right = node[c].right;
    node[node[c].right].left = node[c].left;
}
void resume(int c)
{
    node[node[c].right].left = node[node[c].left].right = c;
    for(int i = node[c].down; i != c; i = node[i].down)
        for(int j = node[i].right; j != i; j = node[j].right)
        {
            node[node[j].up].down = node[node[j].down].up = j;
            lcnt[node[j].col]++;
        }
}
void dance(int dep)
{
    if(!node[0].right)
    {
        for(int i = 1; i < dep; i++)
        {
            int r = ans[i] / 100, c = ans[i] % 100 / 10, v = ans[i] % 10;
            a[r][c] = v;
        }
        return;
    }
    int C = node[0].right;
    for(int i = node[0].right; i; i = node[i].right)
        if(lcnt[i] < lcnt[C])
            C = i;
    remove(C);
    for(int i = node[C].down; i != C; i = node[i].down)
    {
        ans[dep] = node[i].row;
        for(int j = node[i].right; j != i; j = node[j].right) remove(node[j].col);
        dance(dep + 1);
        for(int j = node[i].right; j != i; j = node[j].right) resume(node[j].col);
    }
    resume(C);
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    init();
    for(int i = 1; i <= 9; i++)
        for(int j = 1; j <= 9; j++)
        {
            cin >> a[i][j];
            for(int k = 1; k <= 9; k++)
            {
                if(a[i][j] != k && a[i][j]) continue;
                int ro = i * 100 + j * 10 + k;
                add(ro, (i - 1) * 9 + j);
                add(ro, 81 + (i - 1) * 9 + k);
                add(ro, 162 + (j - 1) * 9 + k);
                add(ro, 243 + ((i - 1) / 3 * 3 + (j - 1) / 3) * 9 + k);
            }
        }
    dance(1);
    for(int i = 1; i <= 9; i++)
    {
        for(int j = 1; j <= 9; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }   
    return 0;
}