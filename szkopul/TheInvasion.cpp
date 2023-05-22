#include <bits/stdc++.h>

using namespace std;

const int INF = 1E9 + 7;

struct Point {
    int x, y, w, id;
} p[603], q[20003];

int n, m, f[604][603];

int cross(const Point &A, const Point &B) {
    return A.x * B.y - A.y * B.x;
}

int CCW(const Point &A, const Point &B, const Point &C) {
    Point AC = C; AC.x -= A.x; AC.y -= A.y;
    Point AB = B; AB.x -= A.x; AB.y -= A.y;
    return cross(AB, AC);
}

int sign(int v) {
    if (v == 0) return 0;
    return (v > 0 ? 1 : -1);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y; p[i].w = 0, p[i].id = i;
        q[i] = p[i];
    }
    cin >> m;
    int total = 0;
    for (int i = 1; i <= m; i++) {
        cin >> q[i + n].x >> q[i + n].y >> q[i + n].w;
        q[i + n].id = -1;
        total += q[i + n].w;
    }
    for (int i = 1; i <= n; i++) {
        sort(q + 1, q + n + m + 1, [&](Point &x, Point &y) {
            if (x.id == i) return true;
            if (y.id == i) return false;
            int temp = sign(CCW(p[i], x, y));
            return (temp > 0) || (temp == 0 && x.id < y.id);
        });
        int s = 0;
        for (int j = 1; j <= n + m; j++) {
            if (q[j].id != -1) {
                f[i][q[j].id] = s;
            }
            s += q[j].w;
        }
    }
    int res = -INF;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            for (int k = j + 1; k <= n; k++)
                res = max(res, -2 * total + f[i][j] + f[j][k] + f[k][i]);
    cout << res;
}
