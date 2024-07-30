#include <bits/stdc++.h>

using namespace std;

const int N = 2000;

#define ll long long

int n, m, a[N + 1][N + 1], dp[N + 1][N + 1];

struct Elements {
    ll cnt, v, h, maxH;
    Elements(ll _cnt = 0, ll _v = 0, ll _h = 0, ll _maxH = 0) {
        cnt = _cnt, v = _v, h = _h, maxH = _maxH;
    }
};

ll res = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        stack<Elements> s;
        s.push({0, -1, 0, 0});
        for (int j = 0; j < m; j++) {
            dp[i][j] = 1;
            if (i > 0 && a[i][j] == a[i - 1][j]) dp[i][j] += dp[i - 1][j];
            int sum = 1;
            while (s.top().v == a[i][j] && s.top().h >= dp[i][j]) {
                sum += s.top().cnt;
                s.pop();
            }
            ll maxArea = sum * dp[i][j];
            if (s.top().v == a[i][j]) maxArea += s.top().maxH;
            res += maxArea;
            s.push({sum, a[i][j], dp[i][j], maxArea});
        }
    }
    cout << res;
    return 0;
}
