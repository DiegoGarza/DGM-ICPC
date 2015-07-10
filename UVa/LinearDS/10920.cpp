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
    int size, loc;
    while(scanf("%d%d", &size, &loc), (size||loc)){
        int n = 3;
        while(loc > (int) pow(n, 2)){
            n+=2;
        }
        int col = n-1, row = n, start = (int) pow(n-2, 2) + 1;
        if(loc == 1){
            col = 1;
            row = 1;
            n = 1;
        }
        else{
            while(col > 1 && loc != start){
                col--;
                start++;
            }
            while(row > 1 && loc != start){
                row--;
                start++;
            }
            while(col < n && loc != start){
                col++;
                start++;
            }
            while(row < n && loc != start){
                row++;
                start++;
            }
        }
        printf("Line = %d, column = %d.\n", row+(size-n)/2, col+(size-n)/2);
    }
    //END

    // fclose(in);
    // fclose(out);
    return 0;
}
