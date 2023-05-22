#include <bits/stdc++.h>

#define int long long

using namespace std;

int n, X[10], Y[10], R[10];

signed main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> X[i] >> Y[i] >> R[i];
    int res = 0;
    for (int msk = 1; msk < (1 << n); msk++) {
        int x = 0, y = 0, r = 1e7;
        for (int i = 0; i < n; i++) if (msk >> i & 1) {
            r = min(X[i] + Y[i] + R[i], x + y + r);
            int newx = max(x, X[i]), newy = max(y, Y[i]);
            x = newx, y = newy;
            r -= x + y;
            r = max(0ll, r);
        }
        int sze = __builtin_popcount(msk);
        if (sze & 1) res += (1 << sze - 1) * r * r;
        else res -= (1 << sze - 1) * r * r;
    }
    cout << fixed << setprecision(1) << 1.0 * res / 2;
}
