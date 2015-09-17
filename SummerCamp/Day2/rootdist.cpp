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



int dsu [100];

int getDist(int x){
	return (dsu[x] == x) ? 0 : 1 + getDist(dsu[x]);
}

int main(){
	freopen("rootdist.in", "r", stdin);
 	freopen("rootdist.out", "w+", stdout);

	//STARTS
	int n;
	cin>>n;
	F(i,1,n){
		int in;
		scanf("%d", &in);
		dsu[i] = in - 1;
	}
	int max = 0;
	F(i,0,n){
		if(max < getDist(i)) max = getDist(i);
	}
	vi ans;
	F(i,0,n){
		if(max == getDist(i)) ans.push_back(i);
	}
	sort(ans.begin(), ans.end());
	printf("%d\n%d\n", max, (int) ans.size());
	F(i,0,ans.size()){
		if(i) printf(" ");
		printf("%d", ans[i]+1);
	}
	printf("\n");
	return 0;
}
