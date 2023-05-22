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

const string NAME = "word";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
    string finp = NAME + ".inp";
    string fout = NAME2 + ".out";
    freopen(finp.c_str(), "r", stdin);
    freopen(fout.c_str(), "w", stdout);
}

int n;

int dp[103][103][103][33];

int f[103][103];

vector < int > pos[30];

pair < string, int > a[1003];

string s;   

void readINP() {
    cin >> s >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].fi >> a[i].se;
}

void init() {
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            f[i][j] = -INF;
            for (int str = 1; str <= n; str ++) {
                for (int k = 0; k < a[str].fi.size(); k++) dp[i][j][str][k] = -INF;
            }
        }
    }
}

void solve() {
    for (int i = s.size() - 1; i >= 0; i--) {
        for (int j = 0; j <= 'z' - 'a'; j++) pos[j].clear();
        for (int j = i; j < s.size(); j++) {
            for (int str = 1; str <= n; str ++) {
                for (int k = 0; k < a[str].fi.size(); k++) {
                    if (s[j] == a[str].fi[k]) {
                        if (k == 0) {
                            dp[i][j][str][k] = f[i][j - 1];
                            continue;
                        }
                        for (auto v : pos[a[str].fi[k - 1] - 'a']) {
                            if (dp[i][v][str][k - 1] != -INF && f[v + 1][j - 1] != -INF)
                                 dp[i][j][str][k] = max(dp[i][j][str][k], dp[i][v][str][k - 1] + f[v + 1][j - 1]);
                        }
                    }
                }
                if (dp[i][j][str][a[str].fi.size() - 1] != -INF) {
                    dp[i][j][str][a[str].fi.size() - 1] += a[str].se;
                    f[i][j] = max(f[i][j], dp[i][j][str][a[str].fi.size() - 1]);
                }
            }
            pos[s[j] - 'a'].push_back(j);
        }
    }
}

void printANS() {
    ll ans = 0;
    for (int len = 1; len <= s.size(); len ++) {
        for (int i = 0; i <= s.size() - len; i++) {
            int j = i + len - 1;
            f[i][j] = max(0, f[i][j]);
            for (int k = i; k < j; k++) f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j]);
            ans = max(ans, 1ll * f[i][j]);
            //cout << i << " " << j << " " << f[i][j] << '\n';
        }
    }
    cout << ans;
}

int main() {
    fast;
    fre();    
    readINP();
    init();
    solve();
    printANS();
}
