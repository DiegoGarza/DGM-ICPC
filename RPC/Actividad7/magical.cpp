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

int arr [1000000];

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    //STARTS
    int n, cases;
    scanf("%d", cases);
    while(cases--){
        scanf("%d", &n);
        F(i,0,n){
            scanf("%d", &arr[i]);
        }
        int curr_max = 0;
        int maxf = numeric_limits<int>::min();
        for(int n : nums){
            curr_max = max(curr_max + n, n);
            maxf = max(maxf, curr_max);
        }
    }
    //END

    return 0;
}
