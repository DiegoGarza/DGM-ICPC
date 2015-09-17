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

set<pair<int, pair<int, int> > > s;

void dfs(vvi& graph, int start, int i, vi path, int level){
	path.push_back(i);
	if(level < 2){
		F(j, 0, graph[i].size()){
			dfs(graph, start, graph[i][j], path, level+1);
		}
	}
	if(level == 2){
		F(j, 0, graph[i].size()){
			if(graph[i][j] == start){
				sort(path.begin(), path.end());
				if(s.find(make_pair(path[0], make_pair(path[1], path[2]))) == s.end()){
					s.insert(make_pair(path[0], make_pair(path[1], path[2])));
				}
			}
		}
	}
}

int main(){
	 freopen("triangles.in", "r", stdin);
	 freopen("triangles.out", "w+", stdout);

	//STARTS
	int n, m;
	scanf("%d%d", &n, &m);
	vvi graph(n, vi());
	F(i,0,m){
		int a,b;
		scanf("%d%d", &a, &b);
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
	F(i,0,n){
		dfs(graph, i, i, vi(), 0);
	}
	printf("%d\n", (int) s.size());
	//END

	return 0;
}

