#include<bits/stdc++.h>
using namespace std;
struct DLXnode{
    int row, col;
    int left, right, up, down;
};
int n, m, cnt;
DLXnode node[10005];
int row[505], ans[505], lcnt[505];
void init()
{
    for(int i = 0; i <= m; i++)
    {
        node[i].left = i - 1;
        node[i].right = i + 1;
        node[i].down = i;
        node[i].up = i;
    }
    node[0].left = m;
    node[m].right = 0;
    cnt = m;
}
void add(int r, int c)
{
    node[++cnt].row = r;
    node[cnt].col = c;
    node[cnt].up = node[c].up;
    node[cnt].down = c;
    node[c].up = cnt;
    node[node[cnt].up].down = cnt;
    if(!row[r])
    {
        node[cnt].left = cnt;
        node[cnt].right = cnt;
        row[r] = cnt;
    }
    else
    {
        node[cnt].left = node[row[r]].left;
        node[cnt].right = row[r];
        node[node[cnt].left].right = cnt;
        node[row[r]].left = cnt;
    }
    lcnt[c]++;
}
void remove(int c)
{
    for(int i = node[c].down; i != c; i = node[i].down)
        for(int j = node[i].right; j != i; j = node[j].right)
        {
            node[node[j].down].up = node[j].up;
            node[node[j].up].down = node[j].down;
            lcnt[node[j].col]--;
        }
    node[node[c].left].right = node[c].right;
    node[node[c].right].left = node[c].left;
}
void resume(int c)
{
    node[node[c].left].right = c;
    node[node[c].right].left = c;
    for(int i = node[c].down; i != c; i = node[i].down)
        for(int j = node[i].right; j != i; j = node[j].right)
        {
            node[node[j].down].up = j;
            node[node[j].up].down = j;
            lcnt[node[j].col]++;
        }
}
bool dance(int dep)
{
    if(!node[0].right)
    {
        for(int i = 1; i < dep; i++)
            cout << ans[i] << ' ';
        return true;
    }
    int C = node[0].right;
    for(int i = node[0].right; i != 0; i = node[i].right)
        if(lcnt[i] < lcnt[C])
            C = i;
    remove(C);
    for(int i = node[C].down; i != C; i = node[i].down)
    {
        ans[dep] = node[i].row;
        for(int j = node[i].right; j != i; j = node[j].right) remove(node[j].col);
        if(dance(dep + 1))return true;
        for(int j = node[i].right; j != i; j = node[j].right) resume(node[j].col);
    }
    resume(C);
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    init();
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            int v;
            cin >> v;
            if(v) add(i, j);
        }
    if(!dance(1)) cout << "No Solution!";
    return 0;
}