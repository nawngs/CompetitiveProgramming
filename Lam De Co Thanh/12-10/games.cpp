#include <bits/stdc++.h>

#define pii pair < int, int >
#define piii pair < pii, int >
#define fi first
#define se second

using namespace std;

vector < pii > a, b;

vector < piii > res;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("games.inp", "r", stdin);
    freopen("games.out", "w", stdout);
    int s = 0;
    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        a.push_back({x, i});
        s += x;
    }
    sort(a.begin(), a.end());
    if (a[3].fi == 0) {
        cout << 0 << '\n';
        return 0;
    }
    while (a[2].fi == 0) {
        res.push_back({{a[3].se, a[4].se}, a[2].se});
        a[2].fi += 2;
        a[3].fi --;
        a[4].fi --;
        sort(a.begin(), a.end());
    }
    int pos = 0;
    for (int i = 4; i >= 0; i--) {
        if ((s - a[i].fi) % 2 == 0) {
            pos = i;
            for (int j = 0; j < 5; j++) {
                if (j != i) b.push_back(a[j]);
            }
            break;
        }
    }
    s -= a[pos].fi;
    sort(b.begin(), b.end());
    while (b.back().fi > s / 2) {
        res.push_back({{b[3].se, b[2].se}, b[0].se});
        b[0].fi += 2;
        b[3].fi --;
        b[2].fi --;
        sort(b.begin(), b.end());
    }
    while (b.back().fi != 0) {
         res.push_back({{b[3].se, b[2].se}, a[pos].se});
        b[3].fi --;
        b[2].fi --;
        sort(b.begin(), b.end());
    }
    cout << res.size() << '\n';
    for (auto x : res) cout << x.fi.fi + 1 << " " << x.fi.se + 1 << " " << x.se + 1 << '\n';
}
