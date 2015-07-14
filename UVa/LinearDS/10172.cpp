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

bool checkEmpty(stack<int>& cargo, vector<queue<int> >& stations){
    if(!cargo.empty()) return false;
    for(int i=0; i<stations.size(); i++){
        if(!stations[i].empty()) return false;
    }
    return true;
}

int main(){
    // FILE *in, *out;
    // in = fopen("input.txt", "r");
    // out = fopen("output.txt", "w+");

    //STARTS
    int cases;
    scanf("%d", &cases);
    while(cases--){
        int n, cCap, sCap;
        scanf("%d%d%d", &n, &cCap, &sCap);
        vector<queue<int> > stations(n);
        F(i, n){
            int quantity;
            scanf("%d", &quantity);
            while(quantity--){
                int in;
                scanf("%d", &in);
                stations[i].push(in);
            }
        }
        stack<int > cargo;
        int totalTime = 0;
        int current = 0;
        while(!checkEmpty(cargo, stations)){
            while ((!cargo.empty() && stations[current].size() < sCap) || (!cargo.empty() && cargo.top() == current + 1)){
                if(cargo.top() != current + 1)
                    stations[current].push(cargo.top());
                cargo.pop();
                totalTime++;
            }
            while (!stations[current].empty() && cargo.size() < cCap){
                cargo.push(stations[current].front());
                stations[current].pop();
                totalTime++;
            }
            if(!checkEmpty(cargo, stations)) totalTime += 2;
            current = (current + 1) % stations.size();
        }
        cout<<totalTime<<endl;
    }
    //END

    // fclose(in);
    // fclose(out);
    return 0;
}
