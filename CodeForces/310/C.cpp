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
    int size, chains;
    scanf("%d%d", &size, &chains);
    vvi mat (chains);
    F(i,0,chains){
        int chainsize;
        scanf("%d", &chainsize);
        vi aux (chainsize);
        F(i, 0, chainsize){
            scanf("%d", &aux[i]);
        }
        mat[i] = aux;
    }
    int i = 0;
    while(mat[i][0] != 1) {
        i++;
    }
    int conn = 0, curr = 2;
    int j = 1;
    while(j < mat[i].size() && curr == mat[i][j]){
        conn++;
        curr++;
        j++;
    }
    int total = (mat[i].size()-1-conn);
    for(int k=0; k<mat.size(); k++){
        if(k!=i){
            total += mat[k].size()-1;
        }
    }
    total+=(size-1-conn);
    printf("%d\n", total);
    //END

    return 0;
}
