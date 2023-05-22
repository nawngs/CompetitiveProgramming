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

const string NAME = "npath";
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

ll n, a[503][503], frac[1003];

ll mu(ll a, ll b) {
	if (b == 0) return 1;
	ll x = mu(a, b / 2);
	x = (x * x) % MOD;
	if (b % 2 == 1) x = (x * a) % MOD;
	return x;
}

ll C(ll k, ll n) {
	if (k > n) return 0;
	return (frac[n] * mu((frac[k] * frac[n - k]) % MOD, MOD - 2)) % MOD;
}

int main() {
	fast;
	fre();
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	frac[0] = 1;
	for (int i = 1; i <= 2 * n; i++) frac[i] = (frac[i - 1] * i) % MOD;
	ll ans = 0;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++)
			for (int p = i; p <= n; p++)
				for (int q = j; q <= n; q++) 
					if (a[i][j] == a[p][q]) ans = (ans + C(p - i, p - i + q - j)) % MOD;
	cout << ans;
}
