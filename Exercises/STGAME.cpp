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

const string NAME = "stgame";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, a[60003], mx = 0, s[60003], res = INF, dp[60003];

map < int , ll > f;

void solve(ll x) {
	memset(dp, 0, sizeof(dp));
	ll cur = 0;
	for (int i = 1; i <= 2 * n; i++) {
		cur += a[i];
		if (f.find(cur - x) != f.end()) dp[i] = dp[f[cur - x]] + 1;
		if (dp[i] >= s[n] / x) {
			res = min(res, n - s[n] / x);
			return ;
		}
	}
}

int main() {
	fast;
	fre();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
		s[i] = s[i - 1] + a[i];
		f[s[i]] = i;
	}
	for (int j = n + 1; j <= 2 * n; j++) {
		a[j] = a[j - n];
		s[j] = s[j - 1] + a[j];
		f[s[j]] = j;
	}
	vector<ll> dv;
    for (int i = 1; i * i <= s[n]; i ++)
        if (s[n] % i == 0) {
            if (i >= mx) dv.push_back(i);
            if ( i * i != s[n] && s[n] / i >= mx)
                dv.push_back(s[n] / i);
        }
    f[0] = 0;
    for (auto x : dv) 
    	solve(x);
    cout << res;
}

/*
#include<bits/stdc++.h>
#define ll long long
#define int ll
#define pb push_back
using namespace std;
const int N = 3e4 + 5;

int n, ans, sum;
int a[2*N], f[2*N];
map<ll, int> d;

void solve(ll k){
    for (int i = 1; i <= 2*n; i ++) f[i] = 0;
    ll s = 0;
    for (int i = 1; i <= 2*n; i ++){
        s += a[i];
        if ( d.find(s-k) != d.end() ) f[i] = f[d[s-k]] + 1;
        if ( f[i] >= sum/k ){
            ans = min(ans, n-sum/k);
            return;
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    freopen("stgame.inp", "r", stdin);
    freopen("stgame.out", "w", stdout);

    cin >> n;
    sum = 0;
    int mx = 0;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }

    vector<ll> div;
    for (int i = 1; i * i <= sum; i ++)
        if ( sum % i == 0 ){
            if ( i >= mx ) div.pb(i);
            if ( i * i != sum && sum/i >= mx )
                div.pb(sum/i);
        }

    for (int i = n+1; i <= 2*n; i ++) a[i] = a[i-n];
    d[0] = 0, sum = 0;
    for (int i = 1; i <= 2*n; i ++)
        sum += a[i], d[sum] = i;
    sum /= 2;

    ans = n + 1;
    for (int x : div)
        solve(x);

    cout << ans;

    return 0;
}*/
