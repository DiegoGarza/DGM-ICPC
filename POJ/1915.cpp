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

int cases, size, xS, yS, xE, yE, steps, i, j, auxi, auxj, minPath;
typedef pair<int, pair<pair<int, int>, int> > P;
priority_queue< P, vector<P>, greater<P> > pq;

int getDist(int i, int j){
    return abs(i - yE) + abs(j - xE);
}

void a_star(vvi& visited) {
    int movesX [] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int movesY [] = {1, 2, 2, 1, -1, -2, -2, -1};
    double dist = getDist(xS, yS);
    visited[xS][yS] = 1;
    pq.push(make_pair(dist, make_pair(make_pair(xS, yS), 1)));
    while(!pq.empty()){
        i = pq.top().second.first.first;
        j = pq.top().second.first.second;
        steps = pq.top().second.second;
        visited[i][j] = steps;
        dist = pq.top().first;
        cout<<i<<" "<<j<<" "<<dist<<" "<<steps<<endl;
        pq.pop();
        if(!dist){
            if(minPath > steps) minPath = steps;
        }
        steps++;
        if(steps < minPath){
            F(k, 0, 8){
                auxi = i+movesY[k];
                auxj = j+movesX[k];
                if(auxi >= 0 && auxi < size && auxj >= 0 && auxj < size &&
                    (!visited[auxi][auxj] || visited[auxi][auxj] < steps)) {
                    dist = getDist(auxi, auxj);
                    pq.push(make_pair(dist, make_pair(make_pair(auxi, auxj), steps)));
                }
            }
        }
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    //STARTS
    scanf("%d", &cases);
    while(cases--){
        minPath = 1000000;
        while(!pq.empty()) pq.pop();
        scanf("%d", &size);
        vvi visited(size, vi(size, 0));
        scanf("%d%d%d%d", &xS, &yS, &xE, &yE);
        a_star(visited);
        printf("%d\n", minPath);
    }
    //END

    return 0;
}
