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
#include <string.h>
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

int m[26];
int levels [500001];

void bfsAll(vector<vector<int> > graph){
    int current, hops;
    queue<pair<int, int> > q;
    q.push(make_pair(1, 1));
    while(!q.empty()){
        current = q.front().first;
        hops = q.front().second;
        for(int i=0; i<graph[current].size(); i++){
            q.push(make_pair(graph[current][i], hops+1));
        }
        levels[current] = hops;
        q.pop();
    }
}

string s;

void bfs(vector<vector<int> > graph, int from, int level){
    int current, hops;
    queue<pair<int, int> > q;
    q.push(make_pair(from, levels[from]));
    while(!q.empty()){
        current = q.front().first;
        hops = q.front().second;
        if(hops == level) {
            m[s[current-1] - 'a']++;
        }
        for(int i=0; i<graph[current].size(); i++){
            if(hops <= level) {
                q.push(make_pair(graph[current][i], hops+1));
            }
        }
        q.pop();
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    //STARTS
    int n, q, in, from, level;
    cin>>n>>q;
    vector<vector<int > > tree(n+1);
    vector<vector<int > > ancestors(n+1);
    F(i, 2, n+1){
        cin>>in;
        tree[in].push_back(i);
    }
    bfsAll(tree);
    cin>>s;
    F(i, 0, q){
        cin>>from>>level;
        vector<int> chars;
        memset(m, 0, sizeof(m));
        bfs(tree, from, level);
        int count = 0;
        F(i, 0, 26){
            if(m[i]%2 != 0) count++;
        }
        if(count <= 1) printf("Yes\n");
        else printf("No\n");
    }
    //END

    return 0;
}
