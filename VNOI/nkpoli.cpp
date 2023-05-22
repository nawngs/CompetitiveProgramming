#include <bits/stdc++.h>

using namespace std;

struct PT {
    int x, y;
    PT operator -(const PT &oth) {
        PT res;
        res.x = x - oth.x, res.y = y - oth.y;
        return res;
    }
} a[103];

int dot(PT x, PT y) {
    return x.x * y.x + x.y * y.y;
}

int cross(PT x, PT y) {
    return x.x * y.y - y.x * x.y;
}

bool CCW(PT A, PT B, PT C) {
    return cross(B - A, C - A) > 0;
}

bool CW(PT A, PT B, PT C) {
    return cross(B - A, C - A) < 0;
}

int n, dp[103][103];

int calc(int i, int j) {
    if (dp[i][j] != 0) return dp[i][j];
    dp[i][j] = 3;
    for (int k = 1; k <= n; k++) {
        if (k != i && k != j && CW(a[k], a[i], a[j]) && CW(a[0], a[k], a[i]))
            dp[i][j] = max(dp[i][j], calc(k, i) + 1);
    }
    return dp[i][j];

}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    a[0].x = a[0].y = 0;
    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) if (i != j && CW(a[0], a[i], a[j])) res = max(res, calc(i, j));
    cout << res;
}
