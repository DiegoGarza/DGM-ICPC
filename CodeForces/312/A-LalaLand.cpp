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

#define F(i, b, a) for( int i = (b); i < (a); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fe(i, x) for(typeof (x.begin()) i = x.begin(); i != x.end (); i++)
#define Set(a, s) memset(a, s, sizeof (a))
#define Max(a, b)  (a < b ? b : a)
#define Min(a, b)  (a > b ? b : a)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;

bool comp(const pair<int, int>& a, const pair<int, int>& b){
    return a.first < b.first;
}

bool comp1(const pair<int, int>& a, const pair<int, int>& b){
    return a.first > b.first;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    //STARTS
    int trees;
    scanf("%d", &trees);
    vii left, right;
    while(trees--){
        int coord, val;
        scanf("%d%d", &coord, &val);
        (coord < 0) ? left.push_back(make_pair(coord, val)) : right.push_back(make_pair(coord, val));
    }
    sort(left.begin(), left.end(), comp1);
    sort(right.begin(), right.end(), comp);
    int size, total = 0;
    (left.size() < right.size()) ? size = left.size() : size = right.size();
    F(i, 0, size) total += left[i].second + right[i].second;
    if(left.size() != right.size())
        (left.size() < right.size()) ? total += right[size].second : total += left[size].second;
    printf("%d\n", total);
    //END

    return 0;
}
