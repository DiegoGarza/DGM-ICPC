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
#include <string.h>
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

int arr [105];

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    //STARTS
    int n, m, in, maxs = 0, winner;
    scanf("%d%d", &n, &m);
    memset(arr, 0, sizeof(arr));
    F(i, 0, m){
        maxs = -1;
        F(j, 0, n){
            scanf("%d", &in);
            if(in > maxs){
                maxs = in;
                winner = j;
            }
        }
        arr[winner]++;
    }
    maxs = 0;
    F(i, 0, n){
        if(maxs < arr[i]) {
            maxs = arr[i];
            winner = i;
        }
    }
    printf("%d\n", winner+1);
    //END

    return 0;
}
