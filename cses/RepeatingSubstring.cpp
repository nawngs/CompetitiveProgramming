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

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 1e7;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME2 + ".inp";
	string fout = NAME2 + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll pow_base[100003], hash_s[100003], pos, n;

vector < pll > temp;

string s;

void create() {
	pow_base[0] = 1;
	for(int i = 1; i <= 100001; i++){
		pow_base[i] = (pow_base[i - 1] * base) % MOD;
	}
}

ll get(ll l, ll r){
	return (hash_s[r] - (hash_s[l - 1] * pow_base[r - l + 1]) + MOD * MOD) % MOD;
}

bool check(ll x) {
	temp.clear();
	for (int i = 1; i <= n - x; i++) temp.push_back({get(i, i + x), i});
	sort(temp.begin(), temp.end());
	for (int i = 1; i < temp.size(); i++) {
		if (temp[i].fi == temp[i - 1].fi) {
			pos = temp[i].se;
			return true;
		}
	}
	return false;
}

void sol() {
	create();
	cin >> s;
	n = s.size();
	s = ' ' + s;
	for (int i = 1; i <= n; i++) hash_s[i] = (hash_s[i - 1] * base + s[i]) % MOD;
	ll l = 0, r = n, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	if (ans == -1) cout << ans;
	else for (int i = pos; i <= pos + ans; i++) cout << s[i];
	
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
