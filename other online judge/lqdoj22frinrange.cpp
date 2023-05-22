#include <bits/stdc++.h>

#define name "inrange"
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

ll n, AA, BB, A, B, P, M;

ll cnt[1003][1003];

pll f[1003];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % M;
	if (b % 2 == 1) x = (x * a) % M;
	return x;
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> AA >> BB >> P >> M;
	A = AA; B = BB;
	ll pre = 0, res = 0;
	if (n <= 1000) {
		f[1] = {A, B};
		for (int i = 2; i <= n; i++) {
			A = (A + pre * P + mu(i + AA, AA)) % M + 1;
			B = (B + pre * P + mu(i + BB, BB)) % M + 1;
			f[i] = {A, B};
			pre = 0;
			for (int j = 1; j < i; j++)
				pre += (f[j].fi < A && f[j].se < B);
			res += pre;
		}
		cout << res;
	}
	else {
		for (int j = B; j <= M; j++) 
				cnt[A][j]++;
		for (int i = 2; i <= n; i++) {
			A = (A + pre * P + mu(i + AA, AA)) % M + 1;
			B = (B + pre * P + mu(i + BB, BB)) % M + 1;
			pre = 0;
			for (int j = 1; j < A; j++)
				pre += cnt[j][B - 1];
			res += pre;
			for (int j = B; j <= M; j++) 
				cnt[A][j]++;
		}
		cout << res;
	}
}