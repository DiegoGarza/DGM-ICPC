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
#include <fstream>
#include <limits>

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

int array[1000];

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    //STARTS
    int size, in;
    int cases = 1;
    while(scanf("%d", &size), size){
        printf("Case %d:\n", cases);
        F(i, 0, size){
            scanf("%d", &in);
            array[i] = in;
        }
        int queries;
        scanf("%d", &queries);
        while(queries--){
            int diff = numeric_limits<int>::max();
            scanf("%d", &in);
            int ans = 0;
            F(i, 0, size){
                F(j, i+1, size){
                    int auxans = array[i] + array[j];
                    int diffaux = (int) abs((double) array[i] + (double) array[j] - (double) in);
                    if(diffaux < diff){
                        ans = auxans;
                        diff = diffaux;
                    }
                }
            }
            printf("Closest sum to %d is %d.\n", in, ans);
        }
        cases++;
    }
    //END

    return 0;
}
