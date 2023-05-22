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
	const ll INF = 1e9 + 7;
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

	string s[33];

	vector < int > adj[33];

	bitset < 30 > valid[33], used;

	mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

	long long get(long long l, long long r) {
	    return l + (rd() % (r - l + 1));
	}

	int calc() {	
		for (int i = 1; i <= n; i++) {
			 valid[i] = 0;
			 valid[i] = ~valid[i];
		}
		used = 0;
		while(1) {
			int val = INF, choice = -1;
			for (int i = 1; i <= n; i++) {
				if (valid[i].count() == 0) continue;
				if (val > (int) valid[i].count()) {
					val = (int) valid[i].count();
					choice = i;
				}
			}
			if (choice == -1) break;
			int pos;
			for (int i = 0; i < 30; i++) {
				if (valid[choice][i]) {
					pos = i;
					break;
				}
			}
			//cout << choice << " " << pos << '\n';
			valid[choice] = 0;
			for (auto x : adj[choice]) valid[x][pos] = 0;
			used[pos] = 1;
		}
		return used.count();
	}

	int main() {
		fast;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> s[i];
			for (int j = 1; j < i; j++) {
				if (s[i].size() != s[j].size()) {
					adj[i].push_back(j);
					adj[j].push_back(i);
					continue;
				}
				for (int k = 0; k < s[i].size(); k++) {
					if (s[i][k] != s[j][k] && s[i][k] != '*' && s[j][k] != '*') {
						adj[i].push_back(j);
						adj[j].push_back(i);
						//cout << i << " " << j << '\n';
						break ;
					}
				}
			}
		}
		cout << calc();
	}
