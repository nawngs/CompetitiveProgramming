#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pb push_back
#define db(val) "[" #val " = " << (val) << "] "
using namespace std;
const ll mod = 1e9 + 7;
const int maxn = 5e5 + 4;
const int INF = 1e9;

int n, q, tmin[4 * maxn], t[4 * maxn], a[maxn], res[maxn];
string votes;
vector<pair<int,int>> queries[maxn];
vector<int> zeronums;

void update(int v, int l, int r, int pos, int val)
{
    if (l == r) 
    {
        t[v] = val;
        tmin[v] = val;
    }
    else
    {
        int m = (l + r) / 2;
        if (pos <= m) update(2 * v, l, m, pos, val);
        else update(2 * v + 1, m + 1, r, pos, val);
        t[v] = t[2 * v] + t[2 * v + 1];
        tmin[v] = min(tmin[2 * v] + t[2 * v + 1], tmin[2 * v + 1]);
    }
}

pair<int,int> get(int v, int l, int r, int tl, int tr)
{
    if (l > tr or r < tl) return {0, 0};
    if (tl >= l and tr <= r) return make_pair(t[v], tmin[v]);
    else
    {
        int m = (tl + tr) / 2;
        auto Left = get(2 * v, l, r, tl, m);
        auto Right = get(2 * v + 1, l , r, m + 1, tr);
        return make_pair(Left.fi + Right.fi, min(Left.se + Right.fi, Right.se));
    }
}

int getzero(int i)
{
    int l = 0, r = zeronums.size() - 1, pos = zeronums.size();
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (zeronums[m] <= i)
        {
            pos = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    return zeronums.size() - pos;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen(".INP", "r", stdin);
    //freopen(".OUT", "w", stdout);
    cin >> n >> votes >> q;
    votes = ' ' + votes;
    for (int i = 1; i <= n; i++)
    {
        int l, r; cin >> l >> r;
        queries[l].pb({r, i});
    }
    for (int i = 1; i <= n; i++) a[i] = (votes[i] == 'X' ? 1 : -1);
    for (int i = n; i >= 1; i--)
    {
        if (votes[i] == 'Y') 
        {
            zeronums.pb(i);
            a[i] = 0;
            update(1, 1, n, i, 0);
        }
        else
        {
            if (zeronums.size())
            {
                int idx = zeronums.back();
                zeronums.pop_back();
                update(1, 1, n, idx, -1);
            }
            update(1, 1, n, i, 1);
        }  
        for (auto it : queries[i])
        {
            int j = it.fi, idx = it.se;
            res[idx] = - min(0, get(1, i, j, 1, n).se) + getzero(j);
        }
    }
    for (int i = 1; i <= q; i++) cout << res[i] << '\n';
}
