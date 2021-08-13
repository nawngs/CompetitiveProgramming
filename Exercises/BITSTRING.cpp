#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MOD = 1000007;

ll n, k, dp[1000005], sumdp[1000005];

ll mu(ll a, ll b){
	if(b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if(b % 2 == 1) x = (x * a) % MOD;
	return x;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("BITSTRING.inp", "r", stdin);
    freopen("BITSTRING.out", "w", stdout);
	cin >> n >> k;
	memset(dp, 0, sizeof(dp));
	memset(sumdp, 0, sizeof(sumdp));
	dp[k] = 1;
	sumdp[k] = 1;
	for(int i = k + 1; i <= n; i++){
        dp[i] = ((sumdp[i - 1] - sumdp[i - k - 1] + MOD) % MOD + mu(2, i - k)) % MOD;
        sumdp[i] = (sumdp[i - 1] + dp[i]) % MOD;
    }
	cout << dp[n] % MOD;
}
