#include <bits/stdc++.h>
 
#define name ""
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZE(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define lnode node * 2, l, (l + r) / 2
#define rnode node * 2 + 1, (l + r) / 2 + 1, r
 
using namespace std;
 
const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int m, n;

map < int, multiset < int > > adj;

map < int, vector < char > > val[100003];

vector < int > a[100003];

bool vs[100003];

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> n;
		a[i].resize(n);
		for (int j = 0; j < n; j++) {
			int z; cin >> z; z += m; 
			a[i][j] = z;
			adj[i].insert(z); adj[z].insert(i);
		}
	}
	for (auto x : adj) {
		if (SZE(x.se) % 2 == 1) {
			cout << "NO" << '\n';
			return 0;
		}
	}
	stack < int > st;
	vector < int > res;
	while (1) {
		int dau = -1;
		for (int i = 0;  i < m; i++)
			if (SZE(adj[i])) {
				dau = i;
				break;
			}
		if (dau == -1) break;
	    st.push(dau);
	    while ((int)st.size()) {
	        int u = st.top();
	        if (adj[u].empty()) {
	            res.pb(u);
	            st.pop();
	        }
	        else {
	            for (auto v : adj[u]) {
	                st.push(v);
	                adj[u].erase(adj[u].find(v));
	                adj[v].erase(adj[v].find(u));
	                break;
	            }
	        }
	    }
	}
    for (int i = 0; i < SZE(res) - 1; i++) {
    	if (res[i] < m) 
    		val[res[i]][res[i + 1]].pb('R');
    	else 
    		val[res[i + 1]][res[i]].pb('L');
    }
    cout << "YES" << '\n';
    for (int i = 0; i < m; i++) {
    	for (auto z : a[i]) {
    		cout << val[i][z].back();
    		val[i][z].pop_back();
    	}
    	cout << '\n';
    }
}