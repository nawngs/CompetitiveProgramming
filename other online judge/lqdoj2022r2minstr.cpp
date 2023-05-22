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

const string NAME = "minstr";
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

ll n, m, pow_base[200003], hash_s[200003], len[10003], cnt[200003];

string s, b[10003];

vector < ll > hash_b[10003]; 

map < ll, bool > f;

ll get_hash_s(ll l, ll r) {
	return ((hash_s[r] - (hash_s[l - 1] * pow_base[r - l + 1]) % MOD) % MOD + MOD) % MOD;
}

ll get_hash_b(ll l, ll r, ll id) {
	return ((hash_b[id][r] - (hash_b[id][l - 1] * pow_base[r - l + 1]) % MOD) % MOD + MOD) % MOD;
}

bool check(ll x) {
	f.clear();
	for (int i = 1; i <= m; i++) {
		for (int j = x; j <= len[i]; j++) {
			f[get_hash_b(j - x + 1, j, i)] = 1;	
		}
	}
	memset(cnt, 0, sizeof(cnt));
	for (int i = x; i <= n; i++) {
		if (f[get_hash_s(i - x + 1, i)] == 1) cnt[i] ++;
		cnt[i] += cnt[i - 1];	
	}
	for (int i = n / 2; i <= n; i++) {
		if (cnt[i] - cnt[i - n / 2 + x - 1] == 0) return true;
	}
	return false;
}

int main() {
	fast;
	//fre();
	cin >> n >> m >> s;
	s = ' ' + s + s;
	n = n * 2;
	pow_base[0] = 1;
	for (int i = 1; i <= n; i++)
		pow_base[i] = (pow_base[i - 1] * base) % MOD;
	for (int i = 1; i <= n; i++) 
		hash_s[i] = (hash_s[i - 1] * base + s[i]) % MOD;
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
		len[i] = b[i].size();
		b[i] = ' ' + b[i];
		hash_b[i].resize(b[i].size());
		hash_b[i][0] = 0;;
		for (int j = 1; j <= len[i]; j++) 
			hash_b[i][j] = (hash_b[i][j - 1] * base + b[i][j]) % MOD;
	}
	//check(3);
	int l = 1, r = n / 2, mid, ans = n / 2 + 1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans - 1;
}
