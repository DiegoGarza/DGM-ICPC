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

int t1, t2;

void merge(vi& arr, int start, int mid, int end){
    int size = (end - start) + 1;
    vi aux(size);
    int i = start, j = mid + 1, k = 0;

    while(i <= mid && j <= end) {
        if (arr[i] > arr[j]) {
            t1 += mid - i + 1;
        }
        if(arr[i] < arr[j]){
            arr[i+j] = arr[i];
            i++;
        }
        else {
            arr[i+j] = arr[j];
            j++;
        }
    }

    while(i <= mid) aux[k++] = arr[i++];
    while(j <= end) aux[k++] = arr[j++];

    for(k=0; k < size; k++) {
        arr[start+k] = aux[k];
    }
}

void mergeSort(vi& arr, int i, int j){
    if(j - i < 1){
        return;
    }
    int mid = (i+j) / 2;
    mergeSort(arr, i, mid);
    mergeSort(arr, mid+1, j);
    merge(arr, i, mid, j);
}

int main(){
     freopen("john.in", "r", stdin);
     freopen("john.out", "w+", stdout);

    //STARTS
    int n;
    scanf("%d", &n);
    vii r(n);
    F(i,0,n){
        int a, b;
        scanf("%d%d", &a, &b);
        r[i] = make_pair(a,b);
    }
    sort(r.begin(), r.end());
    t1=0;
    vi vec(n);
    F(i,0,n){
        vec[i] = r[i].second;
    }
    mergeSort(vec, 0, vec.size()-1);
    printf("%d\n", t1);
    //END

    return 0;
}
