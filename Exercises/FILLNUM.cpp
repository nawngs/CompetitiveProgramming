#define taskname "FILLNUM"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxN = 1e7 + 2;
const int maxM = 1e5 + 1;

int n, m, k;
int a[maxN], Next[maxN];

struct TFillCommand
{
    int i, j, c;
} cmd[maxM];

void ReadInput()
{
    cin >> n >> m >> k;
    cmd[0] = {1, n, 0};
    for (int i = 1; i <= m; ++i)
        cin >> cmd[i].i >> cmd[i].j >> cmd[i].c;
    fill(a + 1, a + n + 2, -1);
    for (int i = 0; i <= n; ++i)
        Next[i] = i + 1;
}

int FindNext(int i)
{
    int Res;
    for (Res = Next[i]; a[Res] != -1; Res = Next[Res]);
    while (i != Res)
    {
        int j = Next[i];
        Next[i] = Res;
        i = j;
    }
    return Res;
}

void DoFill(int i, int j, int c)
{
    for (int p = FindNext(i - 1); p <= j; p = FindNext(p))
        a[p] = c;
}

void Solve()
{
    for (int i = m; i >= 0; --i)
        DoFill(cmd[i].i, cmd[i].j, cmd[i].c);
    int res = 0;
    for (int i = 1; i <= n; ++i)
        res = ((long long)res *  10 + a[i]) % k;
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    ReadInput();
    Solve();
}