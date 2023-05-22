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

const string NAME = "brentford40mu";
const string NAME2 = "TEST";
const ld ESP = 1e-9;
const ll INF = 1e9 + 7;
const ll LINF = 1E18;
const ll nmax = 2e5;
const ll MOD = 1e9 + 19972207;
const ll base = 2309;

void fre() {
	string finp = NAME + ".inp";
	string fout = NAME + ".out";
	freopen(finp.c_str(), "r", stdin);
	freopen(fout.c_str(), "w", stdout);
}

string a, b;

ll dp[1000003][4];

// 0 la = 
// 1 la a > b
// 2 b > a
// 3 a >< b

int main() {
	fast;
	fre();
	cin >> a >> b;
	int n = a.size();
	a = ' ' + a;
	b = ' ' + b;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int dga = 0; dga <= 9; dga++) {
			if (a[i] != '?' && a[i] - '0' != dga) continue;
			for (int dgb = 0; dgb <= 9; dgb++) {
				if (b[i] != '?' && b[i] - '0' != dgb) continue;
				if (dga == dgb) {
					dp[i][0] = (dp[i][0] + dp[i - 1][0]) % MOD;
					dp[i][1] = (dp[i][1] + dp[i - 1][1]) % MOD;
					dp[i][2] = (dp[i][2] + dp[i - 1][2]) % MOD;
					dp[i][3] = (dp[i][3] + dp[i - 1][3]) % MOD;
				}
				if (dga > dgb) {
					dp[i][1] = (dp[i][1] + dp[i - 1][1] + dp[i - 1][0]) % MOD;
					dp[i][3] = (dp[i][3] + dp[i - 1][3] + dp[i - 1][2]) % MOD;
				}
				if (dgb > dga) {
					dp[i][2] = (dp[i][2] + dp[i - 1][2] + dp[i - 1][0]) % MOD;
					dp[i][3] = (dp[i][3] + dp[i - 1][3] + dp[i - 1][1]) % MOD;
				}
			}
		}
	}
	cout << dp[n][3];
}
