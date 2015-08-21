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

pair<int, int> v[3402];
vvi knap(2, vector<int>(12881, 0));

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    //STARTS
    int N, W;
    scanf("%d%d", &N, &W);
    F(i, 0, N){
        int a, b;
        scanf("%d%d", &a, &b);
        v[i] = make_pair(a, b);
    }
    for(int i=1; i<=N; i++){
        for(int j=0; j<=W; j++){
            if(v[i-1].first <= j){
                knap[i%2][j] = max(knap[(i-1)%2][j], knap[(i-1)%2][j-v[i-1].first] + v[i-1].second);
            }
            else knap[i%2][j] = knap[(i-1)%2][j];
        }
    }
    printf("%d\n", knap[N%2][W]);
    //END

    return 0;
}
