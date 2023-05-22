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

const string NAME = "";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, k, s[2003], b[2003];

bool check(ll x) {
	unordered_set < int > tam;
	for (int i = 1; i <= n; i++) tam.insert(x + s[i]);
	for (int i = 1; i <= k; i++) if (!tam.count(b[i])) return false;
	
	return true; 
}

void sol() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		s[i] = s[i - 1] + x;
	}
	for (int i = 1; i <= k; i++) cin >> b[i];
	unordered_set < int > st;
	for (int i = 1; i <= n; i++) st.insert(b[1] - s[i]);
	int ans = 0;
	sort(b + 1, b + k + 1);
	for (auto x : st) if (check(x)) ans ++;
	cout << ans;
}

int main() {
	fast;
	//fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
