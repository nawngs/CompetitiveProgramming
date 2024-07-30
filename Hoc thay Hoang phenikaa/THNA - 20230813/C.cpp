#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;
const int INF = 1e9;
struct node {
    int l, r, id;
    node() {}
    node(int l_, int r_, int id_) :
        l(l_), r(r_), id(id_) {}
    bool operator<(const node& other) {
        if (l == other.l) {
            if (r == other.r) return id < other.id;
            return r < other.r;
        }
        return l < other.l;
    }
};
int n, m, tx[N], ty[N], px[N], py[N], R[N], sx, sy, limn, limm;
vector<node> v;
string s;

using pii = pair<int, int>;
#define fi first
#define se second

vector<pii> vecx, vecy;
set<int> idx;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> limn;
    limm = limn;
    for (int i = 1; i <= limn; i++) {
        for (int j = 1; j <= limm; j++) {
            char x;
            cin >> x;
            if (x == 'X') {
                ++n;
                tx[n] = i;
                ty[n] = j;
            } else if (x == 'S') sx = i, sy = j;
        }
    }

    cin >> s;
    s = '#' + s;

    int m = s.size();
    for (int i = 1; i < m; i++) {
        px[i] = px[i-1];
        py[i] = py[i-1];
        if (s[i] == 'D') px[i]++;
        if (s[i] == 'U') px[i]--;
        if (s[i] == 'L') py[i]--;
        if (s[i] == 'R') py[i]++;
    }

    for (int i = 0; i < m; i++) {
        R[i] = m;
        v.emplace_back(px[i], py[i], i);
    }

    sort(v.begin(), v.end());

    for (int i = 1; i <= n; i++) {
        int pt = 0;
        for (int j = 0; j < m; j++) {
            int tar_l = tx[i] - sx + v[j].l;
            int tar_r = ty[i] - sy + v[j].r;
            int tar_id = v[j].id;
            node tmp = {tar_l, tar_r, tar_id};
            while (pt < m && !(tmp < v[pt])) ++pt;
            if (pt < m) {
                if (v[pt].l == tar_l && v[pt].r == tar_r)
                    R[v[j].id] = min(R[v[j].id], v[pt].id);
            }
        }
    }


    // sx + (px[r] - px[l]) > limn hoac sx + (px[r] - px[l]) <= 0;
    // => px[r] > limn - sx + px[l] hoac px[r] <= px[l] - sx

    for (int i = 0; i < m; i++) {
        vecx.emplace_back(px[i], i);
        vecy.emplace_back(py[i], i);
    }

    sort(vecx.begin(), vecx.end());
    sort(vecy.begin(), vecy.end());

    int j = m;
    for (int i = m-1; i >= 0; i--) {
        while (j > 0 && vecx[j-1].fi > limn - sx + vecx[i].fi) {
            --j;
            idx.insert(vecx[j].se);
        }

        auto it = idx.upper_bound(vecx[i].se);
        if (it != idx.end()) R[vecx[i].se] = min(R[vecx[i].se], *it);

    }

    idx.clear();
    j = -1;
    for (int i = 0; i < m; i++) {
        while (j < m-1 && vecx[j+1].fi <= vecx[i].fi - sx) {
            ++j;
            idx.insert(vecx[j].se);
        }

        auto it = idx.upper_bound(vecx[i].se);
        if (it != idx.end()) R[vecx[i].se] = min(R[vecx[i].se], *it);

    }

    idx.clear();

    j = m;
    for (int i = m-1; i >= 0; i--) {
        while (j > 0 && vecy[j-1].fi > limn - sy + vecy[i].fi) {
            --j;
            idx.insert(vecy[j].se);
        }

        auto it = idx.upper_bound(vecy[i].se);
        if (it != idx.end()) R[vecy[i].se] = min(R[vecy[i].se], *it);

    }

    idx.clear();
    j = -1;
    for (int i = 0; i < m; i++) {
        while (j < m-1 && vecy[j+1].fi <= vecy[i].fi - sy) {
            ++j;
            idx.insert(vecy[j].se);
        }
        auto it = idx.upper_bound(vecy[i].se);
        if (it != idx.end()) R[vecy[i].se] = min(R[vecy[i].se], *it);

    }
    ll res = 0;
    for (int i = 0; i < m; i++) res += (R[i] - i-1);
    cout << res;
}