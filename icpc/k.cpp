#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FOD(i, a, b) for(int i = a; i >= b; --i)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define ll long long
#define ld long double
#define nmax 507
void faster()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int n, m;

vector < vector < int > > a;
vector < vector < int > > res;

vector < vector < int > > rouhe;

vector < vector < int > > cop;

int danhdau[nmax][nmax];

int q;

void change()
{
    FOR(i, 0, n - 1)
    FOR(j, 0, m - 1)
    res[i][j] = cop[i][j];
}

void update()
{
    FOR(i, 0, n - 1)
    FOR(j, 0, m - 1)
    {
        if(cop[i][j] < res[i][j]) return;
        if(cop[i][j] > res[i][j])
        {
            change();
            return;
        }
    }
}
void read()
{
    cin >> n >> m;
    a.clear();
    FOR(i, 0, n - 1)
    {
        vector < int > tmp;
        tmp.clear();
    FOR(j, 0, m - 1)
    {
        int x;
        cin >> x;
        tmp.eb(x);
        danhdau[i][x] = j;
    }
        a.eb(tmp);
    }
}
void khoitao()
{
    res.clear();
    FOR(i, 0, n - 1)
    {
        vector < int > tmp;
        tmp.clear();
        tmp.resize(m, 0);
        res.eb(tmp);
        cop.eb(tmp);
    }
}
void tryhard()
{
    FOR(i, 0, m - 1)
    {
        vector < int > tmp;
        tmp.clear();
        tmp.resize(n, 0);
        rouhe.eb(tmp);
    }
    FOR(i, 0, n - 1)
    {
        swap(a[0] , a[i]);
        FOR(j, 0, m - 1)
        {
            // danhdau[i][m - j]
            FOR(t, 0, n - 1)
            {
                cop[t][j] = a[t][danhdau[i][m - j]];
            }
        }
        sort(cop.begin() + 1, cop.end());
        update();
    }
}

int main()
{
    faster();
    read();
    khoitao();
    tryhard();
    cin >> q;
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        cout << res[x - 1][y - 1] << '\n';
    }

    return 0;
}