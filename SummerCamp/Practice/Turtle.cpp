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
	 freopen("turtle.in", "r", stdin);
	 freopen("turtle.out", "w+", stdout);

	//STARTS
	int n, m;
	scanf("%d%d", &n, &m);
	vvi a(n,vi(m));
	F(i,0,n){
		F(j,0,m){
			scanf("%d", &a[i][j]);
		}
	}
	vvi f(n,vi(m));
	F(i,0,n){
		F(j,0,m){
			if(!i && !j){
				f[i][j] = a[i][j];
			}
			else if(!i){
				f[i][j]= f[i][j-1] + a[i][j];
			}
			else if(!j){
				f[i][j] = f[i-1][j] + a[i][j];
			}
			else {
				f[i][j] = max(f[i-1][j], f[i][j-1]) + a[i][j];
			}
		}
	}
	printf("%d\n", f[n-1][m-1]);
	//END

	return 0;
}

