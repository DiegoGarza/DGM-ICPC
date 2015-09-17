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

int dsu [100000];

void initializeDSU(int size){
	F(i,0,size){
		dsu[i] = i;
	}
}

int get(int x){
	if(x == dsu[x]) return x;
	dsu[x] = get(dsu[x]);
	return dsu[x];
}

int main(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w+", stdout);

	//STARTS
	int n, m;
	cin>>n>>m;
	vvi graph(n, vi(m));
	string s;
	F(i,0,n){
		cin>>s;
		F(j,0,s.length()){
			graph[i][j] = s[j];
		}
	}
	initializeDSU(n*m);
	F(i1,0,n){
		F(j1,0,m){
			F(i2,0,n){
				F(j2,0,m){
					if(i1 == i2 && j1 == j2){
						continue;
					}
					if(graph[i1][j1] == graph[i2][j2] && abs(i1 -i2) + abs(j1 - j2) == 1){
						int v = i1 * m + j1;
						int u = i2 * m + j2;
						if(v < u){
							if(get(v) == get(u)) {
								cout<<"Yes"<<endl;
								return 0;
							}
							dsu[get(v)] = get(u);
						}
					}
				}
			}
		}
	}
	cout<<"No"<<endl;
	//END

	return 0;
}

