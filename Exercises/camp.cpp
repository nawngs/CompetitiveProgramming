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

const string NAME = "camp";
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

ll m, n, f[1005][1005][3];

pair < ll, ll > hn[1005], hcm[1005];

ll calc_dis(ll a, ll b, ll c, ll d){
    return (a - c) * (a - c) + (b - d) * (b - d);
}

void sol() {
    cin >> m >> n;
    for(int i = 1; i <= m; i++) cin >> hn[i].fi >> hn[i].se;
    for(int i = 1; i <= n; i++) cin >> hcm[i].fi >> hcm[i].se;

    for(int i = 1; i <= m; i++)
        for(int j = 0; j <= n; j++) 
            for(int k = 1; k <= 2; k++) f[i][j][k] = 1e18;
    //f[1][1][2] = calc_dis(hn[1].fi, hn[1].se, hcm[1].fi, hcm[1].se);
    f[1][0][1] = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 0; j <= n; j++){
            f[i + 1][j][1] = min(f[i + 1][j][1], min(f[i][j][1] + calc_dis(hn[i].fi, hn[i].se, hn[i + 1].fi, hn[i + 1].se), 
                                                    f[i][j][2] + calc_dis(hcm[j].fi, hcm[j].se, hn[i + 1].fi, hn[i + 1].se)));
            //################################################################################################################################
            f[i][j + 1][2] = min(f[i][j + 1][2], min(f[i][j][1] + calc_dis(hn[i].fi, hn[i].se, hcm[j + 1].fi, hcm[j + 1].se), 
                                                    f[i][j][2] + calc_dis(hcm[j].fi, hcm[j].se, hcm[j + 1].fi, hcm[j + 1].se)));
            //cout << i << " " << j << " " << f[i][j][1] << " " << f[i][j][2] << '\n';
        }
    }
    cout << f[m][n][1];   
}

int main() {
    fast;
    fre();
    int t = 1;
    //cin >> t;
    while (t --) sol();
}
