// cach 1 chia can 
/*#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

const string NAME = "paint";
const string NAME2 = "TEST";
const ll ESP = 1e-9;
const ll INF = 1e18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;
const ll BLOCK_SIZE = 1000;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, k = -1;

char lazy[1003][30];

char res[1000003];

void update(int block) {
	int l = block * BLOCK_SIZE;
	int r = min(1ll * k, (block + 1) * BLOCK_SIZE - 1);
	for (int i = l; i <= r; i++) res[i] = lazy[block][res[i] - 'a'];
	for (int j = 0; j < 28; j++) {
		char c = j + 'a';
		lazy[block][j] = c;
	}
}

void sol() {
	cin >> n;
	for (int i = 0; i <= 1001; i++) 
		for (int j = 0; j < 28; j++) {
			char c = j + 'a';
			lazy[i][j] = c;
		}
	for (int i = 1; i <= n; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			char x;
			cin >> x;
			res[++ k] = x;
		}
		else {	
			char x, y;
			cin >> x >> y;
			int rblock = k / BLOCK_SIZE;
			for (int block = 0; block < rblock; block ++) {
				for (int j = 0; j < 28; j++) {
					if (lazy[block][j] == x) lazy[block][j] = y;
				}
			}
			update(rblock);
			for (int j = rblock * BLOCK_SIZE; j <= k; j++) if (res[j] == x) res[j] = y;
		}
	}
	for (int i = 0; i <= k / BLOCK_SIZE; i++) update(i);
	for (int i = 0; i <= k; i++) cout << res[i];
	
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
*/
// cach 2: foward_list

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

const string NAME = "paint";
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

int n;

forward_list < int > pos[30];

void sol() {
	cin >> n;
	int k = -1;
	for (int i = 1; i <= n; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			char x;
			cin >> x;
			pos[x - 'a'].push_front(++ k);
		}
		else {
			char x, y;
			cin >> x >> y;
			if (x == y) continue;
			if (!pos[y - 'a'].empty()) pos[y -'a'].splice_after(pos[y - 'a'].begin(), pos[x - 'a']);
			else pos[y - 'a'] = pos[x - 'a'];
			pos[x - 'a'].clear();
		}
	}
	vector < int > res;
	res.resize(k + 1);
	for (int i = 0; i <= 'z' - 'a'; i++)
		for (auto x : pos[i]) res[x] = i;
	for (auto x : res) {
		char c = x + 'a';
		cout << c;
	}
}

int main() {
	fast;
	fre();
	int t = 1;
	//cin >> t;
	while (t --) sol();
}
