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

const string NAME = "Ferriswheel";
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

ll n, k, a[4003][4003], f[4003][803], s[4003][803];

ll get(ll l, ll r) {
	return s[r][r] - s[r][l - 1] - s[l - 1][r] + s[l - 1][l - 1];
}

void calc(ll d, ll l, ll r, ll low, ll high) {
	if (r < l) return ;
	ll mid = (l + r) / 2, val = -1;
	f[mid][d] = LINF;
	for (int i = low; i <= min(mid, high); i++) {
		if (f[i][d - 1] + get(i + 1, mid) < f[mid][d]) {
			cout << f[i][d - 1] << " " << get(i + 1, mid) << '\n';
			f[mid][d] = f[i][d - 1] + get(i + 1, mid);
			val = i;
		}
	}
	//cout << d << " " << mid << " " << f[mid][d] << '\n';
	calc(d, l, mid - 1, low, val);
	calc(d, mid + 1, r, val, high);
}

int main() {
	fast;
	//fre();
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			s[i][j] = s[i][j - 1] + s[i - 1][j] + a[i][j] - s[i - 1][j - 1];
		}

	for (int i = 1; i <= n; i++) f[i][1] = get(1, i);
	for (int i = 1; i <= k; i++) calc(i, 1, n, 1, n);
	cout << f[n][k];
}
