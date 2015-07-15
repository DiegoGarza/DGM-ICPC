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
    int n;
    priority_queue<int, vi, greater<int> > pq;
    while(scanf("%d", &n), n){
        int in;
        while(n--){
            scanf("%d", &in);
            pq.push(in);
        }
        int total = 0, aux;
        while(!pq.empty()){
            aux = 0;
            aux += pq.top();
            pq.pop();
            aux += pq.top();
            pq.pop();
            if(!pq.empty())
                pq.push(aux);
            total += aux;
        }
        printf("%d\n", total);
    }
    //END

    // fclose(in);
    // fclose(out);
    return 0;
}
