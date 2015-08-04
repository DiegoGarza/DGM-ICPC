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
    vi bs(10000100, 0);
    int bound = (int) sqrt(10000100.0);
    for(int i=2; i<10000100; i++){
        if(bs[i] == 0) {
            bs[i] = 1;
            for (int k = i + i; k < 10000100; k += i)
                bs[k]++;
        }
    }

    // F(i, 2, 30) cout<<bs[i]<<endl;

    int cases;
    scanf("%d", &cases);
    F(l, 0, cases){
        int a, b, k;
        scanf("%d%d%d", &a, &b, &k);
        int total = 0;
        for(int i=a; i<=b; i++){
            if(bs[i] == k) total++;
        }
        printf("Case #%d: %d\n", l+1, total);
    }

    //END

    return 0;
}
