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

int fs[1000], rs[1000];

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    //STARTS
    int f, r;
    while(scanf("%d", &f), f){
        scanf("%d", &r);
        vector<double> ratios;
        F(i, 0, f){
            scanf("%d", &fs[i]);
        }
        F(i, 0, r){
            scanf("%d", &rs[i]);
        }
        F(i, 0, f){
            F(j, 0, r){
                ratios.push_back((double) rs[j]/ (double) fs[i]);
            }
        }
        sort(ratios.begin(), ratios.end());
        double max = -1;
        F(i, 1, ratios.size()){
            if(max < ratios[i]/ratios[i-1]) max = ratios[i]/ratios[i-1];
        }
        max = round(100.0*max) / 100.0;
        printf("%0.2lf\n", max);
    }
    //END

    return 0;
}
