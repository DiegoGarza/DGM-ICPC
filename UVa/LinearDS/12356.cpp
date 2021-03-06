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

#define F(i, a) for( int i = (0); i < (a); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fe(i, x) for(typeof (x.begin()) i = x.begin(); i != x.end (); i++)
#define Set(a, s) memset(a, s, sizeof (a))
#define Max(a, b)  (a < b ? b : a)
#define Min(a, b)  (a > b ? b : a)

using namespace std;

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
    int size, reports;
    while(scanf("%d%d", &size, &reports), (size||reports)){
        vi left(size+1);
        vi right(size+1);
        F(i, left.size()){
            left[i] = i - 1;
        }
        F(i, right.size()){
            right[i] = i + 1;
        }
        int l, r;
        while(reports--){
            scanf("%d%d", &l, &r);
            if(left[l] == 0) printf("* ");
            else printf("%d ", left[l]);
            if(right[r] == size + 1) printf("*\n");
            else printf("%d\n", right[r]);

            left[right[r]] = left[l];
            right[left[l]] = right[r];
        }
        printf("-\n");
    }


    //END

    // fclose(in);
    // fclose(out);
    return 0;
}
