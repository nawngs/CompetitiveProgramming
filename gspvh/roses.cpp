#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (y < x) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/

bool swapRowAndColumn;
struct Area {
    int top, bot, left, right;
    Area(int _top = 0, int _bot = 0, int _left = 0, int _right = 0) {
        top = _top; bot = _bot; left = _left; right = _right;
    }

    int perimeter(void) const {
        return 2 * (bot - top + 1) + 2 * (right - left + 1);
    }

    bool operator < (const Area &a) const {
        return perimeter() < a.perimeter();
    }

    void print(void) {
        if (swapRowAndColumn) {
            swap(top, left);
            swap(bot, right);
        }
        printf("%d %d %d %d\n", top, left, bot, right);
    }
};

#define MAX   360360
const int INF = (int)1e8 + 7;
const Area INF_AREA(0, INF, 0, INF);

int numRow, numCol, numFlower;
vector<int> sum[MAX], tmp[MAX];
char input[MAX];
Area bestLeft[MAX], bestRight[MAX], bestTop[MAX], bestBot[MAX];

void init(void) {
    scanf("%d%d%d", &numRow, &numCol, &numFlower);
    tmp[0].assign(numCol + 1, 0);
    FOR(i, 1, numRow) {
        scanf("%s", input + 1);
        tmp[i].assign(numCol + 1, 0);
        FOR(j, 1, numCol) tmp[i][j] = tmp[i][j - 1] + tmp[i - 1][j] - tmp[i - 1][j - 1] + (input[j] == '#');
    }

    if (numRow > numCol) {
        swapRowAndColumn = true;
        swap(numRow, numCol);
    }
    FOR(i, 0, numRow) sum[i].assign(numCol + 1, 0);
    FOR(i, 0, numRow) FOR(j, 0, numCol) sum[i][j] = swapRowAndColumn ? tmp[j][i] : tmp[i][j];
}

int getNumFlower(int top, int bot, int left, int right) {
    if (top > bot || left > right) return 0;
    return sum[bot][right] - sum[top - 1][right] - sum[bot][left - 1] + sum[top - 1][left - 1];
}

void process(void) {
    FOR(i, 1, numRow) {
        bestTop[i] = INF_AREA;
        bestBot[i] = INF_AREA;
    }
    FOR(i, 1, numCol) {
        bestLeft[i] = INF_AREA;
        bestRight[i] = INF_AREA;
    }

    FOR(top, 1, numRow) FOR(bot, top, numRow) {
        int right = 0;
        FOR(left, 1, numCol) {
            while (right <= numCol && getNumFlower(top, bot, left, right) < numFlower) right++;
            if (right > numCol) break;
            if (getNumFlower(top, bot, left, right) == numFlower) {
                Area area(top, bot, left, right);
                minimize(bestTop[bot], area);
                minimize(bestBot[top], area);
                minimize(bestLeft[right], area);
                minimize(bestRight[left], area);
            }
        }
    }

    FOR(i, 2, numRow) minimize(bestTop[i], bestTop[i - 1]);
    FORD(i, numRow - 1, 1) minimize(bestBot[i], bestBot[i + 1]);
    FOR(i, 2, numCol) minimize(bestLeft[i], bestLeft[i - 1]);
    FORD(i, numCol - 1, 1) minimize(bestRight[i], bestRight[i + 1]);

    pair<Area, Area> best(INF_AREA, INF_AREA);
    FOR(i, 1, numRow - 1) {
        pair<Area, Area> tmp(bestTop[i], bestBot[i + 1]);
        if (tmp.fi.perimeter() + tmp.se.perimeter() < best.fi.perimeter() + best.se.perimeter()) best = tmp;
    }
    FOR(i, 1, numCol - 1) {
        pair<Area, Area> tmp(bestLeft[i], bestRight[i + 1]);
        if (tmp.fi.perimeter() + tmp.se.perimeter() < best.fi.perimeter() + best.se.perimeter()) best = tmp;
    }

    int result = best.fi.perimeter() + best.se.perimeter();
    if (result >= INF) {
        printf("-1\n");
        return;
    }

    printf("%d\n", result);
    best.fi.print();
    best.se.print();
}

int main(void) {
#ifdef ONLINE_JUDGE
    freopen("roses.inp", "r", stdin);
    freopen("roses.out", "w", stdout);
#endif // ONLINE_JUDGE
    init();
    process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/
