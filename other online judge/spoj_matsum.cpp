#include <bits/stdc++.h>

using namespace std;

int it[4003][4003], n, q, a[2003][2003];

void modify_y(int x, int y, int val) {
    for (y += n, it[x][y] += val; y >= 1; y >>= 1)
        it[x][y >> 1] = it[x][y] + it[x][y ^ 1];
}

void modify_x(int x, int y, int val) {
    for (x += n; x >= 1; x >>= 1)
        modify_y(x, y, val);
}

int query_y(int x, int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += it[x][l ++];
        if (r & 1) res += it[x][-- r];
    }
    return res;
}

int query_x(int l, int r, int y1, int y2) {
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += query_y(l ++, y1, y2);
        if (r & 1) res += query_y(-- r, y1, y2);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        char s0, s1, s2;
        memset(it, 0, sizeof(it)); memset(a, 0, sizeof(a));
        while (cin >> s0 >> s1 >> s2 && s0 != 'E') {
            if (s1 == 'E') {
                int x, y, v; cin >> x >> y >> v; x++; y++;
                modify_x(x, y, v - a[x][y]); a[x][y] = v;
            }
            else {
                int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
                x1 ++; y1 ++; x2 ++; y2 ++;
                cout << query_x(x1, x2 + 1, y1, y2 + 1) << '\n';
            }
        }

    }
}
