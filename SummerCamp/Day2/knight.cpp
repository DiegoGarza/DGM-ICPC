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

int n, m, total;

int dfs(vvi& board, int i, int j){	
	if(i < 0 || j  < 0){
		return 0;
	}
	if(i == 0 && j == 0){
		return 1;
	}
	if(board[i][j] != -1){
		return board[i][j];
	}
	int tot = dfs(board, i-1, j-2) + dfs(board, i-2, j-1);
	board[i][j] = tot;
	return board[i][j];
}

int main(){
	 freopen("knight.in", "r", stdin);
	 freopen("knight.out", "w+", stdout);

	//STARTS
	total = 0;
	scanf("%d%d", &n, &m);
	vvi board(n, vi(m,-1));
	board[0][0] = 1;
	printf("%d\n", dfs(board, n-1, m-1));
	//END

	return 0;
}

