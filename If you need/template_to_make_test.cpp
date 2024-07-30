#include <bits/stdc++.h>
using namespace std;
#define inp cout
using ll = long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll get(ll x, ll y) {
    return x + rng() % (y - x + 1);
}

void gen() {
	// code sinh test
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    for (int i = 1; i <= 50; i++) { // so test
        string cur_name = "sex" + to_string(i) + ".inp"; // ten bai trong dau ""
        ofstream cout(cur_name);
		gen();
		cout << 123 << '\n';
		// ghi test ra
    }
}
