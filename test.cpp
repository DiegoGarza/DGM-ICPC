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

using namespace std;

#define F(i, b, a) for( int i = (b); i < (a); i++ )
#define Set(a, s) memset(a, s, sizeof (a))
#define INF (int)2e9

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;

int HOB(int n){
    int bits = 0;
    while(n){
        bits++;
        n>>=1;
    }
    return bits;
}

int reverse(int x) {
    int n = 0, prev = 0;
    int mod = (x > 0) ? 1 : -1;
    if(mod == -1) x &= ~(1 << 32);
    cout<<x<<endl;
    while(x){
        n *= 10;
        n += x % 10;
        if(HOB(n) + 5 >= 32) return 0;
        x /= 10;
    }
    n *= mod;
    return n;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    //STARTS
    cout<<reverse(-2147483648)<<endl;
    //END

    return 0;
}
