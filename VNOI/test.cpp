#include <bits/stdc++.h>

using namespace std;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int rand(int l, int r) {
    return l + rd() % (r - l + 1);
}

int randomfunc(int j) {
    return rd() % j;
}

int a[1003];

int main() {
    srand(time(NULL));
    for (int i = 1; i <= 100; i++) {
        ofstream inp("noel.inp");
        int n = rand(2, 10), d = rand(1, min(5, n));
        inp << n << " " << d << '\n';
        n *= 2;
        for (int i = 1; i <= n; i++)
            a[i] = i;
        random_shuffle(a + 1, a + n + 1, randomfunc);
        for (int i = 1; i <= n; i++) inp << a[i] << ' ';
        inp << '\n';
        inp.close();
        system("voi21_noel.exe");
        system("voi21_noel_trau.exe");
        if (system("fc noel.out noel.ans") != 0) {
            cout << "NGU" << '\n';
            return 0;
        }
        else cout << "OK" << '\n';
    }
    return 0;
}
