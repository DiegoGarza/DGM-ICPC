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

int a[105], b[205];

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    //STARTS
    int tests;
    scanf("%d", &tests);
    while(tests--){
        int n, m;
        scanf("%d%d", &n, &m);
        F(i,0,n){
            scanf("%d", &a[i]);
        }
        F(i,0,m){
            scanf("%d", &b[i]);
        }
        sort(a, a+n);
        sort(b, b+m);
        int i, j = 0;
        int cc = b[0];
        bool can = true;
        for(i = 0; i<n && j<m && can; i++){
            int c = 0;
            while(i<n-1 && a[i] == a[i+1]){
                i++;
                j++;
                if(cc != b[j]) can = false;
                c++;
            }
            if(c!=0)
                i--;
            while(cc == b[j] && j < m) {
                j++;
            }
            if(j < m)
                cc = b[j];
        }
        if(can && i == n) printf("YES\n");
        else printf("NO\n");
    }
    //END

    return 0;
}
