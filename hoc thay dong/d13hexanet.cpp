#include <bits/stdc++.h>

#define pii pair < int, int >
#define fi first
#define se second
#define int long long
using namespace std;

const int INF = 1e18;
const int dx[6] = {-1, -1, 0, 0, 1, 1};
const int dy[6] = {-1, 0, -1, 1, 0, 1};

int n, t, w[3003], a[65][65], d[65][65][(1 << 6)];

map < pii, int > mp;

struct Data {
    int val, x, y, msk;
    Data (int _val, int _x, int _y, int _msk) : val(_val), x(_x), y(_y), msk(_msk) {};
    bool operator < (const Data &oth) const {
        return val > oth.val;
    }
};

bool minimize(int &x, int y) {
    if (x > y) {
        x = y;
        return true;
    }
    return false;
}

signed main() {
    cin >> n >> t;
    for (int i = 1; i <= 1 + 3 * n * (n + 1); i++)
        cin >> w[i];
    mp[{1, 1}] = 0; mp[{1, n + 1}] = 1;
    mp[{n + 1, 1}] = 2; mp[{n + 1, 2 * n + 1}] = 3;
    mp[{2 * n + 1, n + 1}] = 4; mp[{2 * n + 1, 2 * n + 1}] = 5;
    w[0] = INF;
    a[n + 1][n + 1] = 1;
    pii pos = {n + 1, n + 1};
    int len = 1, cur = 1;
    while (len <= n) {
        for (int i = 1; i <= len; i++) {
            pos.fi --;
            a[pos.fi][pos.se] = ++ cur;
        }
        for (int i = 1; i < len; i++) {
            pos.se ++;
            a[pos.fi][pos.se] = ++ cur;
        }
        for (int i = 1; i <= len; i++) {
            pos.fi ++; pos.se ++;
            a[pos.fi][pos.se] = ++ cur;
        }
        for (int i = 1; i <= len; i++) {
            pos.fi ++;
            a[pos.fi][pos.se] = ++ cur;
        }
        for (int i = 1; i <= len; i++) {
            pos.se --;
            a[pos.fi][pos.se] = ++ cur;
        }
        for (int i = 1; i <= len; i++) {
            pos.fi --; pos.se --;
            a[pos.fi][pos.se] = ++ cur;
        }
        len ++;
    }
    while (cur <= 1 + 3 * n * (n + 1)) {
        pos.fi --;
        a[pos.fi][pos.se] = ++ cur;
    }
    /*
    for (int i = 1; i <= 2 * n + 1; i++) {
        for (int j = 1; j <= 2 * n + 1; j++) cout << a[i][j] << " ";
        cout << '\n';
    }
    */
    for (int i = 1; i <= 2 * n + 1; i++)
        for (int j = 1; j <= 2 * n + 1; j++)
            a[i][j] = w[a[i][j]];
    priority_queue < Data > heap;
    for (int i = 1; i <= 2 * n + 1; i++)
        for (int j = 1; j <= 2 * n + 1; j++)
            for (int msk = 0; msk < (1 << 6); msk++) d[i][j][msk] = INF;
    for (int i = 1; i <= 2 * n + 1; i++)
        for (int j = 1; j <= 2 * n + 1; j++) {
            d[i][j][0] = 0;
            heap.push({0, i, j, 0});
        }
    for (auto x : mp) {
        d[x.fi.fi][x.fi.se][(1 << x.se)] = 0;
        heap.push({0, x.fi.fi, x.fi.se, (1 << x.se)});
    }
    while (!heap.empty()) {
        auto u = heap.top(); heap.pop();
        int i = u.x, j = u.y, val = u.val, msk = u.msk;
        if (val != d[i][j][msk]) continue;
        for (int newmsk = msk + 1; newmsk < (1 << 6); newmsk++) if (newmsk & msk == msk) {
            if (minimize(d[i][j][newmsk], val + d[i][j][newmsk ^ msk]))
                heap.push({d[i][j][newmsk], i, j, newmsk});
        }
        for (int p = 0; p < 6; p++) {
            int newi = i + dx[p], newj = j + dy[p], newmsk = msk;
            if (newi < 1 || newj < 1 || newi > 2 * n + 1 || newj > 2 * n + 1) continue;
            if (mp.find({newi, newj}) != mp.end()) newmsk ^= (1 << mp[{newi, newj}]);
            if (minimize(d[newi][newj][newmsk], val + a[i][j])) {
                heap.push({val + a[i][j], newi, newj, newmsk});
            }
        }
    }
    if (t == 1) {
        int res = INF;
        for (int i = 1; i <= 2 * n + 1; i++)
            for (int j = 1; j <= 2 * n + 1; j++)
                for (int msk = 1; msk < (1 << 6); msk++) if ((msk & 25) == 25) {
                    res = min(res, d[i][j][msk] + a[i][j]);
                }
        cout << res;
    }
    else {
        int res = INF;
        for (int i = 1; i <= 2 * n + 1; i++)
            for (int j = 1; j <= 2 * n + 1; j++) res = min(res, d[i][j][(1 << 6) - 1] + a[i][j]);
        cout << res;
    }
}
