#include <bits/stdc++.h>

#define ll long long
#define pll pair < ll, ll >
#define fi first
#define se second

using namespace std;

ll n, m, q, s[100003], p[100003], cnt[100003], price[100003];

ll t;

vector < pll > gap;

pll teddy[100003];

ll calc(ll l, ll r) {
    return (l + r) * (r - l + 1) / 2;
}

bool check(ll x) {
    ll lost, gain;
    if (x >= gap.back().fi)
        lost = gap.back().se + (x - gap.back().fi) * p[n];
    else {
        int l = 0, r = gap.size() - 1, mid, ans;
        while (l <= r) {
            mid = (l + r) / 2;
            if (gap[mid].fi <= x) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        lost = gap[ans].se + (x - gap[ans].fi) * p[ans];
    }// find lost
    int l = 0, r = m - 1, mid, ans = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        if (x >= cnt[mid]) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    gain = price[ans] + calc(teddy[ans + 1].fi, teddy[ans + 1].fi + (x - cnt[ans]) - 1);
    return gain - lost >= t;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("gapthu.inp", "r", stdin);
    freopen("gapthu.out", "w", stdout);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 0; i <= n; i++)
        cin >> p[i];
    cnt[0] = price[0] = 0;
    for (int i = 1; i <= m; i++) {
        cin >> teddy[i].fi >> teddy[i].se;
        cnt[i] = (cnt[i - 1] + teddy[i].se - teddy[i].fi + 1);
        price[i] = price[i - 1] + calc(teddy[i].fi, teddy[i].se);
       // cout << cnt[i] << " " << price[i] << '\n';
    }
    ll total = 0, num = 0;
    gap.push_back({0, 0});
    for (int i = 1; i <= n; i++) {
        ll dem = (s[i] - total + p[i - 1] - 1) / p[i - 1], val = dem * p[i - 1];
        num += dem, total += val;
        gap.push_back({num, total});
        //cout << num << " " << total << '\n';
    }
    while (q--) {
        cin >> t;
        ll l = 1, r = cnt[m], mid, ans = -1;
        while (l <= r) {
            mid = (l + r) / 2;
            if (check(mid)) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        cout << ans << ' ';
    }
}

/*
test:
3 3 3
20 30 40
7 5 3 2
2 5
8 10
10 12
1 20 34
*/
