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

int arr[50005];
int ans[50005];

int main(){
    //freopen("inverse.in", "r", stdin);
    //freopen("inverse.out", "w+", stdout);

    //STARTS
    int n;
    scanf("%d", &n);
    F(i, 0, n){
        scanf("%d", &arr[i]);
    }
    memset(ans, 0, sizeof(ans));
    int total = 0;
    for(int i=0; i<n; i++){
        for(int j=i-1; j>=0; j--){
            if(arr[i] < arr[j]) {
                ans[i] = ans[j] + 1;
            }
            break;
        }
    }
    printf("  ");
    F(i,0,n){
        printf("%d ", ans[i]);
        total += ans[i];
    }
    printf("%d\n", total);
    //END

    return 0;
}
