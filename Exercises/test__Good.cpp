#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; (i) < int(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < int(n); ++ (i))
#define ALL(x) begin(x), end(x)
using ll = long long;
using namespace std;
template <class T> inline void chmin(T & a, T const & b) { a = min(a, b); }

template <typename UnaryPredicate>
int64_t binsearch(int64_t l, int64_t r, UnaryPredicate p) {
    assert (l <= r);
    -- l;
    while (r - l > 1) {
        int64_t m = l + (r - l) / 2;  // to avoid overflow
        (p(m) ? r : l) = m;
    }
    return r;
}

int main() {
    freopen("cutsummin.inp", "r", stdin);
    // input
    int n; cin >> n;
    vector<ll> a(n);
    REP (i, n) cin >> a[i];

    // solve
    vector<ll> acc(n + 1);
    partial_sum(ALL(a), acc.begin() + 1);
    ll answer = LLONG_MAX;
    REP (m, n + 1) {
        int l0 = binsearch(0, m + 1, [&](int l) {
            ll b = acc[l] - acc[0];
            ll c = acc[m] - acc[l];
            return b >= c;
        });
        int r0 = binsearch(m, n + 1, [&](int r) {
            ll d = acc[r] - acc[m];
            ll e = acc[n] - acc[r];
            return d >= e;
        });
        REP3 (l, max(0, l0 - 3), min(m, l0 + 3) + 1) {
            REP3 (r, max(m, r0 - 3), min(n, r0 + 3) + 1) {
                ll b = acc[l] - acc[0];
                ll c = acc[m] - acc[l];
                ll d = acc[r] - acc[m];
                ll e = acc[n] - acc[r];
                array<ll, 4> bcde = {{ b, c, d, e }};
                chmin(answer, *max_element(ALL(bcde)) - *min_element(ALL(bcde)));
                if (answer == 218707676) {
                    cout << b << " " << c << " " << d << " " << e << '\n';
                    exit(0);
                }
            }
        }
    }

    // output
    cout << answer << endl;
    return 0;
}