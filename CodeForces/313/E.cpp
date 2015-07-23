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

int arr [100][100];

void fillThat(int i, int j, int h, int w){
    F(k,0,h){
        F(l, 0, w){
            cout<<arr[k][l]<<" ";
        }
        cout<<endl;
    }
    int val = 0;
    if(i < h - 1 && arr[i+1][j] != -1) val++;
    if(j < w - 1 && arr[i][j+1] != -1) val++;
    if(i > 0 && j == 0) val += arr[i-1][j];
    else if(j > 0 && i == 0) val += arr[i][j-1];
    else if (i > 0 && j > 0){
        int max = Max(arr[i-1][j], arr[i][j-1]);
        val += max;
    }
    arr[i][j] = val;
    if(i < h - 1 && arr[i+1][j] != -1) fillThat(i+1, j, h, w);
    if(j < w - 1 && arr[i][j+1] != -1) fillThat(i, j+1, h, w);
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);

    //STARTS
    int h, w, n;
    memset (arr, 0, sizeof(arr));
    scanf("%d%d%d", &h, &w, &n);
    while (n--){
        int x, y;
        scanf("%d%d", &x, &y);
        arr[x-1][y-1] = -1;
    }
    cout<<"check"<<endl;
    fillThat(0, 0, h, w);
    printf("%d\n", arr[h-1][w-1]);
    //END

    return 0;
}
