#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define li pair<long long, int>
int const nmax = 1e5 + 5;
int n, q;
int a[nmax];
ll it[18][nmax * 4];
int lazy[18][nmax * 4];
ll sum[18][nmax][2];
// 0 la khong co j
// 1 la ca doan bang 0
// 2 la ca doan bang 1
// 3 la ca doan doi so
int bit(int mask, int i)
{
    return ((mask >> i) & 1);
}
void build(int x, int node, int l, int r)
{
    if(l == r)
    {
        it[x][node] = (bit(l, x) == bit(a[l], x) ? 0 : 1);
        return;
    }
    int mid = (l + r) >> 1;
    build(x, node << 1, l, mid);
    build(x, node << 1 | 1, mid + 1, r);
    it[x][node] = it[x][node << 1] + it[x][node << 1 | 1];
}
//lazy[x][node] ---> lazy[x][node << 1]
void change(int x, int node, int l, int r, int val)
{
    // 0 la khong co j
    // 1 la ca doan bang 0
    // 2 la ca doan bang 1
    // 3 la ca doan doi bit
    if(val == 0) return;
    if(lazy[x][node] == 0 && val == 1)
    {
        it[x][node] = sum[x][r][0] - sum[x][l - 1][0];
        lazy[x][node] = 1;
        return;
    }
    if(lazy[x][node] == 0 && val == 2)
    {
        it[x][node] = sum[x][r][1] - sum[x][l - 1][1];
        lazy[x][node] = 2;
        return;
    }
    if(lazy[x][node] == 0 && val == 3)
    {
        it[x][node] = sum[x][r][0] - sum[x][l - 1][0] + sum[x][r][1] - sum[x][l - 1][1] - it[x][node];
        lazy[x][node] = 3;
        return;
    }
    if(lazy[x][node] == 1 && val == 1) return;
    if(lazy[x][node] == 1 && val == 2)
    {
        it[x][node] = sum[x][r][1] - sum[x][l - 1][1];
        lazy[x][node] = 2;
        return;
    }
    if(lazy[x][node] == 1 && val == 3)
    {
        it[x][node] = sum[x][r][1] - sum[x][l - 1][1];
        lazy[x][node] = 2;
        return;
    }
    if(lazy[x][node] == 2 && val == 1)
    {
        it[x][node] = sum[x][r][0] - sum[x][l - 1][0];
        lazy[x][node] = 1;
        return;
    }
    if(lazy[x][node] == 2 && val == 2) return;
    if(lazy[x][node] == 2 && val == 3)
    {
        it[x][node] = sum[x][r][0] - sum[x][l - 1][0];
        lazy[x][node] = 1;
        return;
    }
    if(lazy[x][node] == 3 && val == 1)
    {
        it[x][node] = sum[x][r][0] - sum[x][l - 1][0];
        lazy[x][node] = 1;
        return;
    }
    if(lazy[x][node] == 3 && val == 2)
    {
        it[x][node] = sum[x][r][1] - sum[x][l - 1][1];
        lazy[x][node] = 2;
        return;
    }
    if(lazy[x][node] == 3 && val == 3)
    {
        it[x][node] = sum[x][r][0] - sum[x][l - 1][0] + sum[x][r][1] - sum[x][l - 1][1] - it[x][node];
        lazy[x][node] = 0;
        return;
    }
}
void down(int x, int node, int l, int r, int mid)
{
    if(lazy[x][node] == 0) return;
    change(x, node << 1, l, mid, lazy[x][node]);
    change(x, node << 1 | 1, mid + 1, r, lazy[x][node]);
    lazy[x][node] = 0;
}
void update_3(int x, int node, int l, int r, int u, int v, int val)
{
    if(v < l || r < u) return;
    if(u <= l && r <= v)
    {
        change(x, node, l, r, val);
        return;
    }
    int mid = (l + r) >> 1;
    down(x, node, l, r, mid);
    update_3(x, node << 1, l, mid, u, v, val);
    update_3(x, node << 1 | 1, mid + 1, r, u, v, val);
    it[x][node] = it[x][node << 1] + it[x][node << 1 | 1];
}
ll get(int x, int node, int l, int r, int u, int v)
{
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return it[x][node];
    int mid = (l + r) >> 1;
    down(x, node, l, r, mid);
    return get(x, node << 1, l, mid, u, v) + get(x, node << 1 | 1, mid + 1, r, u, v);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 0; i < 17; ++i)
    {
        build(i, 1, 1, n);
        for(int j = 1; j <= n; ++j)
        {
            sum[i][j][bit(j, i) ^ 1] = sum[i][j - 1][bit(j, i) ^ 1] + 1;
            sum[i][j][bit(j, i)] = sum[i][j - 1][bit(j, i)];
        }
    }
    while(q--)
    {
        int t, l, r; cin >> t >> l >> r;
        if(t == 1)
        {
            ll ans = 0;
            for(int i = 0; i < 17; ++i) ans += (1ll << i) * get(i, 1, 1, n, l, r);
            cout << ans << '\n';
        }
        if(t == 2)
        {
            int x; cin >> x;
            for(int i = 0; i < 17; ++i) update_3(i, 1, 1, n, l, r, bit(x, i) + 1);
        }
        if(t == 3)
        {
            int x; char c; cin >> x >> c;
            if(c == '&')
            {
                for(int i = 0; i < 17; ++i)
                    if(!bit(x, i))
                        update_3(i, 1, 1, n, l, r, 1);
            }
            if(c == '|')
            {
                for(int i = 0; i < 17; ++i)
                    if(bit(x, i))
                        update_3(i, 1, 1, n, l, r, 2);
            }
            if(c == '^')
            {
                for(int i = 0; i < 17; ++i)
                    if(bit(x, i))
                        update_3(i, 1, 1, n, l, r, 3);
            }
        }
        /*for (int j = 1; j <= n; j++) {
            ll ans = 0;
            for(int i = 0; i < 17; ++i) ans += (1ll << i) * get(i, 1, 1, n, j, j);
            cout << ans << ' ';
        }
        cout << '\n';*/
    }
    return 0;
}
