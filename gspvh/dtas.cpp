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

const string NAME = "dtas";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

struct Data {
	string Name;
	ll points, correct;
} students[600003];

ll n, q, cnt[600003];

vector < ll > wrong[600003]; 

int main() {
	fast;
	//fre();
	cin >> n >> q;
	ll s = 0;
	for (int i = 1; i <= q; i++) {
		cnt[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		string name = "", a;
		cin >> a; name += a;
		while (cin >> a && 'a' <= a[0] && a[0] <= 'z') 
			name += ' ' + a;
		int c = stoi(a);
		students[i].correct = q - c;
		while (c--) {
			int x; cin >> x;
			wrong[i].push_back(x);
			cnt[x] ++;
			s ++;
		}
		students[i].Name = name;
	}
	for (int i = 1; i <= n; i++) {
		ll temp = s;
		for (auto x : wrong[i]) temp -= cnt[x];
		students[i].points = temp;
	}
	sort(students + 1, students + n + 1, [&](Data &x, Data &y) {
		return (x.points > y.points) || (x.points == y.points && x.correct > y.correct) || (x.points == y.points && x.correct == y.correct && x.Name < y.Name);
	});
	for (int i = 1; i <= n; i++) 
		cout << students[i].Name << " " << students[i].points << '\n';
}
