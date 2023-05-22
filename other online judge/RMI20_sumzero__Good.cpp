#include <bits/stdc++.h>
 
using namespace std;
unsigned seed = chrono :: system_clock :: now().time_since_epoch().count();
mt19937 rng(seed);
using ll = long long;
const int N = 4e5 + 5;
ll c[N];
ll dp[N];
const ll P1 = (1ll << 20) - 1, P2 = ((1ll << 20) - 1) << 20, P3 = ((1ll << 20) - 1) << 40;
 
int main()
{
    ios_base :: sync_with_stdio(false); cin.tie(0);
    int n, q;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    cin >> q;
    partial_sum(c + 1, c + n + 1, c + 1);
    set <ll> s;
    dp[n + 1] = n + 1;
    for(int i = n; i >= 0; i--) {
        auto it = s.lower_bound(c[i] << 20);
        if(it != s.end() && (*it >> 20) == c[i]) {
            ll val = *it & P1;
            dp[i] = min(val, dp[i + 1]);
            s.erase(it);
        } else dp[i] = dp[i + 1];
        s.insert(c[i] << 20 | i);
    }
    s.clear();
    for(ll i = 1, l, r; i <= q; i++) {
        cin >> l >> r;
        l--;
        c[i] = (l | (r << 20));
    }
    dp[n + 1] = (n + 1) * (1 + (1 << 20) + (1ll << 40));
    for(int k = 9; k >= 1; k--) {
        int kk = 2 * (k - 1);
        for(int i = 0; i <= n; i++) {
            dp[i] &= ~P2;
            int from = dp[i] & P1;
            dp[i] |= ll(dp[from] & P1) << 20;
        }
        for(int i = 0; i <= n; i++) {
            dp[i] &= ~P3;
            int from = (dp[i] & P2) >> 20;
            dp[i] |= ll(dp[from] & P2) << 20;
        }
        for(int j = 2; j <= k; j++) {
            for(int i = 0; i <= n; i++) {
                dp[i] &= ~P2;
                int from = (dp[i] & P3) >> 40;
                dp[i] |= ll(dp[from] & P3) >> 20;
            }
            for(int i = 0; i <= n; i++) {
                dp[i] &= ~P3;
                int from = (dp[i] & P2) >> 20;
                dp[i] |= ll(dp[from] & P2) << 20;
            }
        }
        for(ll i = 1, l, r, res; i <= q; i++) {
            l = c[i] & P1;
            r = (c[i] & P2) >> 20;
            res = (c[i] & P3) >> 40;
            if(((dp[l] & P3) >> 40) <= r)
                res |= (1 << (kk + 2)),
                l = (dp[l] & P3) >> 40;
            if(((dp[l] & P2) >> 20) <= r)
                res |= (1 << (kk + 1)),
                l = (dp[l] & P2) >> 20;
            if(k == 1 && (dp[l] & P1) <= r)
                res |= (1 << kk),
                l = dp[l] & P1;
            c[i] = (l | (r << 20) | (res << 40));
            if(k == 1) cout << res << "\n";
        }
    }
    return 0;
}