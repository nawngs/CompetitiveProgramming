#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned ll
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "coltri";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e6;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
    string finp = NAME + ".inp";
    string fout = NAME + ".out";
    //freopen(finp.c_str(), "r", stdin);
    freopen(fout.c_str(), "w", stdout);
}

ull n, dem[nmax + 3];

bool f[nmax + 3];

void sang() {
    memset(f, 1, sizeof(f));
    f[1] = f[0] = false;
    for (int i = 2; i * i <= nmax; i++)
        if (f[i]) for (int j = i * i; j <= nmax; j+=i) f[j] = false;
    for (int i = 1; i <= nmax; i++) dem[i] = dem[i - 1] + f[i - 1];
}

void sol() {
    cin >> n;
    ull s = 0;
    for (int i = 1; i <= n; i++) {
        pll tam;
        tam.fi = dem[i * 2] - dem[i + 1];
        tam.se = dem[i + n + 1] - dem[i * 2 + 1];
        s += (tam.fi + tam.se) * (n - 2) - (tam.fi + tam.se) * (tam.fi + tam.se - 1);
    }
    cout << s << '\n';
    cout << n * (n - 1) * (n - 2) / 6 - s / 2 << '\n';
} 

int main() {
    fast;
    fre();
    sang();
    int t = 1;
    cin >> t;
    while (t --) sol();
}
