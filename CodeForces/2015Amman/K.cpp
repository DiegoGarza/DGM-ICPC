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

int a[1000005];

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    //STARTS
    int tests;
    scanf("%d", &tests);
    while(tests--){
        int n, k;
        scanf("%d%d", &n, &k);
        F(i,0,n){
            scanf("%d", &a[i]);
        }
        sort(a, a+n);
        int i, j;
        bool found = false;
        int iF, jF;
        for(i=0; i<n && !found; i++){
            for( j=i+1; j<n && !found; j++){
                if(a[i] * a[j] == k) {
                    found = true;
                    iF = i;
                    jF = j;
                }
                if(a[i] * a[j] > k) break;
            }
            if(a[i] > k) break;
        }
        if(found)
            printf("%d %d\n", a[iF], a[jF]);
        else
            printf("-1\n");
    }
    //END

    return 0;
}
