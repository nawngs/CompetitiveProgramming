#include <bits/stdc++.h>

#define name ""
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
const int NMAX = 2e5;
const ll MOD = 1e9 + 7;
const ll BASE = 2309;

int n, a[100003];

set < int > pq;

int main() {
    fast;
    if(fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }
    //int t; cin >> t; while (t --) sol();
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    pq.insert(a[1]);
    for (int i = 2; i <= n; i++) {
        auto r = pq.lower_bound(a[i]);
        auto l = r; l --;
        auto lmfao = r; lmfao ++;
        cout << *l << " " << *r << " " << *lmfao << '\n';
        cout << min(abs(a[i] - *r), abs(a[i] - *l)) << ' ';
        pq.insert(a[i]);
    }
}
