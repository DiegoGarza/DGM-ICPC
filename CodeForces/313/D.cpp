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
    ll min, max;
    ll i1, i2;
    F(i, 0, 3){
        cin>>i1>>i2;
    }
    max = Max(i1, i2);
    min = Min(i1, i2);

    if(max != min){
        ll total = 0;
        while (min != 0){
            total += (min + (min-1))*3 + (max + (max -1 ))*3;
            max--;
            min--;
        }
        ll diff = max - min;
        ll mod = (ll) pow(4.0, (double) (diff-1));
        cout<<total + mod<<endl;
        return 0;
    }
    else {
        ll size = max;
        ll total = 0;
        for(ll i = 1; i<=size; i++){
            total += ((size + (size -1 ))*6);
        }
        cout<<total<<endl;
    }
    //END

    return 0;
}
