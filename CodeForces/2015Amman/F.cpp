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
#include <functional>

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

int a [10005];

bool comp (const int& a, const int& b){
    return a > b;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    //STARTS
    int tests;
    scanf("%d", &tests);
    while(tests--){
        int studs;
        scanf("%d", &studs);
        int aux;
        for(int i=0; i<studs; i++){
            scanf("%d", &aux);
            a[i] = aux;
        }
        sort(a, a + studs, greater<int>());
        int diff = 100 - a[0];
        int i = 0;
        while (a[i] + diff >= 50 && i < studs) {
            i++;
        }
        printf("%d\n", i);
    }
    //END

    return 0;
}
