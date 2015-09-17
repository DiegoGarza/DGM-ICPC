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
	 freopen("zero.in", "r", stdin);
	 freopen("zero.out", "w+", stdout);

	//STARTS
	ll zero[10005];
	int size;
	scanf("%d", &size);
	for(int i=size-1; i>=0; i--){
		scanf("%lld", &zero[i]);
	}
	F(i,0,size){
		if(i) printf(" ");
		printf("%lld", zero[i]);
	}

	printf("\n");
	//END

	return 0;
}

