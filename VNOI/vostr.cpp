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
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, m, hasha[1000002], hashb[1000002], pow_base[1000002];

string a, b;

void create() {
	pow_base[0] = 1;
	for(int i = 1; i <= 1000000; i++){
		pow_base[i] = (pow_base[i - 1] * base) % MOD;
	}
}

void build_hash(string str, ll arr[]){
	for(int i = 1; i < str.size(); i++){
		arr[i] = (arr[i - 1] * base + str[i]) % MOD;
	}
}

ll get_hash(ll l, ll r, ll arr[]){
	return (arr[r] - arr[l - 1] * pow_base[r - l + 1] + MOD * MOD) % MOD;
}

void sol() {;
	cin >> n >> m >> a >> b;
	a = ' ' + a;
	b = ' ' + b;
	create();
	build_hash(a, hasha);
	build_hash(b, hashb);	
	ll q;
	cin >> q;
	while (q --) {
		ll l, r, u, v;
		cin >> l >> r >> u >> v;
		ll len = min(r - l + 1, v - u + 1);
		ll left = 1, right = len, mid, ans = 0;
		while (left <= right) {
			mid = (left + right) / 2;
			if (get_hash(l, l + mid - 1, hasha) == get_hash(u, u + mid - 1, hashb)) {
				ans = mid;
				left = mid + 1;
			}
			else right = mid - 1;
		}
		if (ans == len) {
			if (r - l + 1 == v - u + 1) cout << '=';
			else if (r - l + 1 > v - u + 1) cout << '>';
				else cout << '<';
		}
		else {
			if (a[l + ans] > b[u + ans]) cout << '>';
			else cout << '<';
		}
	}
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
