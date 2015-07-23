#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#include <iterator>
#include <limits>
#include <fstream>

#define F(i, b, a) for( int i = (b); i < (a); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fe(i, x) for(typeof (x.begin()) i = x.begin(); i != x.end (); i++)
#define Set(a, s) memset(a, s, sizeof (a))
#define Max(a, b)  (a < b ? b : a)
#define Min(a, b)  (a > b ? b : a)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    //STARTS
    int xM, yM, x1, y1, x2, y2;
    scanf("%d%d%d%d%d%d", &xM, &yM, &x1, &y1, &x2, &y2);
    int maxY = max(y1, y2);
    if (xM >= x1 + x2 && yM >= maxY) {
        printf("YES\n");
        return 0;
    }
    int maxX = max(x1, x2);
    if (xM >= maxX && yM >= y1 + y2) {
        printf("YES\n");
        return 0;
    }
    int aux1, aux2;
    aux1 = x1;
    x1 = y1;
    y1 = aux1;
    maxY = max(y1, y2);
    if (xM >= x1 + x2 && yM >= maxY) {
        printf("YES\n");
        return 0;
    }
    maxX = max(x1, x2);
    if (xM >= maxX && yM >= y1 + y2) {
        printf("YES\n");
        return 0;
    }
    aux2 = x2;
    x2 = y2;
    y2 = aux2;
    maxY = max(y1, y2);
    if (xM >= x1 + x2 && yM >= maxY) {
        printf("YES\n");
        return 0;
    }
    maxX = max(x1, x2);
    if (xM >= maxX && yM >= y1 + y2) {
        printf("YES\n");
        return 0;
    }
    aux1 = x1;
    x1 = y1;
    y1 = aux1;
    maxY = max(y1, y2);
    if (xM >= x1 + x2 && yM >= maxY) {
        printf("YES\n");
        return 0;
    }
    maxX = max(x1, x2);
    if (xM >= maxX && yM >= y1 + y2) {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
    //END
}
