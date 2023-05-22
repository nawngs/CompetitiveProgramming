#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5005;
ll n;
int dp[N][N];
vector<ll> u;
int recur(int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];
    if (i == j) return 0;
    int v = j - 1;
    int ret = 0;
    for (int t = i; t <= j && u[t] * u[t] <= u[j]; t++) {
        if (u[j] % u[t] == 0) {
            ll tmp = u[j] / u[t];
            while (u[v] > tmp) --v;
            ret += recur(t, v) + 1;
        }
    }
    return dp[i][j] = ret;	
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("factor.inp", "r", stdin);
    freopen("factor.out", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        u.clear();
        for (ll i = 1; i * i <= n; i++) {
            if (n % i != 0) continue;
            u.push_back(i);
            if (i * i != n) u.push_back(n/i);
        }
        sort(u.begin(), u.end());
        memset(dp, -1, sizeof dp);
        cout << recur(1, u.size() - 1) << '\n';
    }
}