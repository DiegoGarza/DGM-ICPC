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

int main(){
    // FILE *in, *out;
    // in = fopen("input.txt", "r");
    // out = fopen("output.txt", "w+");

    //STARTS
    int frosh;
    while(scanf("%d", &frosh), frosh!=0){
        map<string, int> m;
        int max = 0;
        while(frosh--){
            vi v(5);
            F(i, 5){
                scanf("%d", &v[i]);
            }
            sort(v.begin(), v.end());
            string s = "";
            F(i, 5){
                ostringstream ss;
                ss << v[i];
                s += ss.str();
            }
            (m.find(s) == m.end()) ?
                m[s] = 1 : m[s]++;
            if(m[s] > max) max = m[s];
        }
        int total = 0;
        for (map<string, int>::iterator it = m.begin(); it != m.end(); it++){
            if(it->second == max) total += max;
        }
        printf("%d\n", total);
    }
    //END

    // fclose(in);
    // fclose(out);
    return 0;
}
