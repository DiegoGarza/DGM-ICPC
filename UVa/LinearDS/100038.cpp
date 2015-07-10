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
    int n;
    while(scanf("%d", &n) == 1){
        vi ans(n-1);
        int prev;
        scanf("%d", &prev);
        for(int i=1; i<n; i++){
            int aux;
            scanf("%d", &aux);
            int diff = abs(prev - aux);
            if(diff<=n-1 && diff >= 1){
                ans[diff-1] = 1;
            }
            prev = aux;
        }
        bool notJolly = false;
        F(i, ans.size()){
            if(ans[i] == 0){
                notJolly = true;
                break;
            }
        }
        if(notJolly){
            printf("Not jolly\n");
        }
        else{
            printf("Jolly\n");
        }
    }
    //END

    // fclose(in);
    // fclose(out);
    return 0;
}
