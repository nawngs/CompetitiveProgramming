#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, q, a[N], S = sqrt(N);

struct t {
    int first, second, third, k;
    t() = default;
};

t qr[N];

int cnt[N], ans[N], res[N];

void solve() {
    vector<int> arr;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i], arr.emplace_back(a[i]);
    for (int i = 1; i <= q; i++)
        cin >> qr[i].first >> qr[i].second >> qr[i].k, qr[i].third = i;

    sort(qr + 1, qr + q + 1, [&] (const t &x, const t &y) {
        if (x.first / S != y.first / S)
            return x.first / S < y.first / S;
        return x.second < y.second;
    });

    sort(arr.begin(), arr.end());
    arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(arr.begin(), arr.end(), a[i]) - arr.begin() + 1;

    for (int i = 1; i <= n; i++)
        res[i] = cnt[i] = 0;
    cnt[a[1]] = 1;
    int l = 1, r = 1, dis = 1;

    auto update = [&] (int x, int w) -> void {
        int now = cnt[x];
        cnt[x] += w;
        int nxt = cnt[x];
        if (w == -1) {
            res[nxt]--;
            if (nxt == 0) --dis;
        } else {
            res[now]++;
            if (nxt == 1) ++dis;
        }
    };

    for (int i = 1; i <= q; i++) {
        int L = qr[i].first, R = qr[i].second, k = qr[i].k, id = qr[i].third;
        while (l > L) --l, update(a[l], +1);
        while (l < L) update(a[l], -1), l++;
        while (r > R) update(a[r], -1), r--;
        while (r < R) ++r, update(a[r], +1);
        ans[id] = dis - res[k];
    }

    for (int i = 1; i <= q; i++)
        cout << ans[i] << ' ';
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    int test; cin >> test;
    while (test--) solve(), cout << '\n';

    return 0;
}
