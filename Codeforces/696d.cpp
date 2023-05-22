#include <bits/stdc++.h>

#define name ""
#define test "test"
#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair

using namespace std;

const ld EPS = 1e-9;
const int INF = 1e9 + 7;
const ll LINF = 1E18;
const int NMAX = 2e2;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

struct Matrix {
	int NumRow, NumCol;
	vector < vector < ll > > val;
	Matrix (int _NumRow, int _NumCol) {
		NumRow = _NumRow; NumCol = _NumCol;
		val.resize(NumRow + 3);
		for (auto &x : val) {
			x.resize(NumCol + 3, -LINF);
		}
	}
	Matrix operator * (const Matrix &oth) const {
		Matrix res(NumRow, oth.NumCol);
		for (int i = 0; i <= NumRow; i++)
			for (int j = 0; j <= oth.NumCol; j++) 
				for (int k = 0; k <= NumCol; k++) {
					res.val[i][j] = max(res.val[i][j], val[i][k] + oth.val[k][j]);
				}
		return res;
	}
};

Matrix pow(Matrix a, ll b) {
	if (b == 1) return a;
	Matrix x = pow(a, b / 2); x = x * x;
	if (b % 2 == 1) x = x * a;
	return x;
}

int nxt[NMAX + 3][26], jump[NMAX + 3][26], f[NMAX + 3], node = 0;

ll sum[NMAX + 3], a[NMAX + 3];

ll n, l, val;

string s;

void add() {
	int cur = 0;
	for (auto c : s) {
		if (!nxt[cur][c - 'a']) nxt[cur][c - 'a'] = ++ node;
		cur = nxt[cur][c - 'a'];
	}
	sum[cur] += val;
}

void bfs() {
	queue < int > Q; Q.push(0);
	while (!Q.empty()) {
		int i = Q.front(); Q.pop();
		sum[i] += sum[f[i]];
		for (int j = 0; j < 26; j++) if (nxt[i][j]) {
			int x = nxt[i][j];
			f[x] = jump[f[i]][j];
			jump[i][j] = x;
			Q.push(x);
		}
		else jump[i][j] = jump[f[i]][j];
	}
}

void print(Matrix a) {
	for (int i = 0; i <= a.NumRow; i++) {
		for (int j = 0; j <= a.NumCol; j++) cout << a.val[i][j] << ' ';
		cout << '\n';
	}
}

int main() {
	fast;
	if(fopen(name".inp", "r")) {
		freopen(name".inp", "r", stdin);
		freopen(name".out", "w", stdout);
	}
	//int t; cin >> t; while (t --) sol();
	cin >> n >> l;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> s; val = a[i];
		add();
	}
	bfs();
	Matrix g(node, node);
	for (int i = 0; i <= node; i++) for (int j = 0; j <= node; j++) g.val[i][j] = -LINF;
	for (int i = 0; i <= node; i++)
		for (int j = 0; j < 26; j++) {
			g.val[i][jump[i][j]] = max(g.val[i][jump[i][j]], sum[jump[i][j]]);
		}
	g = pow(g, l);
	// cout << "g :" << '\n'; print(g);
	// Matrix val = g; val = val * g;
	// cout << "g ^2 :" << '\n'; print(val);
	// val = val * g;
	// cout << "g ^3 :" << '\n'; print(val);
	Matrix tam(1, node);
	for (int i = 1; i <= node; i++) tam.val[1][i] = -LINF;
	tam.val[1][0] = 0;
	tam = tam * g;
	ll ans = 0;
	for (int i = 0; i <= node; i++) ans = max(ans, tam.val[1][i]);
	cout << ans;
}