/*



█▄─▄█_█▀█_█▄──█_█▀_█─█_█▀_█▀_▀█▀_█▀_█▀█
█─▀─█_█▄█_█─█─█_█─_█▀█_█▀_▀█_─█─_█▀_█▄▀
█───█_█─█_█──▀█_█▄_█─█_█▄_▄█_─█─_█▄_█─█
ㅤ
────────────▐▌────▐▌
───────────▄██▄──▄██▄ ㅤ ㅤ ▲ ㅤ ㅤ ▲ ㅤ ㅤ ▲
────▄────▀████████████▀ ◄██► ◄██► ◄██►
───▄██▄█──███▀████▀███───██───██───██
█─▄█████──███▄─██─▄███───██───██───██
▀███████───██████████────████████████
─██▀▀████──██████████────████████████
▀▀──▄████▄──██▄──▄██──────────██
───▀▀████▀──█████████▄────────██
──────██──▄███████████▀───────██
──────██──██████████▀──▄▄████████▄
──────██──██████████▄▄████████████
──────██──▀█████████████▀────▀███▀
──────██───▀████████████▄▄▄▄█████▄
──────██────██████████████████████
──────███▄─▄██████████▀────▀▀▀███▀
──────███████████████─────────██
──────███████████████─▄██─────██
──────██████████████████▀─────██
──────▀█████████████████▄██▄──██
───────▀████████─▀█████████▀──██
──────────▀█████▄──▀███████───██
───────────██████▄───▀█████▄──██
──────────▄███████▄────▀████──██
──────────████████▀──────▀▀▀──██
──────────▀█████▀
────────────████
────────────████▄
───────────▄█████
───────────█████▀
ㅤ
ㅤㅤㅤ█──█─█▄──█─▀─▀▀█▀▀─█▀▀─█▀▀▄
ㅤㅤㅤ█──█─█─█─█─█───█───█▀▀─█──█
ㅤㅤㅤ▀▀▀▀─▀──▀▀─▀───▀───▀▀▀─▀▀▀

Glory glory Man united,
Glory glory Man united,
Glory glory Man united,
As the reds go marching on on on!
Just like the busby babes in days gone by,
We'll keep the red flags flying high,
Your gonna see us all from far and wide,
Your gonna hear the masses sing with pride.
United, Man united,
We're the boys in red and we're on our way to Wembley!
Wembley, Wembley,
We're the famous Man united and we're going to Wembley,
Wembley, Wembley,
We're the famous Man united and we're going to Wembley
In Seventy-Seven it was Docherty
Atkinson will make it Eighty-Three
And everyone will no just who we are,
They'll be singing que sera sera
United, Man united,
We're the boys in red and we're on our way to Wembley!
Wembley, Wembley,
We're the famous Man united and we're going to Wembley,
Wembley, Wembley,
We're the famous Man united and we're going to Wembley
Glory glory Man united,
Glory glory Man united,
Glory glory Man united,
As the reds go marching on on on!
Glory glory Man united,
Glory glory Man united,
Glory glory Man united,
As the reds go marching on on on!
Glory glory Man united,
Glory glory Man united,
Glory glory Man united,
As the reds go marching on on on!

*/

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

const string NAME = "EraseSeqR";
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

int n, a[200003], it[800003];

void build_tree(int node, int l, int r) {
	it[node] = 0;
	if (l == r) return ;
	int mid = (l + r) / 2;
	build_tree(node * 2, l, mid);
	build_tree(node * 2 + 1, mid + 1, r);
}

void update(int node, int l, int r, int pos, int val) {
	if (pos < l || pos > r) return ;
	it[node] = max(it[node], val);
	if (l == r) return ;
	update(node * 2, l, (l + r) / 2, pos, val);
	update(node * 2 + 1, (l + r) / 2 + 1, r, pos, val);
}

int query(int node, int l, int r, int u, int v) {
	if (v < l || r < u) return 0;
	if (u <= l && r <= v) return it[node];
	int mid = (l + r) / 2;
	return max(query(node * 2, l, mid, u, v), query(node * 2 + 1, mid + 1, r, u, v));
}

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build_tree(1, 1, n);
	stack < int > st;
	for (int i = 1; i <= n; i++) {
		int val;
		while (st.size() && a[st.top()] < a[i]) st.pop();
		if (!st.size()) val = 0;
		else val = query(1, 1, n, st.top() + 1, i) + 1;
		update(1, 1, n, i, val);
		st.push(i);
	}
	cout << it[1] + 1 << '\n';
}

int main() {
	fast;
	fre();
	int t = 1;
	cin >> t;
	while (t --) sol();
}
