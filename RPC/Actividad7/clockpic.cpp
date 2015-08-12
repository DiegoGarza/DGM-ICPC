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

int leftclock [200000];
int rightclock [200000];

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    //STARTS
    int n;
    scanf("%d", &n);
    F(i, 0, n){
        scanf("%d", &leftclock[i]);
    }
    F(i, 0, n){
        scanf("%d", &rightclock[i]);
    }
    sort(leftclock, leftclock+n);
    sort(rightclock, rightclock+n);
    F(i, 0, n){

    }
    F(i, 1, n){
        if((int) abs((double) leftclock[i] - (double) leftclock [i-1]) !=
        (int) abs((double) rightclock[i] - (double) rightclock [i-1])){
            printf("impossible\n");
            return 0;
        }
    }
    printf("possible\n");
    //END

    return 0;
}
