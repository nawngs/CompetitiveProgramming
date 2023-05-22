#include <bits/stdc++.h>

#define int long long

using namespace std;

struct Point {
    int x, y;
    Point(int _x = 0, int _y = 0) {
        x = _x, y = _y;
    }
};
int cross(const Point &A, const Point &B) {
    return A.x * B.y - A.y * B.x;
}

using Polygon = vector < Point >;

int W, H, n, m, Q;

int Area(const Polygon &poly) {
    int n = poly.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += cross(poly[i], poly[(i + 1) % n]);
    }
    res = abs(res);
    return res;
}

bool check(const Point &P, const Polygon &poly) {
    int n = poly.size(); int res = 0;
    for (int i = 0; i < n; i++) {
        res += Area({P, poly[i], poly[(i + 1) % n]});
    }
    return res == Area(poly);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("paint.inp", "r", stdin);
    freopen("paint.out", "w", stdout);
    cin >> W >> H >> n >> m >> Q;
    vector < Polygon > polys(n);
    for (auto &poly : polys) {
        poly.resize(m);
        for (auto &p : poly) cin >> p.x >> p.y;
    }
    polys.push_back({Point(0, 0), Point(0, H), Point(W, H), Point(W, 0)}); n += 1;
    sort(polys.begin(), polys.end(), [&](Polygon &x, Polygon &y) {
        return Area(x) < Area(y);
    });
    vector < int > PolyArea;
    for (int i = 0; i < n; i++) PolyArea.push_back(Area(polys[i]));
    for (int i = n - 1; i >= 0; i--) {
        Point p = polys[i][0];
        for (int j = i + 1; j < n; j++) {
            if (check(p, polys[j])) {
                PolyArea[j] -= PolyArea[i];
                break;
            }
        }
    }
    while (Q--) {
        Point P; cin >> P.x >> P.y;
        for (int i = 0; i < n; i++)
            if (check(P, polys[i])) {
                cout << fixed << setprecision(1) << 1.0 * PolyArea[i] / 2 << '\n';
                break;
            }
    }
}


