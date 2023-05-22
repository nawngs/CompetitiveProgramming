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

ll k, pow_base[50002], hashs[50002], n;

string s;

vector < ll > p;


void create() {
	pow_base[0] = 1;
	for(int i = 1; i <= 50000; i++){
		pow_base[i] = (pow_base[i - 1] * base) % MOD;
	}
}

void build_hash(string str, ll arr[]){
	for(int i = 1; i < str.size(); i++){
		arr[i] = (arr[i - 1] * base + str[i]) % MOD;
		cout << arr[i] << '\n';
	}
}

ll get_hash(ll l, ll r, ll arr[]){
	return (arr[r] - arr[l - 1] * pow_base[r - l + 1] + MOD * MOD) % MOD;
}

bool check(ll x) {
	p.clear();
	for (int i = x; i <= n; i++) 
		p.push_back(get_hash(i - x + 1, i, hashs));
	sort(p.begin(), p.end());
	ll dem = 1, ans = 1;
	for (int i = 1; i < p.size(); i++) {
		if (p[i] == p[i - 1]) dem ++;
		else {
			ans = max(ans, dem);
			dem = 1;
		}
	}
	ans = max(ans, dem);
	return ans >= k;
}

void sol() {
	cin >> n >> k >> s;
	s = ' ' + s;
	create();
	build_hash(s, hashs);
	int l = 1, r = n, mid, ans = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}	
	cout << ans;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
