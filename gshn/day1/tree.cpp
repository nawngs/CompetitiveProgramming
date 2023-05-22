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

int n, a[100003];

vector < int > temp;

vector < pii > res;

priority_queue < pii, vector < pii >, greater < pii > > heap; 


int main() {
	fast;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		heap.push({a[i], i});
	}
	while (1) {
		while (heap.size() && heap.top().fi == 1) {
			temp.push_back(heap.top().se);
			heap.pop();
		}
		while (temp.size()) {
			while (heap.size()) {
				auto u = heap.top();
				heap.pop();
				res.push_back({temp.back(), u.se});
				temp.pop_back();
				u.fi --;
				if (u.fi == 1) temp.push_back(u.se);
				else heap.push(u);
			}
			if (!heap.size()) break;
		}
		if (!heap.size() && temp.size()) {
			res.push_back({temp[0], temp[1]});
			break;
		}
	}
	for (auto x : res) cout << x.fi << " " << x.se << '\n';
}
