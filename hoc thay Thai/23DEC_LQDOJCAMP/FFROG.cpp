#include <bits/stdc++.h>

using namespace std;
#define task "code"
#define ll long long

const int N = 1e5 + 3;

int n, a[N], b[N], l[N], p[N];
ll temp = 0, ans = 0;

struct Segment_tree {
    ll st[N << 2], lz[N << 2];

    Segment_tree() {
        memset(st, 0, sizeof st);
        memset(lz, 0, sizeof lz);
    }

    void down (int id) {
        lz[id << 1] += lz[id];
        st[id << 1] += lz[id];
        lz[id << 1 | 1] += lz[id];
        st[id << 1 | 1] += lz[id];
        lz[id] = 0;
    }

    void update (int id, int l, int r, int u, int v, ll val) {
        if (u <= l && r <= v) {
            st[id] += val;
            lz[id] += val;
            return;
        }

        if (lz[id]) down(id);
        int m = l + r >> 1;
        if (u <= m) update (id << 1, l, m, u, v, val);
        if (v > m) update (id << 1 | 1, m+1, r, u, v, val);

        st[id] = max(st[id << 1], st[id << 1 | 1]);
    }

    ll get (int id, int l, int r, int u, int v) {
        if (u <= l && r <= v) return st[id];

        if (lz[id]) down(id);
        int m = l + r >> 1;
        ll ans = 0;
        if (u <= m) ans = max(ans, get(id << 1, l, m, u, v));
        if (v > m) ans = max(ans, get(id << 1 | 1, m+1, r, u, v));
        return ans;
    }
} seg;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i] >> b[i] >> l[i] >> p[i];
        temp = -1e17;

        if (i == 1) temp = a[i] - b[i];
        else {
            seg.update(1, 1, n, 1, i-1, -1);
            if (i > p[i] + 1 && l[i] > p[i] && seg.get(1, 1, n, i-l[i], i-p[i]-1) >= 0)
                temp = max(temp, seg.get(1, 1, n, i-l[i], i-p[i]-1));

            if (l[i] != 0 && p[i] != 0)
            temp = max(temp, a[i] - b[i] + seg.get(1, 1, n, max({1, i-p[i], i-l[i]}), i-1));
        }
		cout << temp << '\n';
        seg.update(1, 1, n, i, i, temp);
        ans = max(ans, temp);

    }

    cout << ans;

    return 0;
}
