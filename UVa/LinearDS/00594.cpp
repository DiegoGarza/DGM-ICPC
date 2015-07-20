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

bool isPowerOfTwo(int n) {
    if (n<1) return false;
    n &= (n - 1);
    return n == 0;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    //STARTS
    int n;
    while(scanf("%d", &n) == 1){
        int m = 0;
        for(int i=0, j=24; i<32; i++, j++){
            if((n & (1<<i)) != 0) {
                m+=(1<<j);
            }
            if ((j + 1) % 8 == 0) j-=16;
        }
        printf("%d converts to %d\n", n, m);
    }
    //END

    return 0;
}
