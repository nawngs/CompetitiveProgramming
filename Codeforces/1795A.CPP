#include <bits/stdc++.h>

using namespace std;

int n, m;

string s1, s2;

void solve() {
    cin >> n >> m >> s1 >> s2; s1 = ' ' + s1, s2 = ' ' + s2;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 2; i <= n; i++)
        if (s1[i] == s1[i - 1]) cnt1 ++;
    for (int i = 2; i <= m; i++)
        if (s2[i] == s2[i - 1]) cnt2 ++;
    if (cnt1 + cnt2 >= 2) {
        cout << "NO" << '\n';
        return ;
    }
    if (cnt1 + cnt2 == 0) {
        cout << "YES" << '\n';
        return ;
    }
    if (s1.back() == s2.back()) {
        cout << "NO" << '\n';
        return ;
    }
    cout << "YES" << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t; cin >> t; while (t--) solve();
}
