#include <bits/stdc++.h>

#define ll long long
#define pll pair < ll, ll >
#define fi first
#define se second

using namespace std;

ll n, l, r;

pll a[200003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> l >> r;
    bool sub5 = true;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
        if (a[i].fi != i) sub5 = false;
    }
    sort(a + 1, a + n + 1);
    deque < int > res;
    ll cur = 0;
    for (int i = 1; i <= n; i++) {
            if (cur < l) {
                cur += a[i].fi;
                res.push_back(i);
                if (cur > r) {
                    cur -= a[res.front()].fi;
                    res.pop_front();
                }
            }
            if (l <= cur && cur <= r) {
                vector < int > ans;
                while (!res.empty()) {
                    ans.push_back(a[res.front()].se);
                    res.pop_front();
                }
                sort(ans.begin(), ans.end());
                cout << ans.size() << '\n';
                for (auto x : ans) cout << x << " ";
                return 0;
            }
        }
    sort(a + 1, a + n + 1, [&](pll &x, pll &y) {
         return x.se < y.se;
    });
    if (n <= 40) {
        vector < ll > v1, v2;
        for (int i = 1; i <= n / 2; i++) v1.push_back(a[i].fi);
        for (int i = n / 2 + 1; i <= n; i++) v2.push_back(a[i].fi);
        vector < pll > temp;
        for (int msk = 1; msk < (1 << (v1.size())); msk++) {
            ll s = 0;
            for (int i = 0; i < n / 2; i++) if (msk >> i & 1) s += v1[i];
            temp.push_back({s, msk});
        }
        sort(temp.begin(), temp.end());
        for (int msk = 1; msk < (1 << v2.size()); msk++) {
            ll s = 0;
            for (int i = 0; i < v2.size(); i++) if (msk >> i & 1) s += v2[i];
            int low = 0, high = temp.size() - 1, mid, ans = -1;
            while (low <= high) {
                mid = (low + high) / 2;
                if (temp[mid].fi + s >= l) {
                    ans = mid;
                    high = mid - 1;
                }
                else low = mid + 1;
            }
            if (ans == -1 || temp[ans].fi + s > r) continue;
            cout << __builtin_popcount(temp[ans].se) + __builtin_popcount(msk) << '\n';
            for (int i = 0; i < v1.size(); i++)
                if (temp[ans].se >> i & 1) cout << i + 1 << ' ';
            for (int i = 0; i < v2.size(); i++)
                if (msk >> i & 1) cout << i + 1 + n / 2 << ' ';
            return 0;
        }
        cout << -1 << '\n';
        return 0;
    }
    if (n <= 80) {
        while (true) {
            random_shuffle(a + 1, a + 1 + n);
            ll cur = 0;
            for (int i = 1; i <= n; i++) {
                cur += a[i].fi;
                if (cur >= l && cur <= r) {
                    cout << i << '\n';
                    vector<int> res;
                    for (int j = 1; j <= i; j++) res.push_back(a[j].se);
                    sort(res.begin(), res.end());
                    for (auto c: res) cout << c << " ";
                    return 0;
                }
            }
        }
        return cout << -1, 0;
    }
    if (sub5) {
        ll val = min(n * (n + 1) / 2, r), cur = n;
        vector < int > res;
        while (val > 0) {
            cur = min(cur, val);
            res.push_back(cur);
            val -= cur; cur--;
        }
        sort(res.begin(), res.end());
        cout << res.size() << '\n';
        for (auto x : res) cout << x << " ";
        return 0;
    }
    cout << -1;
}
