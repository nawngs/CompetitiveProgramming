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

const string NAME = "taxi";
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


ll n, x[5005], y[5005];

double f[5005][5005], ans = 1e18;

double calc_dis(ll a, ll b, ll c, ll d){
    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

void sol() {
    cin >> n;
    for(int i = 0; i <= n; i++) 
        for(int j = 0; j <= n; j++) f[i][j] = 1e18;
    for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    f[0][0] = 0;
    for(int i = 0; i <= n; i++){
        for(int j = i; j <= n; j++){
            f[j][j + 1] = min(f[j][j + 1], f[i][j] + calc_dis(x[i], y[i], x[j + 1], y[j + 1]));
            f[i][j + 1] = min(f[i][j + 1], f[i][j] + calc_dis(x[j], y[j], x[j + 1], y[j + 1]));
            if(j == n) ans = min(ans, f[i][j]);
        }
    }
    cout << fixed << setprecision(3) << ans;
}

int main() {
    fast;
    fre();
    int t = 1;
    //cin >> t;
    while (t --) sol();
}
