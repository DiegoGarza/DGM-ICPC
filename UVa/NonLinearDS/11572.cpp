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
    int cases;
    scanf("%d", &cases);
    while(cases--){
        int size, in;
        scanf("%d", &size);
        map<int, int > m;
        int i = 0, previ = 0;
        int max = 0;
        int total = 0;
        while(size--){
            scanf("%d", &in);
            if(m.find(in) == m.end() || (m.find(in) != m.end() && previ > m[in])){
                m[in] = i;
                total++;
            }
            else{
                total -= m[in] - previ;
                previ = m[in] + 1;
                m[in] = i;
            }
            if(total > max){
                max = total;
            }
            i++;
        }
        printf("%d\n", max);
    }
    //END

    // fclose(in);
    // fclose(out);
    return 0;
}
