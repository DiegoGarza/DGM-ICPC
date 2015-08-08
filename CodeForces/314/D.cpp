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

bitset<100005> bs;
int size, ships, SS, shot;

bool fits(){
    int auxShips = ships, auxSS = SS;
    F(i, 0, size){
        auxSS = SS;
        if(i-1>=0 && !bs[i-1]) auxSS++;
        while(i<size && bs[i] == 0 && auxSS != 0){
            auxSS--;
            if(auxSS) i++;
        }
        if(auxSS == 0) auxShips--;
    }
    return auxShips <= 0;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    //STARTS
    scanf("%d%d%d%d", &size, &ships, &SS, &shot);
    vi shots(shot);
    F(i, 0, shot){
        scanf("%d", &shots[i]);
    }
    int i=0;
    for(i=0; i<shot; i++){
        bs[shots[i]-1] = 1;
        if(!fits()) break;
    }
    if(i==shot) printf("-1\n");
    else printf("%d\n", i+1);
    //END

    return 0;
}
