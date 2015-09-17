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

char grid[1001][1001];
int n, m;

void dfs(int i, int j){

}

int main(){
	// freopen("", "r", stdin);
	// freopen("", "w+", stdout);

	//STARTS
	int x1, x2, y2, y1;
	scanf("%d%d%d%d%d%d", &m, &n, &x1, &y1, &x2, &y2);
	F(i, 0, n){
		F(j, 0, m){
			scanf("%c", grid[i][j]);
		}
	}
	map<pair<int, int>, pair<int, int> > parent;
	dfs(x1, y1);


	//END

	return 0;
}
