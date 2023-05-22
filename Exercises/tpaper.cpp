#pragma GCC optimize ("O2")
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first 
#define se second
#define pll pair < ll, ll >
#define pii pair < int, int >
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pstri pair < string, int >

using namespace std;

const string NAME = "tpaper";
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

int n;

string a[1003], ans = "";

vector < string > full;

vector < pstri > dau, cuoi;

string getmax(string x, string y) {
    if (x.size() > y.size()) return x;
    if (y.size() > x.size()) return y;
    return (x > y ? x : y);
}

bool cmp2 (string x, string y) {
    return (x + y > y + x);
}

bool cmp1(pstri x, pstri y) {
     if (x.fi == y.fi) return false;
    if (getmax(x.fi, y.fi) == x.fi) return true;
    return false;
}

void sol() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        string temp = "";
        for (auto c : a[i]) {
            if (c == '#') temp = "";
            else temp = temp + c;
            ans = getmax(ans, temp);
        }
        temp = "";
        for (auto c : a[i]) {
            if (c == '#') break;
            temp += c;
        }
        if (temp == a[i]) {
            full.push_back(a[i]);
            continue;
        }
        if (temp != "")  dau.push_back({temp, i});
        temp = "";
        for (int j = a[i].size() - 1; j >= 0; j--) {
            if (a[i][j] == '#') break;
            else temp += a[i][j];
        }
        reverse(temp.begin(), temp.end());
        cuoi.push_back({temp, i});
    }
    sort(full.begin(), full.end(), cmp2);
    sort(dau.begin(), dau.end(), cmp1);
    sort(cuoi.begin(), cuoi.end(), cmp1);
    string s;
    cuoi.push_back({"", 0}), cuoi.push_back({"", 0});
    dau.push_back({"", INF}), dau.push_back({"", INF});
    for (auto x : full) s += x;
    if (dau[0].se != cuoi[0].se) ans = getmax(ans, cuoi[0].fi + s + dau[0].fi);
    else ans = getmax(ans, getmax(cuoi[0].fi + s + dau[1].fi, cuoi[1].fi + s + dau[0].fi));
    cout << ans;

}

int main() {
    fast;
    fre();
    int t = 1;
    //cin >> t;
    while (t --) sol();
}
