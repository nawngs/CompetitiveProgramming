#pragma GCC optimize ("O3")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "";
const ll ESP = 1e-9;
const int INF = 1e9;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
    string finp = NAME + ".inp";
    string fout = NAME + ".out";
    freopen(finp.c_str(), "r", stdin);
    freopen(fout.c_str(), "w", stdout);
}

int n, m, a[1505], b[1505], f[1505];

int bs(int val) {
    int l = 0, r = n, mid, ans = -1;
    while (l <= r) {
        mid = (l + r) / 2;
        if (a[mid] <= val) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}

void sol() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    for (int i = 1; i <= n; i++) f[i] = -INF;
    f[0] = 0;
    int l = 1;
    for (int i = 1; i <= n; i++) {
        int tam = bs(a[i] / 2);
        for (l; l <= m; l++) {
            if (a[i] == b[l]) {
                f[i] = max(f[tam] + 1, f[i - 1]);
                break;
            }
            if (b[l] > a[i]) break;
        }
    }
    cout << f[n] << '\n';
}

int main() {
    fast;
    fre();
    int t = 1;
    cin >> t;
    while (t --) sol();
}
