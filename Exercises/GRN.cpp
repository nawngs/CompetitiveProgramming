#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "grn";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
    string finp = NAME + ".inp";
    string fout = NAME + ".out";
    freopen(finp.c_str(), "r", stdin);
    freopen(fout.c_str(), "w", stdout);
}

int n, a[2000003];

bool check() {
    for (int i = 2; i <= 2 * n; i++) if (a[i] != a[i - 1] + 1) return false;
    return true;
}

void ezver() {
    int dem = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            dem ++;
            if (i != n / i) dem ++;
        }
    }
    cout << dem;
}

bool th[2003];

int bs(int pos, int x) {
    int l = pos + 1, r = 2 * n, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (a[mid] == x) return mid;
        if (a[mid] > x) r = mid - 1;
        if (a[mid] < x) l = mid + 1;
    }
    return -1;
}

bool chck(int val) {
    memset(th, false, sizeof(th));
    for (int i = 1; i <= 2 * n; i++) {
        if (th[i]) continue;
        th[i] = 1;
        int tam = bs(i, val + a[i]);
        if (tam == -1) return false;
        th[tam] = 1;
    }
    return true;
}

void hardver() {
    vector < int > f, g;
    for (int i = 1; i <= 2 * n; i++) 
        for (int j = i + 1; j <= 2 * n; j++) f.push_back(a[j] - a[i]);
    sort(f.begin(), f.end());
    int dem = 1;
    int res = 0;
    for (int i = 1; i < f.size(); i++) {
        if (f[i] == f[i - 1]) dem ++;
        else {
            if (dem >= n) g.push_back(f[i - 1]);
            dem = 1;
        }
    }
    if (dem == n) g.push_back(f[f.size() - 1]);
    for (auto x : g) res += chck(x);
    cout << res;
}

void sol() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) cin >> a[i];
    sort(a + 1, a + 2 * n + 1);
     if (check()) ezver();
     else hardver();
}

int main() {
    fast;
    fre();
    int t = 1;
    //cin >> t;
    while (t --) sol();
}
