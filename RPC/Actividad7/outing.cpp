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

int size;

void dfs(vvi graph, vi &visited, int curr){
    visited[curr] = 1;
    size++;
    F(i, 0, graph[curr].size()){
        if(!visited[graph[curr][i]]){
            dfs(graph, visited, graph[curr][i]);
        }
    }
}

bool comp (const pii& a, const pii& b){
    return a.first > b.first;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    //STARTS
    int n, k, in;
    int max = 0;
    vi def(1001, 0);
    vvi graph(1001);
    scanf("%d%d", &n, &k);
    F(i, 0, n){
        scanf("%d", &in);
        graph[i+1].push_back(in);
    }
    vii ans;
    F(i, 1, n+1){
        size = 0;
        vi visited(1001, 0);
        dfs(graph, visited, i);
        ans.push_back(make_pair(size,i));
    }
    sort(ans.begin(), ans.end(), comp);
    F(i, 0, ans.size()){
        if(max+ans[i].first <= k && !def[ans[i].second]) {
            max+=ans[i].first;
            dfs(graph, def, ans[i].second);
        }
    }
    printf("%d\n", max);
    //END

    return 0;
}
