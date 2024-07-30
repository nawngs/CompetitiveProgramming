#include <bits/stdc++.h>

using namespace std;

const string NAME = "PALIN"; // ten bai

const int NTEST = 100; // so test kiem tra

mt19937 rd(time(0));

long long Rand(long long l, long long r) { // sinh so ngau nhien tu l -> r
    return l + rd() % (r - l + 1);
}

int main() {
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++) {
        ofstream inp((NAME + ".inp").c_str());
        // code de sinh test
        int n = Rand(1, 100);
        inp << n << '\n';
        for (int i = 0; i < n; i++) {
        	char c = Rand(0, 25) + 'a';
        	inp << c;
        }
        inp << '\n';
        inp.close();
        system((NAME + ".exe").c_str()); // chay code dung
        system((NAME + "_trau.exe").c_str()); // chay code trau

        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0) // so sanh ket qua o 2 file .out va .ans
        	return 0;
    }
    cout << "OK" << '\n';
    return 0;
}

