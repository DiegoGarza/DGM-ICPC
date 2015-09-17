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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    ifstream in("arrange.in");
    ofstream out("arrange.out");

    //STARTS
    int n;
    int curr = 65, c = 0;
    string s;
    in>>n;
    vector<string> vs(n);
    F(i,0,n){
        in>>vs[i];
    }
    sort(vs.begin(), vs.end());
    F(i,0,n){
        if(vs[i][0] == curr){
            if(curr == 90) {
                c++;
                curr = 65;
            }
            else curr++;
        }
    }
    out<<(curr - 65) + (c*26)<<endl;
    //END

    return 0;
}
