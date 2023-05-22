#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
string s;

ll dem = 0;

ll mu(ll a, ll b) {
    if (b == -1) return 0;
    if (b == 0) return 1;
    ll x = mu(a, b / 2);
    x = x * x;
    if (b % 2 == 1) x = x * a;
    return x;
}
 
void sol(int index) {
    cin >> s;
    bool th = false, th2 = false;
    ll val = 0, val2 = 0, val3 = 0, dem1 = 0, dem2 = 0;
    for (int i = 0; i < s.size(); i++) {    
        if (s[i] == '.') th = true;
        if (s[i] == '(') th2 = true;
        if (!th) {
             if ('0' <= s[i] && s[i] <= '9') val3 = val3 * 10 + s[i] - '0';
        }
        if (th) {
            if ('0' <= s[i] && s[i] <= '9') {
                if (!th2) {
                    val2 = val2 * 10 + (s[i] - '0');
                    dem2 ++;
                }
                dem1 ++;
                val = val * 10 + (s[i] - '0');
            }
        }
    }
    if (!th2) {
        val2 = 0; 
        dem2 = -1;
    }
   ll res1 = val - val2;
   ll res2 = mu(10, dem1) - mu(10, dem2);
   ll gcdres = __gcd(res1, res2);
   res1 /= gcdres;
   res2 /= gcdres;
    cout << "Case #" << index << ": " << res1 + val3 * res2 << "/" << res2 << '\n';
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("Fraction.Inp", "r", stdin);
    freopen("Fraction.Out", "w", stdout);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) sol(i);
}