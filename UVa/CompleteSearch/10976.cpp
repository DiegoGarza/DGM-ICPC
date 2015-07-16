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

#define F(i, a) for( int i = (0); i < (a); i++ )
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

int ans [100000][2];

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    //STARTS
    int in;
    while(scanf("%d", &in) == 1){
        int total = 0;
        int i = in + 1;
        while(i <= in*2){
            int j = in*i % (i - in);
            if(j == 0) {
                ans[total][0] = in*i / (i - in);
                ans[total][1] = i;
                total++;
            }
            i++;
        }
        printf("%d\n", total);
        F(i, total){
            printf("1/%d = 1/%d + 1/%d\n", in, ans[i][0], ans[i][1]);
        }
    }
    //END

    return 0;
}
