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

const string NAME = "COMST";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const int INF = 1E9 + 7;;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;

void fre() {
    string finp = NAME + ".inp";
    string fout = NAME + ".out";
    freopen(finp.c_str(), "r", stdin);
    freopen(fout.c_str(), "w", stdout);
}

int next_pos[100005][30], n, m, dp[1005][1005];

string s, t;

void build_next_pos() {
	memset(next_pos, 255, sizeof(next_pos));
    for (int i = 0; i <= 25; i++) {
        for (int j = n; j >= 0; j --) next_pos[j][i] = s[j] - 'a' == i ? j : next_pos[j + 1][i];
    }
}

void sol() {
    cin >> t;
    m = t.size();
    t = ' ' + t;
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= min(m, n); j++) dp[i][j] = INF;
    dp[0][0] = 0;
    int ans = 0;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= min(n, i); j++) {
            //cout << i << " " << j << " " <<  dp[i][j] << '\n';
            if (dp[i][j] != INF) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
               //cout << i << " " << j << " " << next_pos[dp[i][j] + 1][t[i + 1] - 'a'] << '\n';
                if (next_pos[dp[i][j] + 1][t[i + 1] - 'a'] != -1) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], next_pos[dp[i][j] + 1][t[i + 1] - 'a']);
                ans = max(ans, j);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    fast;
    fre();
    cin >> s;
    n = s.size();
    s = ' ' + s;
    build_next_pos();
    int t = 1;
    cin >> t;
    while (t --) sol();
}