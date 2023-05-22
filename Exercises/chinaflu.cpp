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

const string NAME = "chinaflu";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e15 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, m, mu[300003], hash_node[300003];

pii a[300003];

ll ans = 0, dem = 0;

int main() {
	fast;
	fre();
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> a[i].fi >> a[i].se;
	mu[0] = 1;
	for (int i = 1; i <= n; i++) mu[i] = (mu[i - 1] * base) % MOD;
	for (int i = 1; i <= m; i++) {
		hash_node[a[i].fi] = (hash_node[a[i].fi] + mu[a[i].se]) % MOD;
		hash_node[a[i].se] = (hash_node[a[i].se] + mu[a[i].fi]) % MOD;
	}
	sort(hash_node + 1, hash_node + n + 1);
	dem = 1;
	for (int i = 2; i <= n; i++) {
		if (hash_node[i] == hash_node[i - 1]) dem ++;
		else {
			ans += (dem * (dem - 1)) / 2;
			dem = 1;
		}
	}	
	ans += (dem * (dem - 1)) / 2;
	memset(hash_node, 0, sizeof(hash_node));
	for (int i = 1; i <= n; i++) hash_node[i] = mu[i];
	for (int i = 1; i <= m; i++) {
		hash_node[a[i].fi] = (hash_node[a[i].fi] + mu[a[i].se]) % MOD;
		hash_node[a[i].se] = (hash_node[a[i].se] + mu[a[i].fi]) % MOD;
	}
	sort(hash_node + 1, hash_node + n + 1);
	dem = 1;
	for (int i = 2; i <= n; i++) {
		if (hash_node[i] == hash_node[i - 1]) dem ++;
		else {
			ans += (dem * (dem - 1)) / 2;
			dem = 1;
		}
	}	
	ans += (dem * (dem - 1)) / 2;
	cout << ans;
}
