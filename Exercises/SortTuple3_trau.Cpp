#include <bits/stdc++.h>

using namespace std;

struct Data {
	int sum, x, y, z;
	Data(int _sum, int _x, int _y, int _z) : sum(_sum), x(_x), y(_y), z(_z) {};
};

int n, k;

vector < Data > f;

int main() {
	freopen("sorttuple3.inp", "r", stdin);
	freopen("trau.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int p = 1; p <= n; p++) {
				f.push_back({i + j + p, i, j, p});
			}
		}
	}
	sort(f.begin(), f.end(), [](Data &x, Data &y) {
		return (x.sum < y.sum) || (x.sum == y.sum && x.x < y.x) || (x.sum == y.sum && x.x == y.x && x.y < y.y) || (x.sum == y.sum && x.x == y.x && x.y == y.y && x.z < y.z);
	});
	cout << f[k - 1].x << " " << f[k - 1].y << " " << f[k - 1].z;
}