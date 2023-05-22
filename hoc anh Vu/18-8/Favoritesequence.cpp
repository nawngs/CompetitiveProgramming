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
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME2 + ".inp";
	string fout = NAME2 + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, k, a[1003][1003], cnt[1000003];

bool used[1000003];

vector < int > adj[1000003], val, res;

int main() {
	fast;
	fre();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0];
		for (int j = 1; j <= a[i][0]; j++) {
			cin >> a[i][j];
			if (!used[a[i][j]]) val.push_back(a[i][j]);
			used[a[i][j]] = 1;
			if (j != 1) {
				cnt[a[i][j]] ++;
				adj[a[i][j - 1]].push_back(a[i][j]);
			}
		}
	}
	priority_queue < pii, vector < pii >, greater < pii > > heap;
	for (auto x : val) {
		heap.push({cnt[x], x});
	}
	while (heap.size()) {
		auto u = heap.top();
		heap.pop();
		if (u.fi != cnt[u.se]) continue;
		res.push_back(u.se);
		for (auto v : adj[u.se]) {
			if (cnt[v] != 0) {
				cnt[v] --;
				heap.push({cnt[v], v});
			}
		}
	}
	for (auto x : res) cout << x << ' ';
}
