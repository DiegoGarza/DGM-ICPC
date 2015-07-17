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
    int k, first = 0;
    while(scanf("%d", &k), k){
        if(first != 0){
            printf("\n");
        }
        first++;
        vi v(k);
        F(i, 0, k){
            scanf("%d", &v[i]);
        }
        sort(v.begin(), v.end());
        F(a, 0, k-5){
            F(b, a+1, k-4){
                F(c, b+1, k-3){
                    F(d, c+1, k-2){
                        F(e, d+1, k-1){
                            F(f, e+1, k){
                                printf("%d %d %d %d %d %d\n", v[a], v[b], v[c], v[d], v[e], v[f]);
                            }
                        }
                    }
                }
            }
        }
    }
    //END

    return 0;
}
