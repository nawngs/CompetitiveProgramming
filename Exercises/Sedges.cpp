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

const string NAME = "Sedges";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E17;
const ll nmax = 300000;
const ll MOD = 1e9 + 7;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

int n, d[nmax + 3];

ll dp[nmax + 3][2];

vector < pii > adj[nmax + 3];

void dfs(int u = 1, int e = 0) {
	vector < pll > temp;
	ll total = 0;
	for (auto x : adj[u]) {
		ll v = x.fi, c = x.se;
		if (v == e) continue;
		if (d[v] > 0 && d[u] > 0) dp[v][1] = c;
		dfs(v, u);
		temp.push_back({dp[v][1], dp[v][0]});
		total += dp[v][0];
	}
	sort(temp.begin(), temp.end(), [&](pll &x, pll &y) {
		return (x.fi - x.se) > (y.fi - y.se);
	});
	ll r = -1, s = 0;
	while (r < (ll) temp.size() - 1 && temp[r + 1].fi > temp[r + 1].se && r + 1 < d[u]) {
		r++;
		s += temp[r].fi;
		total -= temp[r].se;
	}
	dp[u][0] = max(dp[u][0], s + total);
	if (r < (ll) temp.size() - 1) 
		for (int i = 0; i <= r; i++) 
			dp[u][0] = max(dp[u][0], s + total - temp[i].fi + temp[i].se + max(0ll, temp[r + 1].fi) - temp[r + 1].se);  
	d[u] --;
	while (r != -1 && r >= d[u]) {
		s -= temp[r].fi;
		total += temp[r].se;
		r --;
	}
	ll val = dp[u][1];
	dp[u][1] = max(dp[u][1], val + total + s);
	if (r < temp.size() - 1) 
		for (int i = 0; i <= r; i++) 
			dp[u][1] = max(dp[u][1], s + total - temp[i].fi + temp[i].se + max(0ll, temp[r + 1].fi) - temp[r + 1].se + val); 
}

int main() {
	fast;
	fre();
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> d[i];
	for (int i = 1; i < n; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back({v, c});
		adj[v].push_back({u, c});
	}
	for (int i = 1; i <= n; i++) {
		d[i] = min(d[i], (int) adj[i].size());
		dp[i][0] = 0;
		dp[i][1] = -LINF;
	}
	dfs();
	cout << dp[1][0] << '\n';
}
