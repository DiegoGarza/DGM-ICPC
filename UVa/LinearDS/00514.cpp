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
    int size, n = 0;
    while(scanf("%d", &size), size != 0){
        n++;
        vi result(size);
        while(scanf("%d", &result[0]), result[0] != 0){
            F(i, size-1){
                scanf("%d", &result[i+1]);
            }
            int i = 0, j = 0;
            stack<int> s;
            bool found = true;
            while(j < result.size() && i <= size){
                if(!s.empty() && result[j] == s.top()){
                    s.pop();
                    j++;
                }
                else {
                    i++;
                    s.push(i);
                }
            }
            if(j >= result.size()) printf("Yes\n");
            else printf("No\n");
        }
        printf("\n");
    }
    //END

    // fclose(in);
    // fclose(out);
    return 0;
}
