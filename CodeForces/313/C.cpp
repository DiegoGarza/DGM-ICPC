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
    string a,b;
    cin>>a>>b;
    if(a.length() % 2 == 1 && a == b) {
        printf("YES\n");
        return 0;
    }
    if(a.length() != b.length()) {
        printf("NO\n");
        return 0;
    }
    string a1, a2, b1, b2;
    a1 = a.substr(0, a.length()/2);
    a2 = a.substr(a.length()/2, a.length());
    b1 = b.substr(0, b.length()/2);
    b2 = b.substr(b.length()/2, b.length());
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());
    sort(b1.begin(), b1.end());
    sort(b2.begin(), b2.end());
    if((a1 == b1 && a2 == b2) || (a1 == b2 && a2 == b1)) {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
    //END

    return 0;
}
