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

#define int ll
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
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, a[100003], x[100003], y[100003], f[100003], cnt[100003], sze[100003], res = 0, ans[100003];

vector < int > adj[100003];

stack < int > pos[100003];

void dfs(int u = 1, int e = 0) {
	cnt[a[u]] ++;
	pos[a[u]].push(u);
	sze[u] = 1;
	for (auto v : adj[u]) {
		if (v == e) continue;
		dfs(v, u);
		y[v] = f[u];
		f[u] = 0;
		sze[u] += sze[v];
	}
	if (cnt[a[u]] == 1) x[a[u]] += sze[u];
	pos[a[u]].pop();
	if (pos[a[u]].size()) f[pos[a[u]].top()] += sze[u];
	cnt[a[u]] --;
}

void dfs2(int u = 1, int e = 0) {
	ans[u] = res;
	for (auto v : adj[u]) {
		if (v == e) continue;
		if (a[v] == a[u]) dfs2(v, u);
		else {
			int tamv = x[a[v]], tamu = x[a[u]];
			x[a[v]] = n;
			x[a[u]] -= (sze[v] - y[v]);
			res = res - tamv - tamu + x[a[v]] + x[a[u]];
			dfs2(v, u);
			res = res - x[a[v]] - x[a[u]] + tamv + tamu;
			x[a[v]] = tamv;
			x[a[u]] = tamu;
		}	
	}
}

signed main() {
	fast;
	//fre();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	for (int i = 1; i <= n; i++) res += x[i];
	dfs2();
	for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
}
