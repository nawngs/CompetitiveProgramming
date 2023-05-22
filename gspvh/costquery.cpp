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
	
struct Edge {
	int u, v, c;
};

Edge a[100003];

int n, q, cnt[100003], par[100003];

ll s[100003];

vector < int > temp;

int root(int v) {		
    return par[v] == v ? v : (par[v] = root(par[v]));
}

void merge(int x, int y) {
    if ((x = root(x)) == (y = root(y)))  return ;
   
    if (cnt[x] < cnt[y]) {
        swap(x, y);
    }
   	cnt[x] += cnt[y];
    par[y] = x;
}

void sol() {
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		cin >> a[i].u >> a[i].v >> a[i].c;
		temp.push_back(a[i].c);
	}
	sort(a + 1, a + n, [](Edge &x, Edge &y) {
		return x.c < y.c;
	});
	sort(temp.begin(), temp.end());
	for (int i = 1; i <= n; i++) {
		cnt[i] = 1;
		par[i] = i;
	}
	s[0] = 0;
	for (int i = 1; i < n; i++) {
		int x = root(a[i].u);
		int y = root(a[i].v);
		s[i] = s[i - 1] + 1ll * (1ll * cnt[x] * 1ll * cnt[y]);
		merge(x, y);
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << s[(upper_bound(temp.begin(), temp.end(), r) - temp.begin())] - s[(lower_bound(temp.begin(), temp.end(), l) - temp.begin())] << " ";
	}
}

int main() {
	fast;
    //fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
