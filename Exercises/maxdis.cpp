#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define ull unsigned ll

using namespace std;

int n;

ld l, r, a[100003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("maxdis.inp", "r", stdin);
    freopen("maxdis.out", "w", stdout);
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    ld len = 0;
    ld val = -1;
    if (l <= a[1]) {
        len = a[1] - l;
        val = l;
    }
    for (int i = 2; i <= n; i++) {
        if (r < a[i - 1]) break;
        if (l > a[i]) continue;
        ld mid = (a[i - 1] + a[i]) / 2;
        mid = ceil(mid);
        if (mid < l) mid = l;
        if (mid > r) mid = r;
        ld tam = min(mid - a[i - 1], a[i] - mid);
        if (tam >= len) {
            len = tam;
            val = mid;
        }
    }
    if (r >= a[n]) {
        if (len <= r - a[n]) {
            len = r - a[n];
            val = r;
        }
    }
    if (val < 0) cout << '-';
    cout << (ull) abs(val) << '\n';
}
    