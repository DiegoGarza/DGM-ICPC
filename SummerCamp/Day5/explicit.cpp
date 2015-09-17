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

int main(){
    freopen("explicit.in", "r", stdin);
    freopen("explicit.out", "w+", stdout);

    //STARTS
    int t=0, in;
    bitset<10> b;
    F(i,0,10){
        scanf("%d", &in);
        b[i] = in;
    }
    F(i,0,10){
        F(j,i+1,10){
            if(b[i] || b[j]){
                t++;
            }
        }
    }
    F(i,0,10){
        F(j,i+1,10){
            F(k, j+1, 10){
                if(b[i] || b[j] || b[k]){
                    t++;
                }
            }
        }
    }
    cout<<t%2<<endl;
    //END

    return 0;
}
