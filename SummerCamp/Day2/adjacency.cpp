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
	freopen("adjacency.in", "r", stdin);
	freopen("adjacency.out", "w+", stdout);

	//STARTS
	vvi mat(100, vi(100,0));
	int n, m;
	scanf("%d%d", &n, &m);
	F(i,0,m){
		int a, b;
		scanf("%d%d", &a, &b);
		mat[a-1][b-1] = 1;
		mat[b-1][a-1] = 1;
	}
	F(i,0,n){
		F(j,0,n){
			if(j) printf(" ");
			printf("%d", mat[i][j]);
		}
		printf("\n");
	}
	
	//END

	return 0;
}

