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
    int cases;
    scanf("%d", &cases);
    while(cases--){
        bitset<1025> bs;
        bs.set();
        int size, wo, in, total = 0;
        scanf("%d%d", &size, &wo);
        while(wo--){
            scanf("%d", &in);
            bs[in] = 0;
        }
        while(size) {
            for(int i = 1; i<=(int) pow(2.0, (double) size); i+=2){
                total += (bs[i] ^ bs[i+1]);
                bs[(i+1)/2] = bs[i] | bs[i+1];
            }
            size--;
        }
        printf("%d\n", total);
    }
    //END

    return 0;
}
