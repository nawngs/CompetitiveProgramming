#include <bits/stdc++.h>

#define ll long long
#define pll pair < ll, ll >
#define fi first
#define se second

using namespace std;

const ll INF = 1E16;

ll n, m, res[100003];

pll a[200003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("pizza1.inp", "r", stdin);
    freopen("pizza1.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i].fi >> a[i].se;
    for (int i = 1; i <= m; i++) {
        cin >> a[i + n].fi;
        a[i + n].se = -i;
    }
    sort(a + 1, a + n + m + 1, [&](pll &x, pll &y) {
        return (x.fi < y.fi) || (x.fi == y.fi && x.se > 0);
    });
    priority_queue < ll, vector < ll >, greater < ll > >  heap, pq;
    for (int i = 1; i <= n + m; i++) {
        if (a[i].se < 0) {
            res[-a[i].se] = INF;
            if (heap.size()) res[-a[i].se] = heap.top() + a[i].fi - a[1].fi;
        }
        else heap.push(a[i].se - a[i].fi + a[1].fi);
    }
     sort(a + 1, a + n + m + 1, [&](pll &x, pll &y) {
        return (x.fi < y.fi) || (x.fi == y.fi && x.se < 0);
    });
    for (int i = n + m; i >= 1; i--) {
        if (a[i].se < 0) {if (pq.size()) res[-a[i].se] = min(res[-a[i].se], pq.top() + a[n + m].fi - a[i].fi);}
        else pq.push(a[i].se - a[n + m].fi + a[i].fi);
    }
    for (int i = 1; i <= m; i++) cout << res[i] << " ";
}
