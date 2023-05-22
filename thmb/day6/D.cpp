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

struct Node {
	int cnt, height;
	int a[10];
};

vector < Node > trie;

void add_node() {
	Node tam;
	tam.cnt = 0;
	tam.height = 10;
	for (int i = 0; i < 10; i++) tam.a[i] = -1;
	//cout << 123 << '\n';
	trie.push_back(tam);
}

int n, mu[12];

vector < int > digit;

void add() {
	int pre = 0;
	for (auto x : digit) {
		trie[pre].cnt ++;
		if (trie[pre].a[x] == -1) {
			add_node();
			trie.back().height = trie[pre].height - 1;
			trie[pre].a[x] = trie.size() - 1;
		}
		pre = trie[pre].a[x];
	}
	trie[pre].cnt++;
}

int find(int x) {
	int res = 0, pre = 0, th = false;
	while (1) {
		for (int i = 0; i <= 9; i++) {
			if (trie[pre].a[i] == -1) continue;
			if (x == trie[trie[pre].a[i]].cnt && trie[pre].height == 1) {
				res += i;
				th = 1;
				break;
			}
			if (x <= trie[trie[pre].a[i]].cnt) {
				res += i * mu[trie[pre].height - 1];
				pre = trie[pre].a[i];
				break;
			}
			else {
				//cout << i << '\n';
				x -= trie[trie[pre].a[i]].cnt;
			}
		}
		if (th) break;
	}
	return res;
}

int main() {
	fast;
	mu[0] = 1;
	for (int i = 1; i <= 10; i++) mu[i] = mu[i - 1] * 10;
	add_node();
	cin >> n;
	while (n --) {
		int type;
		cin >> type;
		if (type == 1) {
			int x;
			cin >> x;
			digit.clear();
			while (x > 0) {
				digit.push_back(x % 10);
				x /= 10;
			}
			while (digit.size() < 10) digit.push_back(0);
			reverse(digit.begin(), digit.end());
			add();
		}
		else {
			int x;
			cin >> x;
			cout << find(x) << '\n';
		}
	}	
}
