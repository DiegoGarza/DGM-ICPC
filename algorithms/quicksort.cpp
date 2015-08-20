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

void partition(vi& ar, int l, int r) {
    if(l<r) {
        int auxPivot = l - 1, pivot = r;
        for(int i = l; i <= r; i++){
            if(ar[i] <= ar[pivot]){
                int aux = ar[i];
                ar[i] = ar[auxPivot + 1];
                ar[auxPivot + 1] = aux;
                auxPivot++;
            }
        }
        partition(ar, l, auxPivot-1);
        partition(ar, auxPivot+1, r);
    }
}

void quickSort(vi &arr) {
    partition(arr, 0, arr.size() - 1);
}

int main() {
    int size;
    scanf("%d", &size);
    vector<int> ar(size);
    F(i, 0, ar.size()) scanf("%d", &ar[i]);
    quickSort(ar);
    F(i, 0, ar.size()) printf("%d ", ar[i]);
    printf("\n");
    return 0;
}
