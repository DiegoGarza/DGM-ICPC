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

int array [100005];

struct Num{
    int count;
    int left;
    int right;
    Num(int a, int b, int c) {
        count = a;
        left = b;
        right = c;
    }
    Num() { count = 0; left = 0; right = 0; }
};

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    //STARTS
    int size;
    map<int, Num> m;
    scanf("%d", &size);
    int max = -1;
    F(i, 0, size) {
        scanf("%d", &array[i]);
        if (m.find(array[i]) == m.end()) {
            m[array[i]] = Num(1, i, i);
        } else {
            m[array[i]].count++;
            m[array[i]].right = i;
        }
        if(m[array[i]].count > max) max = m[array[i]].count;
    }
    int l = 0, r = size - 1;
    int minLR = numeric_limits<int>::max(), minL, minR;
    for(map<int, Num>::iterator it = m.begin(); it!=m.end(); it++){
        if (it->second.count == max) {
            if (it->second.right-it->second.left < minLR) {
                minLR = it->second.right-it->second.left;
                minL = it->second.left;
                minR = it->second.right;
            }
        }
    }
    printf("%d %d\n", ++minL, ++minR);
    //END

    return 0;
}
