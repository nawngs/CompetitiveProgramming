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
const int BLOCK_SIZE = 320;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

ll n, m, q, a[100003], cnt[BLOCK_SIZE + 3][100003], sum[100003], add[100003];

bool check[100003];

vector < int > group[100003], bigaf, smallaf;

int main() {
	fast;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) {
		int sze;
		cin >> sze;
		if (sze >= BLOCK_SIZE) bigaf.push_back(i);
		else smallaf.push_back(i);
		for (int j = 1; j <= sze; j++) {
			int x;
			cin >> x;
			sum[i] += a[x];
			group[i].push_back(x);
		}
	}
	for (int i = 0; i < bigaf.size(); i++) {
		for (int j = 1; j <= n; j++) check[j] = false;
		for (auto x : group[bigaf[i]]) check[x] = 1;
		for (int j = 1; j <= m; j++) {
			int dem = 0;
			for (auto x : group[j]) dem += check[x];
			cnt[i][j] = dem;
		}
	}
	while (q--) {
		char c;
		cin >> c;
		if (c == '+') {
			ll id, x;
			cin >> id >> x;
			if (group[id].size() >= BLOCK_SIZE) add[id] += x;
			else for (auto i : group[id]) a[i] += x;
			for (int i = 0; i < bigaf.size(); i++)
				sum[bigaf[i]] += x * cnt[i][id];	 
		}
		else {
			int id;
			cin >> id;
			if (group[id].size() >= BLOCK_SIZE) cout << sum[id] << '\n';
			else {
				ll res = 0;
				for (auto i : group[id]) res += a[i];
				for (int i = 0; i < bigaf.size(); i++)
					res += add[bigaf[i]] * cnt[i][id];
				cout << res << '\n'; 
			}
		}
	}
}
